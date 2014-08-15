#include <iostream>
#include <string>
using namespace std;

int OFFSET = (int)'a';

int main(){
	
	int T;
	cin>>T;
	string s;
	int freq[26];
	while(T-->0){
		cin>>s;
		int l = s.length();
		for(int i=0;i<26;i++)
			freq[i] = 0;
		
		for(int i=0;i<l/2;i++){
			freq[s[i] - OFFSET]++;
			freq[s[l-i-1] - OFFSET]--;
		}
		bool result = true;
		for(int i=0;i<26;i++)
			result = result && (freq[i] == 0);
		cout<<(result? "YES" : "NO")<<endl;	
	}
}
