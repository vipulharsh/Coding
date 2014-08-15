#include <iostream>
#include <stdio.h> 
#include <stdlib.h>
#include <cmath> 
using namespace std;

int N,M,K;
char elms[4] = {'A', 'C', 'G', 'T'};
char A[15][15];
		
		
inline int next(int t, int d){
	return (t+1)%d;
}
		
void fill(int nchar){
	
	int rowStart = 0;
	for(int i=0;i<N;i++){
		rowStart = next(rowStart, nchar);
		int curr = rowStart;
		for(int j=0;j<M;j++){
			A[i][j] = elms[curr];
			curr = next(curr, nchar);
		}
	}
}



int main(){
	int T;
	cin>>T;
	srand (time(NULL));
	while(T-->0){
		cin>>N>>M>>K;
		int fac = sqrt(N*M);
		//int fac = (N*M)/2;
		if(K<=(3*N*M)/2)
			fill(1);
		
		else if(K<=(5*N*M)/2)
			fill(2);
		
		else if(K<=(7*N*M)/2)
			fill(3);
		
		else if(K<=((3*fac*N*M)/2))
			fill(4);
		
		/*
		else if(K<=((9*fac*N*M)/2)){
			fill(1);
			if(M>N){
				for(int i=0;i<N;i++)
					A[i][M/2] = elms[3];
			}
			else{
				for(int i=0;i<M;i++)
					A[N/2][i] = elms[3];
			}
		}
		*/
		
		else{
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					A[i][j] = elms[rand()%4];
				}
			}
		}
		
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				cout<<A[i][j];
			cout<<endl;
		}
		
	}
	return 0;
}
