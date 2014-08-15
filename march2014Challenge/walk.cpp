#include <iostream>


int N;

using namespace std;


int main(){
	
	int T;
	int elm;
	int minVel;
	cin>>T;
	while(T-->0){
		cin>>N;
		minVel = -1;
		for(int i=0; i<N; i++){
			cin>>elm;
			minVel = max(minVel, elm+i);
		}
		cout<<minVel<<endl;
	}	
 return 0;	
}
