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

struct segment{
	
	short int val[12];
	short int nRotations; //number of pending rotations
	int left;
	int right;
};


inline int nDigits(int elm){
	
	if(elm==0) return 0;
	if(elm/10==0) return 1;
	if(elm/100==0) return 2;
	if(elm/1000==0) return 3;
	if(elm/10000==0) return 4;
}


int tenpowers[5] = {1, 10, 100, 1000, 10000}; 

inline int findVal(int elm, int rotations, int d){
	
	if(d!=0) rotations = rotations%d;
	if(rotations == 0 || d==0) return elm;
	
	int tenPowerDr = tenpowers[d-rotations];
	int tenPowerd = tenpowers[rotations];
	
	return ((elm%tenPowerDr)*tenPowerd) + (elm/tenPowerDr);
}



int N;
short int *A;
segment *sTree;


void initialize(int L, int R, int index){
	
	sTree[index].left = L;
	sTree[index].right = R;
	sTree[index].nRotations = 0;
	if(L==R){
		sTree[index].val[0] = A[L];
		int d = nDigits(A[L]);
		for(int i=1;i<12;i++)
			sTree[index].val[i] = findVal(A[L], i, d);
	}
	else{
		initialize(L, (L+R)/2, (2*index)+1);
		initialize((L+R)/2 + 1, R, (2*index)+2);
		for(int i=0;i<12;i++)
			sTree[index].val[i] = max(sTree[(2*index)+1].val[i], sTree[(2*index)+2].val[i]);
	}
}



void update(int L, int R, int index, int rotations){
	
	if((sTree[index].right < L) || (sTree[index].left > R)){   //Out of Range
		return;
	}

	if((sTree[index].left == L) && (sTree[index].right == R)){
		sTree[index].nRotations = (sTree[index].nRotations + rotations)%12;  //Pending Rotations
		return;
	}
	
	int leftChild = (2*index) + 1;
	int rightChild = (2*index) + 2;
	
	update(L, min(sTree[leftChild].right, R), leftChild,  rotations);
	update(max(L,  sTree[rightChild].left), R, rightChild, rotations);

	for(int i=0;i<12;i++)
		sTree[index].val[i] = max(sTree[leftChild].val[(i+sTree[leftChild].nRotations)%12],
								  sTree[rightChild].val[(i+sTree[rightChild].nRotations)%12]);
}



int query(int L, int R, int index, int parentRotation){
	
	if((sTree[index].right < L) || (sTree[index].left > R)) return -1;
	
	if((sTree[index].left == L) && (sTree[index].right == R)){
		return sTree[index].val[(sTree[index].nRotations + parentRotation)%12];
	}
	
	int leftChild = (2*index) + 1;
	int rightChild = (2*index) + 2;
	
	int a1 = query(L, min(sTree[leftChild].right, R), leftChild, sTree[index].nRotations + parentRotation) ; 
	int a2 = query(max(L,  sTree[rightChild].left), R, rightChild, sTree[index].nRotations + parentRotation);
	return max(a1, a2);
}



void print(int L, int R, int index, int spaces){
	
	for(int i=0;i<spaces;i++)
		cout<<" ";

	cout<<"(";
	for(int i=0;i<12;i++)
		cout<<sTree[index].val[i]<<",";
	
	cout<<":::"<<sTree[index].nRotations<<")"<<endl;	
	if(L<R){
		print(L, sTree[2*index + 1].right, 2*index + 1, spaces+1);
		print(sTree[2*index + 2].left, R, 2*index + 2, spaces+1);
	}	
}




int main(){
	
	in(N);
	
	A = new short int[N];
	sTree = new segment[3*N+1];

	
	int M,tempelm;
	for(int i=0;i<N;i++){
		in(tempelm);
		A[i] = tempelm;
	}
	
	
	initialize(0, N-1, 0);
	
	scanf("%d", &M);	
	for(int i=0; i<M; i++){
		int type,l,r,f;
		in(type);
		in(l);
		in(r);	
		if(type == 0){
			in(f);
			update(l,r,0,f);
		}
		else if(type == 1){
			printf("%d\n", query(l, r, 0, 0));
		}
	}		
	return 0;
}	
		
	
	
	
