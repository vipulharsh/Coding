#include <iostream>
#include <string>
using namespace std;


int main(){
	string s;
	cin>>s;
	
	int frequencies[26];
	
	for(int i=0;i<26;i++)
		frequencies[i] = 0;
	
	int l = s.length();
	
	for(int i=0;i<l;i++)
			frequencies[s[i]-'a']++;
			
	int count=0;
	for(int i=0;i<26;i++)		
		count += (frequencies[i]%2 == 1);
	
	
	if( (l%2==0 && count==0) || (l%2==1 && count==1))
		cout<<"YES"<<endl;
	else 
		cout<<"NO"<<endl;
	
	return 0;
}	
