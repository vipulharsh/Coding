#include <iostream>
using namespace std;

inline int max(int a, int b){
	return ((a>b)? a : b);
}

int main(){
	
	int N;
	cin>>N;
	int A[100001];
	for(int i=0;i<N;i++)
		cin>>A[i];
		
	int flag = 0;
	int product;
	int answer = 0;
	for(int i=0;i<N;i++){
		if(A[i] == 0){
			flag = 0;
			continue;
		}
		
		if(flag == 0){
			product = 1;
			flag = 1;
		}
		
		else{
			product++;
		}
		answer = max(product, answer);
	}
	cout<<answer<<endl;
	
	return 0;
}
