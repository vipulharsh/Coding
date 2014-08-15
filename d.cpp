#include <iostream>
using namespace std;
long results[21];

long d(int n){
	if(results[n]!=-1)return results[n];
	
	if(n%2 == 0){
		 results[n] = (n*d(n-1)) + 1;
		 return results[n];
    }
    if(n%2 == 1){
		 results[n] = (n*d(n-1)) - 1;
		 return results[n];
    }
    
 }   

int main(){
 for(int j=0;j<=20;j++)
   results[j] = -1;
   
 results[0] = 0;
 results[1] = 0;
 
  int N,j; 
  cin>>N;  	
 for(int i=0;i<N;i++){
	 cin>>j;
	 cout<<d(j)<<endl;
 }	
	
return 0;
}	
