#include <iostream>
#include <list>
#include <assert.h>
#include <string.h>
using namespace std;
#define INFI 1000000


int S[100001];
int next[100001];
int cost[100001];	
int first[10];
int N;
	

int main(){
	
	string s;
	cin>>s;
	N = s.length();
	for(int i=0;i<N;i++)
		S[i] = s[i] - '0';

	int current[10];
	int done[10];
		
	for(int digit=0;digit<10;digit++)
		done[digit] = (current[digit] = (first[digit] = -1));
		

	for(int i=0;i<N;i++){
		cost[i] = -1;
		if(current[S[i]] != -1){
			next[current[S[i]]] = i;
		}
		else
			first[S[i]] = i;
		current[S[i]] = i;
	}



	
	for(int digit=0;digit<10;digit++){
		if(current[digit]!=-1)
			next[current[digit]] = -1;
	}
	
	list<int> elements;
	cost[0] = 0;
	elements.push_back(0);
	while(!elements.empty()){
		int k = elements.front();
		//cout<<k<<"---"<<endl;
		elements.pop_front();
		
		if(k>0){
//			assert(cost[k-1] <= 1+cost[k]);
			if(cost[k-1] == -1){
				cost[k-1] = 1+cost[k];
				elements.push_back(k-1);
			}	
		}
		
		if(k<N-1){
//			assert(cost[k+1] <= 1+cost[k]);
			if(cost[k+1] == -1){
				cost[k+1] = 1+cost[k];
				elements.push_back(k+1);
			}
		}
		
		if(done[S[k]] == -1){
			int f = first[S[k]];
			while(f != -1){
				if(f != k){ 
					if(cost[f] == -1){
						elements.push_back(f);
						cost[f] = 1+cost[k];
					}
//					else
//						cost[f] = min(cost[f], 1+cost[k]);
				}
				f = next[f];
			}
			done[S[k]] = 1;
		}
	}
	
	cout<<cost[N-1]<<endl;
	
	return 0;
}
