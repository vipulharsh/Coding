#include <iostream>
using namespace std;

int main(){
	
	int N,K;
	int A[100001];
	cin>>N;
	cin>>K;
	int mini,maxi;
	cin>>A[0];
	mini = A[0];
	maxi = A[0];
	for(int i=1;i<N;i++){
		cin>>A[i];
		mini = min(mini, A[i]);
		maxi = max(maxi, A[i]);
	}
	
	long long t;
	if(K==0){
		for(int i=0;i<N;i++)
			cout<<A[i]<<" ";	
	}
	else if(K%2 == 0){
		for(int i=0;i<N;i++){
			cout<<(long long)A[i] - mini<<" ";
		}	
	}
	else{
		for(int i=0;i<N;i++)
			cout<<(long long)maxi - A[i]<<" ";	
	}
	cout<<endl;

}
