#include <iostream>
#include <stdio.h>
using namespace std;



int main(){
	
	int N,K,T,elm;
	scanf("%d", &T);
	while(T-->0){
		scanf("%d", &N);
		scanf("%d", &K);
		int count = 0;
		for(int i=0;i<N;i++){
			scanf("%d", &elm);
			count += (elm%2 == 0);
		}
		
		if(K==0 && count==N)
			printf("NO\n");	
		
		else if(count >= K)
			printf("YES\n");
		
		else 
			printf("NO\n");	
	}
	
}
