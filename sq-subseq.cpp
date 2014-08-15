#include <iostream>
#include <stdio.h>
#include <string>



using namespace std;


long results[50][50][50][50];


string s;
int size;

long f(int i, int j , int k, int l){
	
	if(k>l || i>j || j>=k) return 0;
	
	if(results[i][j][k][l] != -1) return results[i][j][k][l];
	
	
	long sum = 0;
	string temp = s.substr(k,l);
	for(int h=i;h<=j;h++){
	  int last =  temp.find_last_of(s[h]);
      if(last == -1) continue;
      sum = (sum + 1 + f(i,h,last+1,l))%1000000007;
   }
   
   results[i][j][k][l] = sum;
   return  results[i][j][k][l];
}




int main(){
 
 int T;
 cin>>T;
 long sum1;

 while(T-->0){
  cin>>s;
  sum1 = 0;
  size = s.length();
 
  for(int i=0;i<size;i++)
	for(int j=i;j<size;j++)
		for(int k=j;k<size;k++)
		  for(int l=k;l<size;l++)
		    results[i][j][k][l] = -1;
	

  for(int i=0; i<size-1; i++){
	  
   int last =  s.find_last_of(s[i]);
   
   if(last==i) continue;
   cout<<last<<" : "<<s[i]<<endl;
   sum1 = (sum1 + 1 + f(0 , i-1 , i+1 , last-1))%1000000007; 
  }	   
  cout<<sum1<<endl;
}	 
	 
	 
return 0;	 
	 
 } 
	 
