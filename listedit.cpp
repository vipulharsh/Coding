#include <iostream>
using namespace std;

int student_list[105];
int fac_list[105];
int M,N;


int results[101][101];	




int f(int i , int j){
	
	
	if(i==M) return (N-j);
	if(j==N) return (M-i);
	
	
	if(results[i][j]!=-1) return results[i][j];  
	
	
	if(student_list[i] == fac_list[j]){
		results[i][j] = f(i+1 , j+1);
		return results[i][j];
	}
	
	else if(student_list[i] < fac_list[j]){
			results[i][j] = min(1 + f(i+1 , j) , 1 + f(i+1 , j+1));
		return results[i][j];

	}
	
	else if(student_list[i] > fac_list[j]){
			results[i][j] = min(1+ f(i+1 , j+1) , 1 + f(i , j+1));
		return results[i][j];

	}
	
}






int main(){
 int T;
 cin>>T;
 
 
 
 
 while(T-->0){
   cin>>M;
   for(int i=0;i<M;i++)
	   cin>>student_list[i];
 
   cin>>N;
   for(int i=0;i<N;i++)
	   cin>>fac_list[i];
 
   for(int i=0;i<101;i++)
    for(int j=0;j<101;j++)
      results[i][j] = -1;
 
   cout<<f(0,0)<<endl;
 
 }
 return 0;
}
