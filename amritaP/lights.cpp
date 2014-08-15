#include <iostream>

int lights[51];

int dp[51][101];

int N,M,K;

using namespace std;

int infi  = 100000000;

int f(int row , int turns){
	
	
	if(dp[row][turns] != -1) return dp[row][turns];
	
	if(turns == 0){
		int sum = 0;
		for(int i=0;i<=row;i++)
		 sum+=lights[i];
		dp[row][turns] = sum;
		return sum; 
	}
	
	if(row==0){
		if(turns%2==0) dp[row][turns] = lights[row];
		else dp[row][turns] = M-lights[row];
		return dp[row][turns];
	}
	
	
	int maxVal = lights[row]  + f(row-1 , turns); 
	int s = turns-2;
	while(s>=0){
		maxVal = max(maxVal , lights[row] + f(row - 1 , s));  
		s = s -2;
	}
	s = turns - 1;
	while(s>=0){
		maxVal = max(maxVal , (M - lights[row]) + f(row - 1 , s));  
		s = s - 2;
	}
	
	dp[row][turns] = maxVal;
	return maxVal;
}






int main(){
	
 int T;
 cin>>T;
 char c;
 while(T-->0){
 	cin>>N>>M>>K;
 	for(int i=0;i<N;i++){
 		int count=0;
 		for(int j=0;j<M;j++){
 			cin>>c;
 			if(c=='*') count++;
 		}
 		lights[i] = count;
 	}
 
 for(int i=0;i<=N;i++)
 	for(int j=0;j<=K;j++)
 		dp[i][j] = -1;
 
 cout<<f(N-1 , K)<<endl;
}   
 
	return 0;
}	
	 
		
