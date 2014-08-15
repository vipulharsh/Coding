#include <iostream>
#include <string.h>
using namespace std;


#define OFFSET 33



int main(){
	
	int T;
	cin>>T;
	string s;
	char replacements[94];
	while(T-->0){
		
		int N;
		cin>>N;
		
		for(int i=0;i<94;i++)
			replacements[i] = (char)(i+OFFSET);
		
		for(int i=0;i<N;i++){
			char a,b;
			cin>>a;
			cin>>b;
			replacements[a-OFFSET] = b;
		}
					
		cin>>s;
		int l = s.length();
		for(int i=0;i<l;i++){
			//cout<<s[i]<<" : ";
			s[i] = replacements[s[i] - OFFSET];
			//cout<<s[i]<<endl;
		}
		
		int i=0;
		bool zero = true;
		while(i<l && s[i]!='.'){
			zero = zero && (s[i] == '0');
			i++;
		}
		
		if(!zero){
			int j = 0;
			while(s[j]=='0' && j<i)
				j++;
			for(int k=j;k<i;k++)
				cout<<s[k];	
		}	
			
		int b = l;
		int j=l-1;
		while(j>=i+1 && s[j]=='0')
			j--;
		
		if(i+1<=j){
			cout<<".";	
			for(int k=i+1;k<=j;k++)	
				cout<<s[k];
		}
		else if(zero)
			cout<<"0";	
		
		cout<<endl;
		
	}
	return 0;	
}

