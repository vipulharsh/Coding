#include <iostream>
using namespace std;
int main(){
	int T,N;
	int max,min;
	cin>>T;
	
	int elt;
	
	while(T-->0){
		cin>>N;
		cin>>elt;
		max = elt;
		min = elt;
		for(int i=0; i< N-1 ;i++){
			cin>>elt;
			if(elt > max) max = elt;
			if(elt < min) min = elt;
		}
		cout<<min<<" "<<max<<endl;
	}
	
	
	return 0;
}
