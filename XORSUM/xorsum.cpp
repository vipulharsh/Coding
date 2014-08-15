#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX_BIT 30
#define MODBASE 1000000009

inline int getbit(int i, int bit){ //indexed by 0. Thus, the 0th bit of 1 is 1 . All other bits are 0.
	return (i>>bit)%2;
}

int N;
int A[100001];
long long results[100001][2];


/*
long long getResults(int i, int parity, int bit){
	
	
	if(i>=N) return (1-parity);
	if(results[i][parity] != -1) return results[i][parity];
	
	long long threshold = (1<<bit);
	long long zeroNum = (A[i] >= threshold)? threshold : A[i] + 1;
	long long oneNum =  (A[i] >= threshold)? A[i] - threshold + 1 : 0;
	
	long long ret = (zeroNum * getResults(i+1, parity, bit))%MODBASE;
	ret = (ret + (oneNum * (getResults(i+1, (parity+1)%2, bit))%MODBASE))%MODBASE;
	results[i][parity] = ret;
	return ret;
}
*/




long long calculateResults(int parity, int bit){
	
	long long current = 1;
	long long ret = 0;
	int i = 1;
	int threshold  = (1<<bit);
	
	
	results[N][0] = 1;
	results[N][1] = 0;
	for(i=N-1;i>=0;i--){
		for(int p=0;p<2;p++){
			long long zeroNum = (A[i] >= threshold)? threshold : A[i] + 1;
			long long oneNum =  (A[i] >= threshold)? A[i] - threshold + 1 : 0;
			long long ret = (zeroNum * results[i+1][p])%MODBASE;
			ret = (ret + ((oneNum * results[i+1][(p+1)%2])%MODBASE))%MODBASE;
			results[i][p] = ret;
		}
   }
	
	i=1;
	while((i<=N) && (A[i-1] >= threshold)){
		ret = (ret + ((current * results[i][parity])%MODBASE))%MODBASE;
		parity = (parity + 1)%2;
		current = (current * (A[i-1] - (threshold - 1)))%MODBASE;
		i++;
	}
	return ret;
}



void partition(int bit){
	
	int threshold  = (1<<bit);
	int current = -1;
	int temp;
	for(int i=0;i<N;i++){
		if(A[i] >= threshold){
			current++;
			temp = A[current];
			A[current] = A[i];
			A[i] = temp;
		}
	}
}




int main(){
	
	int T;
	scanf("%d", &T);
	while(T-->0){
		scanf("%d", &N);
		int maxA=-1;
		for(int i=0;i<N;i++){
			scanf("%d", &A[i]);
			maxA = max(A[i], maxA);
		}
		
		int bit=-1;
		while(maxA>0){
			bit++;
			maxA = maxA/2;
		}
		
		long long sum = 0;
		
		for(; bit>=0; bit--){
			partition(bit);  //O(N)
			long long threshold = (1<<bit);
			if(A[0]<threshold) continue;
			
			int parity = 0;
			for(int i=0;i<N;i++){   //O(N) loop
				parity = (parity + getbit(A[i], bit))%2;
			}
		   sum = (sum + calculateResults(parity, bit))%MODBASE;
			for(int i=0;i<N;i++){
				if(A[i] >= threshold) A[i] = A[i] - threshold;
				else break;  //should work 
			}
		}
		 
		printf("%d\n", (int)(sum+1)%MODBASE);		
	}
	return 0;
}
