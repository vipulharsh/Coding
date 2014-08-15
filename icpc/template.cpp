#include <iostream>
#include <stdio.h>
using namespace std;

double results[2510][1255];


double f(int x , int i){
  
  if(2*i >= x) return ((double)x)/2;
  
  if (i<0 || x<=0)
	return 0;

  if(results[x][i]!=-1) return results[x][i];
  
  results[x][i]  =  1 +
          ((double)i/(double)(x-i))	 * f(x-2 , i-1) +
          ((double)(x-2*i)/(double)((x - i) * (x - i -1))) * f(x-2 , i) + 
          ((double)((x-2*i) * (x-(2*i)-2))/(double)((x - i) * (x - i -1))) *  f(x , i+2) + 
          ((double)((x-2*i)*i)/(double)((x - i) * (x - i -1))) * (1 + f(x-2 , i)) ;
  return results[x][i];
}



int main(){
 
 for(int i=0;i<2510;i++){
	for(int j=0;j<1255;j++)
	results[i][j] = -1;	 
 }
 
 
results[2][0] = 1;
results[0][0] = 0;

// int t=2;
int m,n;
cin >>m;
 while(cin){
	cin>>n;
	printf("%.4lf \n" , f(m*n,0));
	cin >>m;
	//t--;
}
  


return 0;
}
