#include <iostream>
#include <stdio.h>
#include <assert.h>
using namespace std;


long long binSearch(long long N, long long K){
	
	long long lt = N*K;
	
	int mid = N/2 + (N%2);
	
	if((mid * (N - mid)) <= lt)
		return mid;
	
	int high = N/2 + (N%2);
	int low = 1;
	
	
	while(low <= high){
		
		mid = (low + high)/2;
		
		if((mid * (N - mid)) > lt)
			high = mid - 1;
		
		
		else if(((mid+1) * (N - (mid+1))) <= lt)
			low = mid + 1;
		
		
		else
			return mid;
		
	}
	
	assert(0);
}



int main(){
	
	int T;
	scanf("%d", &T);
	int N,K;
	while(T-->0){
		
		scanf("%d", &N);
		scanf("%d", &K);
		int ret = binSearch(N,K);
		if(ret == (N+1)/2)
			ret = N-1;
		else 
			ret = 2*ret;
			
		printf("%d\n", ret);
	}
	return 0;
}
