#include <iostream>
using namespace std;


int main(){
	
	int T;	
	cin>>T;
	int x,y;
	while(T-->0){
		cin>>x>>y;
		if(x<0) x = -x;
		if(y<0) y = -y;
		
		int ans = 0;
		if(y>=x){
			ans += (2*x) + (4*((y-x)/2)) + ((y-x)%2);
		}
		
		else{
			ans += (2*y) + (4*((x-y)/2)) + (3*((x-y)%2));
		}
		
		cout<<ans<<endl;
	}
	return 0;
}
