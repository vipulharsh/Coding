#include <iostream>
#include <string>
using namespace std;
int main(){
	int T;
	cin>>T;
	string s="";
	while(T-->0){
		s.clear();
		cin>>s;
		if((s.find("101") != string::npos)  || (s.find("010") != string::npos))
			cout<<"Good"<<endl;
		else
		  cout<<"Bad"<<endl;	
	}
	return 0;
}
