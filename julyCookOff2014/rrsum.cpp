#include <iostream>
using namespace std;



int main(){
	
	int N,M;
	long long q;	
	cin>>N;
	cin>>M;	
	for(int i=0;i<M;i++){
		cin>>q;
		q -= N;
		if(q<=1) cout<<0<<endl;
		else if(q <= N) cout<<q-1<<endl;
		else if(q <= 2*N) cout<<(2*N - q) + 1<<endl; 
		else cout<<0<<endl;
	}
	return 0;
}
	
	
