#include <iostream>
using namespace std;
#define MODBASE 1000000007
#define Inverse100000 716327852

int fac[100001];
int facInv[100001];


void preprocess(){
	
	
	fac[0] = 1;
	for(int i=1;i<=100000;i++)
		fac[i] = (((long long) fac[i-1]) * i)%MODBASE;
	
	facInv[100000] = Inverse100000;
	for(int i=99999; i>=0; i--)
		facInv[i] = ((long long) (i+1) * facInv[i+1])%MODBASE;
	
}




int main(){
	
	preprocess();
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
		
	
	int res = fac[l/2];
	for(int i=0;i<26;i++){
		if(frequencies[i]>1){
			res = ((long long) res * facInv[frequencies[i]/2])%MODBASE;
		}
	}
	cout<<res<<endl;	
	return 0;
}
