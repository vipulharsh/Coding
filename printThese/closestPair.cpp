#include <iostream>
#include <set>
#include <vector>
#include <assert.h>
#include <algorithm>
using namespace std;


struct point{
	double x;
	double y;
void print(){
	cout<<"("<<x<<","<<y<<")"; 	
}	
};


bool operator<(const point &p1 , const point &p2)  {
     return ((p1.y<p2.y) || ((p1.y == p2.y) && (p1.x < p2.x)));
} 

bool ltx(const point &p1 , const point &p2)  {
     return ((p1.x<p2.x) || ((p1.x == p2.x) && (p1.y < p2.y)));
}

inline double distance2(point p1 , point p2){ //distance square
     return ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));	
}


//assumes that points is sorted on x coordinate
pair<point , point> closestPair(vector <point> points){
	pair<point , point> ret;
	ret.first = points[0];
	ret.second = points[1];
	double currMin = distance2(points[0] , points[1]);
	int first_index = 0;
	set<point> sety; //sorted according to y coordinates.
	sety.insert(points[0]);
	sety.insert(points[1]);
	int curr_index = 2;
	while(curr_index < points.size()){
		assert(currMin > 0);
		while(currMin < (points[curr_index].x - points[first_index].x) * (points[curr_index].x - points[first_index].x)){
			sety.erase(sety.find(points[first_index]));
			first_index ++;			
		}
		point temp;
		temp.x = points[0].x;  // - infi basically (since ,  we need all points with y coordinates greater than temp.y)
		temp.y = points[curr_index].y - currMin;
		set<point>::iterator it = sety.lower_bound (temp);
		int count = 0; //compare only order 1 points
		while(count<8 && it!=sety.end()){  //random number 8
			if(distance2(*it , points[curr_index]) < currMin){
				currMin  = distance2(*it , points[curr_index]);
				ret.first = *it;
				ret.second = points[curr_index];		
			}
			count++;
			it++;
		}
		sety.insert(points[curr_index]);
		curr_index++;
	}
	return ret;
}



int main(){
	
	int N;
	vector <point> P;
	cin>>N;
	point temp;
	for(int i=0;i<N;i++){
		cin>>temp.x>>temp.y;
		P.push_back(temp);
	}
	sort(P.begin()  , P.end() , ltx); 
	
	for(int i=0;i<N;i++)
		P[i].print();
   cout<<"----------------------------"<<endl;
	pair <point,point> answer = closestPair(P);
	answer.first.print();
	answer.second.print();
	return 0;	
}
