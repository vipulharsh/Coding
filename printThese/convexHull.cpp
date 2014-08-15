//Area formed by the convex Hull of given points

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define twoD point

#define infi 1000000000


struct point{
	int x;
	int y;
	
void print() const{
	cout<<"("<<x<<","<<y<<")";	
}	
	
};

point basePoint;   //leftmost bottommost point

inline int crossProduct(twoD v1 , twoD v2){
	return (v1.x * v2.y - v2.x * v1.y);	
}

twoD AB(point A , point B){ //B - A
  twoD v;
  v.x = B.x - A.x;
  v.y = B.y - A.y;
  return v;
}


bool pointlt(const point& p1 , const point& p2) {     //point less than

	bool ret; 
        double angle1 ,angle2;
	if((p1.x == basePoint.x) && (p1.y == basePoint.y)) 	return true;
	if((p2.x == basePoint.x) && (p2.y == basePoint.y)) 	return false;

	if((p1.x- basePoint.x) == 0) angle1 = infi * (2 * (int)(p1.y > basePoint.y) - 1);
	else angle1 = (double) (p1.y - basePoint.y) / (double)(p1.x - basePoint.x) ;

	if((p2.x - basePoint.x) == 0) angle2 = infi * (2 * (int)(p2.y > basePoint.y) - 1); 
	else angle2 = (double) (p2.y - basePoint.y) / (double)(p2.x - basePoint.x) ;
	
	ret = (angle1 > angle2);
	if(angle1 == angle2) ret = p1.x + p1.y < p2.x + p2.y;
//	p1.print(); cout<<" "; p2.print(); cout<<" :"<<ret<<endl;
	return ret;
}




void findConvexHull(vector<point> points , vector<point> &convexHull){
	
	point minPoint = points[0];
	for(int i=1;i<points.size();i++){
		if((points[i].x < minPoint.x) || ((points[i].x ==minPoint.x) && (points[i].y < minPoint.y)))
		    minPoint = points[i];
	}
	
   cout<<"Base point is "; 
   basePoint = minPoint;
   basePoint.print();
   cout<<endl<<"----------------------"<<endl;
	
   sort(points.begin() , points.end() , pointlt);
	
	for(int i=0;i<points.size();i++){
		points[i].print();
		cout<<endl;
	}
	 cout<<"-------------------------------"<<endl;
	convexHull.push_back(points[0]);
	
	int nPoints = points.size();
	twoD curr_vec;// =  AB(points[0] , points[1]);
	point last_point;//  = points[1];
	//convexHull.push(points[1]);
	
	int i = 1;
	while(i < nPoints){
//		curr_vec.print(); last_point.print(); cout<<endl;
	   if(convexHull.size()<2){
		   curr_vec = AB(points[0] , points[i]);
		   last_point = points[i];
		   convexHull.push_back(points[i]);
		   i++;
		   continue;
		}
	
	   if(crossProduct(AB(last_point , points[i]) , curr_vec) > 0) { //all's well
			convexHull.push_back(points[i]);
			curr_vec = AB(last_point , points[i]);
			last_point = points[i];
			i++;
	        continue;
		}
	
	  else{
		convexHull.pop_back();
		last_point = convexHull.back();
		curr_vec = AB(convexHull[convexHull.size() -2] , convexHull[convexHull.size() - 1]);
	    continue; 
	  } 	
   }
}



int main(){
    
    vector<point> points;
    int N;
    cin>>N;
    point p;
    for(int i=0;i<N;i++){
		cin>>p.x; cin>>p.y;
		points.push_back(p);
	}
	vector<point> convexHull;
	findConvexHull(points , convexHull);
	for(int i=0;i<convexHull.size();i++){
		convexHull[i].print();
		cout<<endl;
	}
 	return 0;
}
