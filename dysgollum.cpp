#include <iostream>
#include <bitset>

using namespace std;


#define modbase 1000000007

long long int A[1024][405]; 
int N,K;


//bit is 0 indexed
inline int getbit(int i , int bit){
 // cout<<" : "<<i<<" "<<bit<<" : ";
  return (i/(1<<bit)) % 2;
}


bool checkPalindrome(int i, int k){ //check if a palindrome(of length k) for first k bits

 //   cout<< (bitset<10>) i <<endl;
   
    bool ret=true;
    for(int a=0;a<=(k-1)/2;a++){
        ret = ret && (getbit(i,a) == getbit(i, (k-1-a)));
    }

    return ret;
}

int f(int N, int lastK){

 
   if(N==K){
     return (1 - checkPalindrome(lastK , K));
   }
 
   if(A[lastK][N] != -1) return A[lastK][N];
   
    long long answer=0;

    if(checkPalindrome(lastK , K)) return 0;
    
    int lastK1 = lastK + (1<<K);
    if(!checkPalindrome(lastK1 , K+1)) answer = (answer + f(N-1 , (lastK1>>1)))%modbase;

    lastK1 = lastK; 
   if(!checkPalindrome(lastK1 , K+1)) answer = (answer + f(N-1 , (lastK1>>1)))%modbase;
    
   A[lastK][N] = answer;
   return answer; 
    
  
}



int main(){
   
    int T;
    cin>>T;
    
    while(T-->0){
    
       cin>>N>>K;
       
       
       if(K>N){
        cout<<(1<<N)<<endl;
        continue;
        }
       
       for(int i=0;i<1024;i++)
        for(int j=0;j<403;j++)
           A[i][j] = -1;
       
 
   	long long answer = 0;
  	 for(int lastK=0;lastK<(1<<K); lastK++) {
 //  	 	cout<<(bitset<10>)lastK<<" "<<checkPalindrome(lastK,K)<<endl;
       		answer = (answer + f(N,lastK))%modbase;
       } 
       
 /*
   for(int i=1;i<=N;i++){
  	 for(int lastK=0;lastK<(1<<K); lastK++) 
  	   cout<<A[lastK][N]<<" ";
  	 cout<<endl;
  }  
*/    
  cout<<answer<<endl;
    }
return 0;
}
