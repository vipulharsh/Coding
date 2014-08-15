#include <iostream>
#include <stdio.h>
using namespace std;

#define in(x) scanf("%d", &x) 


int main(){
	
	int A[100001];
	int T;
	in(T);
	
	while(T-->0){
		int N;
		in(N);
		for(int i=0;i<N;i++)
			in(A[i]);
			
		int minVal, maxVal;
		bool par;	
		for(int i=0;i<N-1;i++){
			par = i%2;
			minVal = min(A[i], A[i+1]);
			maxVal = max(A[i], A[i+1]);	
			if(!par){
				A[i] = minVal;
				A[i+1] = maxVal;
			}
			else{
				A[i] = maxVal;
				A[i+1] = minVal;
			}
		}
		for(int i=0;i<N;i++)
			printf("%d ", A[i]);
		printf("\n");		
	}	
	return 0;
}
