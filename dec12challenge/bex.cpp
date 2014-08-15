#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;


struct book{
	char name[15];
	int exercises;
	int minExercises;
};



int main(){
	
	stack<book> books;
	book top;
	int N, action;
	scanf("%d", &N);
	while(N-->0){
		scanf("%d", &action);
		if(action != -1){
			book B;
			scanf("%s",B.name);
			if(action == 0) continue;
			B.exercises = action;
			B.minExercises = action;
			if(!books.empty()){
				B.minExercises = min(books.top().minExercises, action);
			}
			books.push(B);
		}
		else{
			int minex = books.top().minExercises;
			int count=0;
			while(books.top().exercises != minex){
				books.pop();
				count++;
			}
			printf("%d %s\n", count, books.top().name);
			books.pop();
		}
	}
	return 0;
}
