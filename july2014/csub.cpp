#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;



int main(){
	
	int T,l;
	cin>>T;
	
	while(T-->0){
		cin>>l;
		string s;
		cin>>s;
		int count = 0;
		for(int i=0;i<l;i++)
			count+= (s[i] == '1');	
		printf("%lld\n", ((((long long)count) * (count-1))/2) + count);
		
	}
	
	return 0;
}
