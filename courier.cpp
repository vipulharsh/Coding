#include <iostream>
using namespace std;



#define infi 100000000

int res[101][101];


int x[101];
int t[101];
int N;





int oldDiagonal1[101];
int oldDiagonal2[101];


int newDiagonal1[101];
int newDiagonal2[101];


int currDiagonalLength;

inline int updateTime(int currTime , int startTime){
  return max(currTime , startTime);
}
	
	
	
inline int pseudores(int i , int *diagonal , int length){
	if(i<0 || i>=length) return infi;
	return diagonal[i];
}	
	
	


int calcDiagonal(){
	int val1 , val2;
	int oldDiagonalLength = currDiagonalLength -1;
	for(int i=0;i<currDiagonalLength;i++){
		val1 = pseudores(i, oldDiagonal1 , oldDiagonalLength);
		val2 = pseudores(i-1 , oldDiagonal2 ,oldDiagonalLength);
	    
	    int a = N - oldDiagonalLength -1 +i;
	    int b = i;
	  //  cout<<val1<<" " <<val2<<" "<<a<<" "<<b<<endl;
	    newDiagonal1[i] = min(
	                        max(val1 , t[a+1]) + x[a+1] - x[a] , 
	                        max(val2 , t[b-1]) + x[a] - x[b-1]); 
	   
	 //  cout<<newDiagonal1[i]<<endl;
	   val1 = pseudores(i-1 , oldDiagonal2 , oldDiagonalLength);
	   val2 = pseudores(i, oldDiagonal1 , oldDiagonalLength);
	//   cout<<val1<<" "<<val2<<" "<<a<<" "<<b<<endl;
	   a = i;
	   b = N - oldDiagonalLength -1 + i;
	   newDiagonal2[i] = min(
	                         max(val1 , t[a-1]) + x[a] - x[a-1] , 
	                         max(val2 , t[b+1]) + x[b+1] - x[a]);
	 //  cout<<newDiagonal2[i]<<endl;
	 //  cout<<"**************"<<endl;
  }
}
	
	
	
	
	
	
	
	
	



	



int f(int i , int j){
	
	
	if(i==0 && j== N-1) return x[0];
	if(i==N-1 && j==0) return x[N-1];
	
	if(i<0 || j<0) return infi;
	if(i>=N || j>=N) return infi;
	
	

	
	if(res[i][j]!=-1) return res[i][j];
	
	
	if(i<j){
		res[i][j] =	min( 
				(max(f(i-1 , j) , t[i-1]) + (x[i] - x[i-1])) , 
				(max(f(j+1 , i) , t[j+1]) + (x[j+1] - x[i]))
			  );
	}		
	
	 
	if(i>=j){
		res[i][j] =	min( 
				(max(f(i+1 , j) , t[i+1])
								+ (x[i+1] - x[i])) , 
				(max(f(j-1 , i) , t[j-1]) 
								+ (x[i] - x[j-1]))
			  );
	}
	
   return res[i][j];	    
	
}



int main(){

cin>>N;  



for(int i=0;i<101;i++)
   for(int j=0;j<101;j++)
     res[i][j]  = -1;



for(int i=0;i<N;i++){
	cin>>x[i];
	cin>>t[i];
}



	int minval;
	int temp = f(0,0);
	
	minval =  max(t[0] , temp);
	
	for(int i=1;i<N;i++){
		temp = f(i,i);
		minval = min(minval , max(t[i] , temp));
	}

  cout<<minval<<endl;
  
  
  currDiagonalLength = 2;
  oldDiagonal1[0] = x[N-1]; 
  oldDiagonal2[0] = x[0];
  
  while(currDiagonalLength < N){
	  calcDiagonal();
	  for(int i=0;i<currDiagonalLength;i++){
		oldDiagonal1[i] = newDiagonal1[i];
	    oldDiagonal2[i] = newDiagonal2[i];
   }
	  currDiagonalLength ++;
  } 
  calcDiagonal();
  minval = newDiagonal1[0];
  for(int i=0 ;i<N;i++){
      // cout<<newDiagonal1[i]<<" "<<newDiagonal2[i]<<endl;
       minval = min(minval , newDiagonal1[i]);
   }
   cout<<minval<<endl;
return 0;
}
