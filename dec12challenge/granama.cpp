#include <iostream>
#include <string.h>
using namespace std;


int main(){
	
	
	int count1[26];
	int count2[26];
	
	
	int T;
	cin>>T;
	
	while(T-->0){
		
			for(int i=0;i<26;i++)
				count1[i] = (count2[i] = 0);

			string s1, s2;
			cin>>s1>>s2;
			
			int l1 = s1.length();
			int l2 = s2.length();
			
			for(int i=0;i<l1;i++)
				count1[s1[i] - 'a']++;
			
			for(int i=0;i<l2;i++)
				count2[s2[i] - 'a']++;
				
				
			bool ans1, ans2;
			ans1 = (ans2 = true);
			for(int i=0;i<26;i++){
				//cout<<count1[i]<<" "<<count2[i]<<endl; 	
				ans1 = ans1 && (count1[i] == count2[i]);
				ans2 = ans2 && (((count1[i]>0) && (count2[i]>0)) || ((count1[i]==0) && (count2[i]==0))); 
				//cout<<ans1<< "-----------"<<ans2<<endl;
			}	
			
			//cout<<ans1<<" : "<<ans2<<endl;
			if(ans1 == ans2)
				cout<<"YES"<<endl;
				
			if(ans1 != ans2)
				cout<<"NO"<<endl;
		
	}
	return 0;
}
	
	
	
