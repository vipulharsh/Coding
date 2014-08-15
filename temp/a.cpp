#include <iostream>
using namespace std;

void ab(int &a){
	cout<<a<<endl;
	a = 2;
}


int main(){
	int *x = new int;
	*x = 1;
	ab(*x);
	cout<<*x<<endl;
	return 0;
	}
