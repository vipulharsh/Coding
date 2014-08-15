#include <iostream>
#include <string>
using namespace std;
int main(){
  int T;
  cin>>T;
  string s;
  while(T-->0){
	  s= "";
	  cin>>s;
	  int l = s.length();
	  bool answer  = true;
	  for(int i=0;i<=l/2;i++)
	    answer  = answer && (s[i] == s[l-1-i]);
	  
	 if(answer) cout<<"YES"<<endl;
	 else cout<<"NO"<<endl; 
  }


return 0;
}
