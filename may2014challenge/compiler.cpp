#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main(){
	int T;
	cin>>T;
	
	while(T-->0){
		string temp;
		cin>>temp;
		int len = temp.length();
		int curr = 0;
		int largestValid = 0;
		for(int i=0;i<len;i++){
			if(temp[i] == '<'){	
				curr++;
			}
			else if(curr == 0){
				break;
			}
			else{
			  curr--;
		   }
			if(curr == 0){
				largestValid = i+1;
			}
		}
		cout<<largestValid<<endl;
	}
	
	return 0;
}
