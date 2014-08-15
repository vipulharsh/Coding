#include <iostream>
using namespace std;
int gcd(int x,int y){
	if (y==0) return x;
	else return gcd(y , x%y);
	
}


int gcdH(int x,int y){
	if(x<=y) return gcd(y,x);
	else return gcd(x,y);
}



int main(){
  	
 int a,b,i,j,k;
 
 
 
 while(true){
 cin>>a>>b;
 
 if(a==1 && b==1) break;
 i=1;	
 
   while(a!=0){	
	if(a*i-b >= 0){
	  j = a;
	  a = a*i - b;
	  b = b*i;
	  int hcf = gcdH(a,b);
	  a = a/hcf;
	  b = b/hcf;
	  cout<<i<<" ";
	  continue;
    }
   i++;
 }
 cout<<endl;
} 
  
   
	return 0;
}
