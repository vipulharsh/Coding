#include <iostream>
#include <stdio.h>

using namespace std;

#define in(x) scanf("%d", &x) 


short int dp[361][361][361];


short int getDP(int i, int n, int remaining){
	
	if(remaining == 0 && n==0) return 1;
	
	if(n==0) return 0;
	
	if(i>remaining) return 0;
	
	if(i==361) return 0;
	
	if(dp[i][n][remaining] != -1) return dp[i][n][remaining];
	
	dp[i][n][remaining] = ((getDP(i+1, n, remaining)==1) || (getDP(i+1, n-1, remaining-i)==1));
	return dp[i][n][remaining];
	
}


int main(){
	
	int T;
	in(T);
	
	for(int i=0;i<=360;i++){	
		for(int j=0;j<=361;j++)
			for(int k=0;k<361;k++)
				dp[i][j][k]=-1;
	}
		
	while(T-->0){
		
		int N;
		in(N);
		
		cout<<((360%N == 0)? 'y' : 'n')<<" ";
		cout<<((360 >= N)? 'y' : 'n')<<" ";
		
		if(N>360) cout<<'n'<<endl;
		else{
			cout<<((getDP(1, N, 360) == 1)? 'y' : 'n')<<endl;
		}
	}
	return 0;
}
