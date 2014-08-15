#include <iostream>
using namespace std;
 int pos[10];
 int dim[10];
 
  int T;
 int N,steps;


long long outerdp[12][303];   //[dimension][steps]
bool chalao = true;

long long innerdp[103][103][303];  //[dimension][position_in_array][steps]


long long choose[301][301]; //n choose m
long long iDF(int i , int j , int k){
	
	if(j<=0 || j>i) return 0;
	
	if(k==0) return 1;
	
	if(innerdp[i][j][k]!=-1) return innerdp[i][j][k];
	
//	cout<< "here "<<endl;
	
	innerdp[i][j][k] = (iDF(i , j-1 , k-1) + iDF(i , j+1 , k-1))%1000000007;
	return innerdp[i][j][k];
}	
	
	
long long chooseF(int n , int m){
	if(m==0 || m==n) return 1;
	
	if(choose[n][m]!=0) return choose[n][m];
	
	choose[n][m] = (chooseF(n-1 ,m) + chooseF(n-1 , m-1))%1000000007;
	return choose[n][m];

}


long long outerdpF(int n , int nSteps){

	
	if(nSteps==0) return 1;
	
	if(n==N-1) {

    long long temp = iDF(dim[n] , pos[n] , nSteps);	
    //		cout<<n<<" : "<<nSteps<<" : "<<temp<<endl;
	return temp;
	}
	if(outerdp[n][nSteps] != -1) return outerdp[n][nSteps];
	
//   cout<<n<<" , "<<nSteps<<" ; "<<outerdp[3][1]<<endl;
    long long sum = 0;
    for(int h=0;h<=nSteps;h++)	{
     long long temp1 =  (chooseF(nSteps , h) * ((iDF(dim[n] ,  pos[n] , h) * outerdpF(n+1 , nSteps - h))% 1000000007)) % 1000000007 ;
     sum  = (sum + temp1) % 1000000007 ;
     } 
    outerdp[n][nSteps] = sum;
    //cout<<n<<" : "<<nSteps<<" : "<<sum<<endl;
    return sum; 	
}


int main(){
 
for(int i=0;i<101;i++)
	for(int j=0; j<101; j++){
	   for(int k=0; k<301; k++)
	     innerdp[i][j][k] = -1;
	//  cout<<j<<endl;
  }   

for(int i=0;i<101;i++)
	for(int j=0; j<101; j++)
	  innerdp[i][j][0] = 1;



  


cin>>T;
 
  
 while(T-->0){
	cin>>N>>steps; 
	
	for(int i=0;i<N;i++)
		cin>>pos[i];
		
	for(int i=0;i<N;i++)
		cin>>dim[i];
		
	for(int i=0;i<10;i++)
	 for(int j=0;j<=steps;j++)	
		outerdp[i][j] = -1;
	
	cout<<outerdpF(0 , steps)<<endl;	
	
}
 
 

return 0;
}
