#include <iostream>
using namespace std;


int main(){
	
	int T;
	cin>>T;
	while(T-->0){
		int N,M;
		cin>>N>>M;
		if(N%2==0 || M%2==0)
			cout<<"1/2"<<endl;
		else{
			N = N/2;
			M = M/2;
			cout<<(((long long)N) * M * 2) + N + M<<"/"<<((long long) (2*N + 1)) *  ((long long) (2*M + 1))<<endl;
		}	
	}
	return 0;
}
