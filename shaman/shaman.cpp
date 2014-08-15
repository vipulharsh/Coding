#include <iostream>
#include <vector>
#include <algorithm>
#include <assert.h>
using namespace std;

#define infiSlope 20000

struct point{
	int x;
	int y;
	void input(){
		cin>>x>>y;
	}
	void output(){
		cout<<"("<<x<<","<<y<<")";
	}
	bool operator==(point& p2)const{
		return ((x == p2.x) && (y == p2.y));
	}


};



#define vecAB point


inline vecAB AB(point A, point B){

	vecAB ret;
	ret.x = B.x - A.x;
	ret.y = B.y - A.y;
	return ret; 
}


inline int crossProduct(vecAB a, vecAB b){

	return  ((a.x * b.y) - (a.y * b.x));
}

inline int dotProduct(vecAB a, vecAB b){

	return  ((a.x * b.x) + (a.y * b.y));
}


point points[2000];
vector<point> convexHull;
int N;
point basePoint;


//p2 is the first point
inline double slope(point p1, point p2){
	
	double ret = (p1.x == p2.x)? infiSlope : ((double)(p1.y - p2.y))/(p1.x - p2.x) ;
	if((p1.x == p2.x) && (p2.y > p1.y)) ret = -infiSlope; 
	return ret;
}


bool myoperator(point p1, point p2){
	
	if(p1 == basePoint) return true;
	if(p2 == basePoint) return false;
	
	
/*	
	if((p1.x == p2.x) && (p1.x == basePoint.x))
		return (p1.y < p2.y);
*/

	
	double m1 = slope(p1, basePoint);
	double m2 = slope(p2, basePoint);
	
//	if(m1 != m2)
	return (m1 > m2);
		
//	int val1 = p1.x + p1.y; 	
//	int val2 = p2.x + p2.y; 	
//	return (val1 < val2);
}



void findConvexHull(){  //assumes the points to be accordingly sorted
	
	assert(basePoint == points[0]);
	convexHull.push_back(points[0]);
	vecAB last;
	int i=1;
	while(i<N){
		
		vecAB curr =  AB(convexHull.back(), points[i]);
		
		if((crossProduct(last, curr) == 0) && dotProduct(last, curr)<0){
			i++;
			continue;
		}
		
		while((crossProduct(last, curr)>=0) && (convexHull.size()>1)){
			convexHull.pop_back();
			int cHsize = convexHull.size();
			curr = AB(convexHull.back(), points[i]);
			if(cHsize>1)
				last = AB(convexHull[cHsize-2], convexHull[cHsize-1]);
		}
		last = AB(convexHull.back(), points[i]);
		convexHull.push_back(points[i]);
		i++;
	}
}
	
	
	
	
	
	
	
	
	




int main(){
	
	int T;
	cin>>T;
	
	while(T-->0){
		cin>>N;
		for(int i=0;i<N;i++)
			points[i].input();
		
		basePoint = points[0];	
		for(int i=1;i<N;i++){
			if(points[i].x < basePoint.x)
				basePoint = points[i];
				
			if(points[i].x == basePoint.x)
				basePoint.y = min(basePoint.y, points[i].y);
		}
		
		sort(points, points+N, myoperator);
		for(int i=0;i<N;i++){
			points[i].output();
			cout<<endl;
		}
		
		cout<<"***************"<<endl;
		
		
		findConvexHull();
		
		int l = convexHull.size();
		for(int i=0;i<l;i++){
			convexHull[i].output();
			cout<<endl;
		}
		 	
	}
	return 0;
}
