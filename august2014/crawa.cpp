#include <iostream>
#include <stdio.h>
using namespace std;




int main(){
	
	int T,X,Y;
	scanf("%d", &T);
	while(T-->0){
		scanf("%d", &X);
		scanf("%d", &Y);
		
		bool answer = false;
		if(Y<=0 && Y%2==0){
			if(X>=Y && X<=((-Y) + 1))
				answer = true;
		}
		
		if(X>0 && X%2==1){
			if(Y>=((-X)+1) && Y<=(X+1))
				answer = true;
		}
		
		if(Y>0 && Y%2==0){
			if(X<=(Y-1) && (X>=-Y))
				answer = true;
		}
		
		if(X<0 && X%2==0){
			if(Y>=X && Y<=-X)
				answer=true;
		}
		
		
		//cout<<X<<" "<<Y<<" : ";
		if(answer)
			printf("YES\n");
		else	
			printf("NO\n");
	}
	return 0;
}
