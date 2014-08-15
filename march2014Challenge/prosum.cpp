#include <iostream>
using namespace std;


long long N;


int main(){
	
	int T;
	cin>>T;
	long long ones;
	long long twos;
	long long elm;
	while(T-->0){
		cin>>N;
		twos = 0;
		ones = 0;  //ones and zeroes
		for(int i=0;i<N;i++){
			cin>>elm;
			ones += ((elm == 0) || (elm == 1));
			twos += (elm == 2);
		}
		cout<<(N*(N-1))/2 - ((ones*(ones - 1))/2 + (ones*(N - ones)) + (twos * (twos -1))/2) << endl;
	}
	return 0;
}
