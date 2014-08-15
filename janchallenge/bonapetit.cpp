#include <iostream>
#include <algorithm>
#include <set>
using namespace std;


int N,K;


struct customer{
	int f;
	int s;
	int p;

	
};


bool operator<(const customer &a , const customer &b) {	
   return (a.s < b.s);
}

int main(){
	
	int T;
	cin>>T;
	
	
	customer *customers = new customer[100001];
	
	while(T-->0){
		cin>>N>>K;
		for(int i=0;i<N;i++){
			cin >> customers[i].s >> customers[i].f >> customers[i].p;
		}
		
		sort(customers , customers + N) ;
			
		
		
		
	}


return 0;
}
