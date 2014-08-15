#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

int N,P,K;
int A[100001];
int B[100001];
int r[100001];
	
	
int findIndex(int x){
	
	int l = 0;
	int h = N-1;
	int mid;
	
	
	while(l<=h){
		
		mid = (l+h)/2;
		if(B[mid] == x) return mid;
		
		if(B[mid] > x) h = mid-1;
		else l = mid+1;
	}
	
	assert(false);
	return -1;
}	
	
	
int main(){
	
	
	
	cin>>N>>K>>P;
	for(int i=0;i<N;i++){
		cin>>A[i];
		B[i] = A[i];
	}
	
	
	sort(B, B+N);
	
	
	r[0] = B[0] - K;
	
//	cout<<A[0]<<" "<<B[0]<<" "<<r[0]<<endl;
	
	for(int i=1;i<N;i++){
		if(B[i] <= (B[i-1]+K)) r[i] = r[i-1];
		else r[i] = B[i] - K;		
//		cout<<A[i]<<" "<<B[i]<<" "<<r[i]<<endl;
	}
	
	
	for(int i=0; i<P; i++){
		int a1, b1, a, b;
		cin>>a1>>b1;
		a = min(A[a1-1], A[b1-1]);
		b = max(A[a1-1], A[b1-1]);
//		cout<<b<<" -----> "<<findIndex(b)<<endl;		
		if(r[findIndex(b)] <= a) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}
