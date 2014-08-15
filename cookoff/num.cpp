#include<iostream>
using namespace std;


long long basemod = 1000000007;

long long f(long long j , long long i){
//	cout<<i<<" : "<<j<< " : "<<endl;
	long long x = (  ((i * (i + 1)) - (j * (j + 1)))  /2  ) % basemod;
//	cout<<x<<endl;
	return x;
}



int digits(long long i){
	int count=0;
	while(i!=0){
		i = i/10;
		count++;
	}
	return count;
}


int main(){
 int T;
 cin>>T;
 
 long long l,r;
 while(T-->0){
	cin>>l>>r;
	
	int dl = digits(l);
	int dr = digits(r);
	
	long long sum = 0,a=10,b=1;
	
	for(int j=1;j<dl;j++)
	{ a = a*10; 
	  b = b*10;
	 }
	
	if(dl!=dr){
	sum = (sum + (dl * f(l-1,a-1))) % basemod;
	
	a = a*10; 
	b = b*10;
	for(int i=dl+1 ; i<=dr-1;i++)
	{
		sum = (sum + (i*f(b-1,a-1)))%basemod;
		
		//cout<<" : "<<sum<<endl;
		a = a*10; 
		b = b*10;
	
    }
    
    sum = (sum + (dr*f(b-1,r)))%basemod;
   }
   else 
   sum = (sum + (dl * f(l-1,r))) % basemod;
	
	cout<<sum<<endl;
} 
 return 0;
}
