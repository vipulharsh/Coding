#include<iostream>
using namespace std;

int results[101][101];
int C[100];
int P[100];
int T[100];
int A[100];
int N,W;


int f(int i, int w){
	
	if(i>=N) return 0;
	
	if(w<=0) return 0;
	
	if(results[i][w]!= -1) return results[i][w];
	
	if(w-T[i]>=0)
	results[i][w] = max( f(i+1,w-T[i]) + A[i] , f(i+1 , w) );
	else 
	results[i][w] = f(i+1 , w); 
	return results[i][w];
}


int main(){
 int Te;
 cin>>Te;
while(Te-->0){
	for(int i=0;i<101;i++)
	  for(int j=0;j<101;j++)
	   results[i][j] = -1;
	cin>>N;
	cin>>W;
	
	int c , p ,t;
	for(int i=0;i<N;i++){
	  cin>>c;
	  cin>>p;
	  cin>>T[i];
	  A[i] = c * p;
   }

	cout<<f(0,W)<<endl;
	
}


return 0;
}
