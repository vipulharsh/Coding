#include <iostream>
#include <string>
using namespace std;




int main(){


	int T;
	cin>>T;
	string s;
	int res[100002];
	while(T-->0){
		cin>>s;
		int length  = s.length();
		int curr_end = -1;
		int max_suffix = -1;
		for(int i = 1;i<length;i++){
		  //cout<<max_suffix<<" "<<curr_end<<endl;
		  if(i<curr_end){
		    int diff = i - max_suffix;
		    if(max_suffix != -1 && res[diff] < curr_end - i){
				res[i] = res[diff];
				continue;
			}
		 }	
			//else
		    int temp = max(i , curr_end);
			 while(s[temp - i] == s[temp] && temp<length) temp++;
			   
		 //   cout<<"temp is :"<<temp<<" :i is "<<i<<endl;
		     curr_end = temp;
		     max_suffix = i;
		     res[i] = (temp - i);  	
		
	   }	
	
		
		long long sum = length;
		//cout<<sizeof(sum) <<" "<<sizeof(int)<<endl;
		for(int i = 1;i<length;i++){
		//	cout<<res[i]<<endl;
		    sum += res[i];
		}
        cout<<sum<<endl;

	}
return 0;
}
