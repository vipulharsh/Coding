#include <iostream>
#include <stdio.h>
using namespace std;


int N;



unsigned int val[100005];

unsigned int th;

int nBits  = sizeof(th) * 8;


long A[2][40][100005];


inline int getbit(int bitPos , int num){
	
    if(((1 << bitPos) & num) == 0) return 0;
    else return 1;;
	
}



pair<long,long> f(int bit , int i){
	
	
 pair<long,long> p;	
	
	
	
	if(i==N-1) {
	   long x = (long)getbit(bit  , val[i]);
	   p.first = (A[0][bit][i] = 1 - x);
	   p.second = (A[1][bit][i] = x);
	   return p; 	
		
	}
	
	
	if(A[0][bit][i]!= -1 && A[1][bit][i]!= -1){
		p.first = A[0][bit][i];
		p.second = A[1][bit][i];
		return p;
	}
	
	
	 pair<long,long> temp;
	
	
	  long x = (long)getbit(bit , val[i]);
	  temp = f(bit , i+1);

	  p.first = (1 - x) + ((1 - x) * temp.first) + (x * temp.second);
	  p.second = x + (x * temp.first) + ((1-x)*temp.second);
	   A[0][bit][i] = p.first;
	   A[1][bit][i] = p.second; 
	 return p;  
}



long sumUp(){
	long T1[100];
	
	for(int i=0;i<=nBits;i++){
		T1[i] = 0;
		for(int j=0;j<N;j++)
			T1[i] += f(i , j).second;
	}	
		
	long answer = 0;
	long multiplier = 1;
	int carry = 0;
	
	for(int i=0;i<nBits;i++){
		answer += multiplier * ((carry + T1[i])%2) ;
		multiplier *= 2;
		carry = (carry + T1[i])/2;
	}
	
	
		answer += multiplier * carry ;
 	
 return answer;	
}





int main(){
	
	
	int T;
	cin>>T;
	while(T-->0){
		cin>>N;
		for(int i=0;i<N;i++)
		 cin>>val[i];
	
		for(int j = 0; j<=nBits ;j++)
			for(int i=0;i<=N;i++) {
				 A[0][j][i] = -1; 
				 A[1][j][i] = -1; 
		    }
	  
	  cout<<sumUp()<<endl;
	  
	}
return 0;
}
