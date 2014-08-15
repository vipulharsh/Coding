#include <iostream>
using namespace std;


int main(){
	
	
	long long a;
	cin>>a;
	int t = a%6;
	if((t==0) || (t==1) || (t==3)){
		cout<<"yes"<<endl;
	}
	else 
		cout<<"no"<<endl;
	return 0;
}
