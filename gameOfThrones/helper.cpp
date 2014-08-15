#include <iostream>
using namespace std;
#define MODBASE 1000000007


int main(){
	
	int elm;
	cin>>elm;
	int i;
	for(i=0;i<MODBASE;i++)
		if(((long long)i * elm)%MODBASE == 1)
			break;
	cout<<i<<endl;
	return 0;
}		
