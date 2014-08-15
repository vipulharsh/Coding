#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int main(){
	
	int T,N;
	scanf("%d", &T);
	int A[100001];
	while(T-->0){
		scanf("%d", &N);
		for(int i=0;i<N;i++){
			scanf("%d", &A[i]);
		}
		sort(A, A+N);
		
		int count = 1;
		for(int i=1;i<N;i++)
			count += (A[i] != A[i-1]);
		
		printf("%d\n", count);	
	}
	return 0;
}
