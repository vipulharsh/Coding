#include <iostream>
#include <stdio.h>
using namespace std;
#define MODBASE 1000000007


int A[100001];
int N;
	

int modexp(int n, int k){
	
	if(k==0) return 1;
	int a = modexp(n, k/2);
	a = ((long long) a * a)%MODBASE;
	if(k%2 == 1)
		a = ((long long) a * n)%MODBASE;
	return a; 
}



int quickRange(int L, int R){ //both L and R inclusive

	if(L>N-1 || R<0 || (R<L)) return 1;
	
	int maxNum = -1;
	int maxIndex = -1;
	
	for(int i=L;i<=R;i++){
		if(A[i] > maxNum){
			maxIndex = i;
			maxNum = A[i];
		}
	}
	
	
	//maxIndex is the pivot


}






int main(){
	
	scanf("%d", &N);
	for(int i=0;i<N;i++)
		scanf("%d", &A[i]);
	printf("%d", quickRange(0, N-1));
	return 0;
	
}
