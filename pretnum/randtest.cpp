#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;




#define ll long long
 







int main(){

	
	int i;
	for(int i=0;i<1000000;i++){
		if(!(i%2&&i%3&&i%5&&i%7&&
				i%11&&i%13&&i%17&&i%19&&i%23&&i%29&&
				i%31&&i%37&&i%41&&i%43&&i%47&&i%53&&
				i%59&&i%61&&i%67&&i%71&&i%73) && (i>73)) continue;
		Fermat((long long)i,5);
	//	i = rand()%10;
	}
	return 0;
}
