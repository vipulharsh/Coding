#include <iostream>
#include <stdio.h> 	
using namespace std;


int main(){
 int T;
 
 cin>>T;
 
 
 int N , M;
 
 int A[1000000];
 
 while(T-->0){
	 scanf ("%d %d",&N,&M);
	 for(int i=0;i<N;i++)
	   A[i] = i;
	   
	  int x,y; 
	 for(int j;j<M;j++){
	  scanf ("%d %d",&x,&y);
	  A[x-1]++;
	  A[y-1]--;
	 }   
	
	bool flag = false; 
	for(int i=0;i<N;i++){
		if(A[i]==N-1) {
			printf("2 %d\n",i+1);
			flag =  true;
			break;
		}
	} 
	
	if(!flag) printf("1\n"); 
 }

 return 0;
}
