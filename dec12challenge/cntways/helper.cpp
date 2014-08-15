#include <iostream>
using namespace std;

#define MODBASE 1000000007



int main(){
	int num = 644158465;
	int i;
	for(i=1;i<MODBASE;i++){
		if(((long long)num * i)%MODBASE == 1){
			cout<<i<<endl;
			break;
		}
	}
	cout<<((long long) num * i)<<endl;
	return 0;
}

