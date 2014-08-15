#include <iostream>
using namespace std;
int main(){

	long double pa;
	int T;
	cin>>T;
	while(T-->0){
		cin>>pa;
		int t;
		t = ((2*pa - 1)>0)? 10000 : 0;
		cout.precision(6);
		cout.setf(ios::fixed, ios::floatfield );
		cout<<10000 + (((long double)t * (2 *pa - 1)) + (10000  * pa * (1 - (2 * pa))))<<endl;		
	}
	return 0;
}
