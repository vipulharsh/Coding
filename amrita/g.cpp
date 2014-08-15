#include <iostream>
using namespace std;

	int opt[301][301][301];
	
	 
	int intensity[300][3];





inline range(int a ,int b, int c){
	
	
	return max(a,max(b,c)) - min(a , min(b,c));
	
	
}

int f(int i,int j,int k){
	
	
	
	if(i==0 && j==0 && k==0) return 0;
	
	
	if(opt[i][j][k] != -1) return opt[i][j][k];
	
	int minR ;
	bool checked = false;
	if(i>=2){
		
		checked  = true;
		
	}
	
	
	if(j>=2){
		int min = intensity[j][1],max = intensity[j][1];
		if(!checked)
			minR = (max - min) + f(i , j-2 , k);
			checked  = true;
		else
		  minR = min(minR , (max - min) + f(i, j-2 , k));	
		
	}
	
	
	if(k>=2){
		
		if(!checked)
			minR = (max - min) + f(i , j , k-2);
			checked  = true;
		else
		  minR = min(minR , (max - min) + f(i, j , k-2));	
		
	}
	
	if(
	
	return 0;
	
}





int main(){
int T,N;
cin>>T;
while(T-->0){
	
	cin>>N;
	for(int i;i<N;i++)
	  for(int j;j<3;j++)
	   cin>>intensity[i][j];

	
	for(int i=0;i<N;i++)
	 for(int j=max(i-2,0);j<=min(i+2,N-1);j++)
	  for(int k = min(i-2,0); k<=min(i+2,N-1); k++)
	   opt[i][j][k] = -1;
	
	 cout<<f(N-1,N-1,N-1)<<endl;
}


return 0;
}
