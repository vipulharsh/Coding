#include <iostream>
using namespace std;

#define MODBASE 1000000007
#define inverseFactorialMod800000 984388797

int *factorialMod;
int *invFactorialMod;
//int factorialMod[800001];
//int invFactorialMod[800001];

void preProcess(){
	
	factorialMod[0] = 1;
	for(int i=1;i<800001;i++){
		factorialMod[i] = ((long long) factorialMod[i-1] * i)%MODBASE;
	}
	invFactorialMod[800000] = inverseFactorialMod800000;
	for(int i=800000-1; i>=0; i--){
		invFactorialMod[i] = ((long long) (i+1) * invFactorialMod[i+1])%MODBASE;
	}
	//cout<<factorialMod[800000]<<" : "<<invFactorialMod[2]<<endl;	
}


inline int choose(int N, int M){
	return (((long long) factorialMod[N] * invFactorialMod[M])%MODBASE * (long long) invFactorialMod[N-M])%MODBASE;	
}



int main(){
	factorialMod = new int[800001];
	invFactorialMod = new int[800001];
	preProcess();
	int R;
	cin>>R;
	while(R-->0){
		int N,M,A,B;
		cin>>N>>M>>A>>B;
		int ans = 0;
	
		for(int k=0; k<=M-B; k++){
			if(k == M-B)
				ans = (ans + (long long) choose(A+k, k) * choose(N+M-(A+k), M-k))%MODBASE;
			else
				ans = (ans + (long long) choose(A+k, k) * choose(N+M-(A+k+1), M-k))%MODBASE;
		} 		
		cout<<ans<<endl;
	}
	return 0;
}

