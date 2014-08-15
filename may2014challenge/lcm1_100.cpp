#include <iostream>
using namespace std;

long long int gcd(long long int x, long long int y){
	return ((x < y)? gcd(y, x) : (y == 0)? x : gcd(y, x%y));
}



int main(){


	long long int lcm = 1;
	for(int i=1;i<43;i++){
		lcm = (lcm * (long long)i)/gcd(lcm, i);
	}


	cout<<lcm<<endl;
	return 0;
}
