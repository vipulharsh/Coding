#include <iostream>
#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
#define infi 1000000000
 
 
int N;
int dp[1001][501];
int H[501];
int K[501];
 
int ch; 
inline void input(int &x )
{
	x=0;
	while((ch<'0' || ch>'9')&& ch!=EOF)	ch=getchar_unlocked();
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
 
}
 
 
 
int getDP(int dist, int station){
	if(dist == 0) return 0;
	if(station>= N || dist<0) return infi;
	if(dp[dist][station] != -1) return dp[dist][station];
	
	dp[dist][station] = min(1 + getDP(dist - K[station], station), getDP(dist, station + 1));
	return dp[dist][station];
}
 
 
 
int main(){
	int T;
	//scanf("%d", &T);
	input(T);
	while(T-->0){
		//scanf("%d", &N);
		input(N);
		int maxHi = -1;
		for(int i=0;i<N;i++){
			//scanf("%d", &H[i]);
			input(H[i]);
			maxHi = max(maxHi, H[i]);
		}
		for(int i=0;i<N;i++)
			scanf("%d", &K[i]);
		for(int i=0;i<=2*maxHi;i++)
			dp[i][N] = infi;
		for(int j=0;j<=N;j++)
			dp[0][j] = 0;
		for(int dist=1; dist<=2*maxHi;dist++){
			for(int station = N-1;station>=0;station--){
				dp[dist][station] = dp[dist][station+1];
				if(dist >= K[station])
					dp[dist][station] = min(dp[dist][station], dp[dist-K[station]][station]+1);
				}
		}
		int sum = 0;
		for(int i=0;i<N;i++)
			sum += dp[2*H[i]][0];
		printf("%d\n", sum);
	}
	return 0;
}
