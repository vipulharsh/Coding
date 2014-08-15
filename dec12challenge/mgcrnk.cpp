#include <iostream>
#include <iomanip> 
using namespace std;

#define infi 1000000000


int points[101][101];
int S[101][101];
int N;

int dp(int i, int j){
	
	if(i==N-1 && j==N-1) return 0;
	
	if(i>=N || j>=N) return -infi;
	
	if(points[i][j] != -1) return points[i][j];
	
	points[i][j] = max(dp(i,j+1), dp(i+1,j)) + S[i][j];
	return points[i][j];
	
}


int main(){
	
	
	int T;
	cin>>T;
	while(T-->0){
		
		cin>>N;
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>S[i][j];
				
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				points[i][j] = -1;
				
		int ans = dp(0,0);
		if(ans < 0)
			cout<<"Bad Judges"<<endl;	
			
		else{
			cout << fixed;	
			cout<<setprecision(7)<< (long double)ans/(2*N - 3)<<endl;
		}
		
	}
	return 0;
}
