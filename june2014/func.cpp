#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

#define MODBASE 1000000007


int main(){
	
	cout<<pow(1.1529216e+18-1e15,1/60.0)<<endl;
	int T;
	scanf("%d", &T);
	int A[10001];
	long long S[10001];
	while(T-->0){
		int N,Q;
		scanf("%d %d", &N, &Q);
		for(int i=0;i<N;i++)
			scanf("%d", &A[i]);
		S[0] = A[0];
		for(int i=0;i<N;i++)
			S[i] = (A[i] + S[i-1])%MODBASE;
		
		
		for(int i=0;i<Q;i++){
			long long x;
			scanf("%lld", &x);
			int ind = 0;
			long long sum = ((x%MODBASE) * (long long)A[ind])%MODBASE;
			ind++;
			while(ind<N){
				double temp = pow(x, (1.0)/(ind+1));				
				if(temp < 2.0){
					sum = ((sum + S[N-1])%MODBASE - S[ind-1])%MODBASE;
					break;
				}
				else
				{
					sum = (sum + ((int)temp * (long long)A[ind])%MODBASE)%MODBASE;
				}
				ind++;
			}
			printf("%d", (int)(sum + MODBASE)%MODBASE);
			if(i!=Q-1){
				printf(" ");
			}
		}
		printf("\n");	
	}
	return 0;
}
