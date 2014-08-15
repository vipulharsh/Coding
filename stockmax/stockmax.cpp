#include <iostream>
#include <stdio.h>
using namespace std;


int A[50001];
int maxA[50001];
int N;

int main(){
	int T;
	scanf("%d", &T);
	while(T-->0){
		scanf("%d", &N);
		for(int i=0;i<N;i++)
			scanf("%d", &A[i]);
			
		maxA[N-1] = A[N-1];
		for(int i=N-2; i>=0; i--)
			maxA[i] = max(A[i], maxA[i+1]);
		
		
		
		long long profit = 0;
		int currStocks = 0;
		for(int i=0; i<N; i++){
			if(A[i] == maxA[i]){
				profit  += ((long long)currStocks) * A[i];
				currStocks = 0;
			}
			else{
				profit = profit - A[i];
				currStocks++;
			}	
		}
		
		printf("%lld\n", profit);
	}
	return 0;
}
		

	
