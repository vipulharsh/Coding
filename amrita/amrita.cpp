#include <iostream>
using namespace std;
int main(){
 int C;
 int N,M,T;
 cin>>C;
 while(C-->0){
	 cin>>N>>M>>T;
	 if(N%M == 0) cout<< (N/M)* 2* T<<endl;
	 else cout<<((N/M) + 1)* 2* T<<endl;
}


return 0;
}
