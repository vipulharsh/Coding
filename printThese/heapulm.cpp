#include <iostream> 
#include <string> 
#include <algorithm>
#include <stdio.h> 
#include <vector>

#define NDEBUG

#include <cassert>
#define infi 1000000000
using namespace std;

struct mypair{
	string label;
	int priority;
void print(){
	printf("(%s/%d)" , label.c_str() , priority);
}
};

mypair *Arr;
int N;

bool operator<(const mypair &p1 , const mypair &p2){
		return (p1.label < p2.label);
}
struct st_node{
	 int l,r;
	 int maxval; //max segment tree on priorities
	 int index; //at which the max val is present
};	
	
class segment_tree{
public:
	 st_node *tree;
	 int size;
 segment_tree(){
   tree  = new st_node[500000];
}
 void build_tree(mypair* in , int n){
	size = n;
	 build_tree_helper(in , 0 , n-1 , 0);	
 }
 	 	
 void build_tree_helper(mypair *in , int i, int j , int index){
        // cout<<i<<j<<endl;
	
	//this node accounts for values from i and j(both inclusive)
	  tree[index].l = i;
	  tree[index].r = j;
	
	 if(i==j){
		
		 tree[index].maxval = in[i].priority;
		 tree[index].index = i;
		 return;
	}
	
	
	build_tree_helper(in , i , (i+j-1)/2 , 2*index + 1);
	build_tree_helper(in , (i+j-1)/2 + 1 , j , 2*index + 2);
    tree[index].maxval = max(tree[2*index+1].maxval , tree[2*index+2].maxval);
    tree[index].index  = (tree[2*index+1].maxval > tree[2*index+2].maxval)?(tree[2*index+1].index):(tree[2*index+2].index);
 }
//pair <maxval  , index>
pair<int , int> maxquery(int i , int j , int index){
//  cout<<"Maxquery "<<i<<" : "<<j<<" : "<<index<<endl;
  pair<int,int> ret;
  if(i>j){
    ret.first =  -infi;
    ret.second = -infi;
    return ret;
  }
  if(tree[index].l == i && tree[index].r == j) {
    ret.first = tree[index].maxval;
    ret.second = tree[index].index;
    return ret;
 }
//else
  assert(tree[2*index+2].l == (tree[2*index+1].r + 1));
  pair<int, int> p1 = maxquery(i , min(tree[2*index+1].r,j) , 2 * index + 1);
  pair<int, int> p2 = maxquery(max(tree[2*index+2].l , i) , j , 2 * index + 2);
  ret.first = max(p1.first , p2.first);
  ret.second = (p1.first > p2.first)?p1.second : p2.second;
 return ret;
}
void printTree(int node , int spaces){
	for(int i=0;i<spaces;i++)
	    cout<<" ";
	cout<<"("<<tree[node].maxval<<","<<tree[node].index<<")"<<endl;
	if(tree[node].l != tree[node].r){
		printTree(node*2 + 1, spaces + 2);
		printTree(node*2 + 2, spaces + 2);
	}
}
};
void printHeap(segment_tree &st , int i , int j){
  if(i>j) return;
  pair<int , int> res = st.maxquery(i,j, 0);
 // cout<<endl<<i<<" : "<<j<<" : "<<res.first<<" : "<<res.second<<endl;
  assert((res.second >= i) && (res.second <= j));
  cout<<"(";
  printHeap(st ,  i , res.second-1); //left subtreap
  cout<<Arr[res.second].label<<"/"<<Arr[res.second].priority;  //label/priority
  printHeap(st , res.second + 1 , j); //right subtreap
  cout<<")";
return;
}


int main(){
  Arr = new mypair[100000];
  segment_tree st;
  char tempstring[1010];
  mypair n;
  while(true){
	scanf("%d", &N);
	if(N==0) break;
       for(int i=0;i<N;i++){
		scanf(" %s" , tempstring);
		string temp = tempstring;
		int found = temp.find_first_of('/');
		string templabel = temp.substr(0 ,found);
		string tempPriority = temp.substr(found+1);
	        //printf("%s ::: %s ::: %s \n" , temp.c_str() , templabel.c_str() , tempPriority.c_str());
		//printf("%s %d \n",tempstring , Arr[i].priority);
		Arr[i].label = templabel;
		Arr[i].priority  = atoi(tempPriority.c_str());
	}
	 scanf("\n");
	 sort(Arr , Arr + N);
/*
	 for(int i=0; i<N;i++){
	   Arr[i].print();
	   printf("\n");
	 }
*/
	st.build_tree(Arr , N);
//	st.printTree(0,0);
//	cout<<st.maxquery(0,3,0).first<<st.minquery(0,3,0).second<<endl;
//	assert(false);
	printHeap(st , 0 , N-1);
	cout<<endl;
 }
 return 0;
}
