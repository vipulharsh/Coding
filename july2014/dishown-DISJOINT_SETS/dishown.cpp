#include <iostream>
#include <stdio.h>
using namespace std;


inline void in(int &x) {
    register int c = getchar_unlocked();
    x = 0;
    int neg = 0;
	for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked()); 
    if(c=='-') {
        neg = 1;
        c = getchar_unlocked();
    } 
    for(; c>47 && c<58 ; c = getchar_unlocked()) {
        x = (x<<1) + (x<<3) + c - 48;
    } 
    if(neg)
        x = -x;
}

struct chef;
struct dish;

struct chef{
	
	int chefID;
	int nDishes;
	int bestDish;
	dish *top;
};



struct dish{
	dish *next;
	int chefID;
	int score;
};


dish dishes[10001];
chef chefs[10001];


inline int getChef(int dishnum){

	return chefs[dishes[dishnum].chefID].chefID;
}




inline void append(int chef1, int chef2, int winner){
	
	int totalDishes =  chefs[chef1].nDishes +  chefs[chef2].nDishes;
	
	dish *t = chefs[chef2].top;
	dish *previous;
	while(t != NULL){
		t->chefID = chef1;
		previous = t;
		t = t->next;
	}
	
	previous->next = chefs[chef1].top; 
	chefs[chef1].top = chefs[chef2].top;
	chefs[chef1].nDishes = totalDishes;
	chefs[chef1].bestDish = chefs[winner].bestDish;
	chefs[chef1].chefID = chefs[winner].chefID;
}









int compete(int dish1, int dish2){
	

	chef chef1 = chefs[dishes[dish1].chefID];
	chef chef2 = chefs[dishes[dish2].chefID];

	if(chef1.chefID == chef2.chefID)
		return -1;
	if(chef1.bestDish == chef2.bestDish){
		return 0;
	}
	
	int winner = (chef1.bestDish > chef2.bestDish)? dishes[dish1].chefID : dishes[dish2].chefID;
	if(chef1.nDishes > chef2.nDishes)
		append(dishes[dish1].chefID, dishes[dish2].chefID, winner);
	else
		append(dishes[dish2].chefID, dishes[dish1].chefID, winner);
		
	return 1; 
}





int main(){
	
	int T,N,Q;
	in(T);
	while(T-->0){
		in(N);
		for(int i=0;i<N;i++){
			in(dishes[i].score);
			dishes[i].chefID = i;
			dishes[i].next = NULL;
			chefs[i].nDishes = 1;
			chefs[i].bestDish = dishes[i].score;
			chefs[i].chefID = i;
			chefs[i].top = &(dishes[i]);
		}
		in(Q);
		int type,x,y;
		for(int i=0;i<Q;i++){
			in(type);
			in(x);
			if(type==0){
				in(y);
				int res = compete(x-1, y-1);
				if(res == -1)
					printf("Invalid query!\n");
			}
			else{
				printf("%d\n", getChef(x-1) + 1);
			}
		}
	}
	
	
	return 0;
}
