#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

//#define NDEBUG

#include <assert.h>
using namespace std;

struct Hsegment{  //Horizontal segments
	int rectangleNum;
	double x1 , x2;
	bool start;
	double y;	

void print() const{
	 
	cout<<"("<<rectangleNum<<","<<x1<<","<<x2<<","<<y<<","<<start<<")"<<endl;
	
}

};





struct intPair{
	int segmentNo;
	int x;
};

bool operator<(intPair &p1 , intPair &p2){
	return (p1.x < p2.x);
};


bool lty(const Hsegment &s1 , const Hsegment &s2){
	return ((s1.y < s2.y) || ((s1.y == s2.y) && (s1.x1 < s2.x1)));
}

bool operator<(const Hsegment &s1 , const Hsegment &s2){   //equality if the x1's are equal
	return (s1.x2 < s2.x2);
}

void findResults(vector<Hsegment> &segments , int *results){
	assert(segments.size()%2 == 0) ;
	int Nrectangles = segments.size()/2;
	set<Hsegment> setx; 
	setx.insert(segments[0]);
	results[segments[0].rectangleNum] = -1;
	int curr = 1;
	while(curr < Nrectangles * 2){
			if(segments[curr].start) {   //nothing to be done
				set<Hsegment>::iterator it = setx.upper_bound (segments[curr]);
				
				if(it == setx.end()) results[segments[curr].rectangleNum] = -1; //No rectangle to the right
				
				else if((*it).x1 > segments[curr].x2) results[segments[curr].rectangleNum] = -1; //Rectangle completely to right
				
				else {
					assert((*it).x2 > segments[curr].x1);
					results[segments[curr].rectangleNum] = (*it).rectangleNum;	
				}
				
				setx.insert(segments[curr]);
				
				curr++;
				continue;
			}
			
		  assert(!segments[curr].start);
		  	set<Hsegment>::iterator it = setx.find(segments[curr]);
		    
		    assert(it != setx.end());
		    setx.erase(it);
		    curr++;

		}		    
}

int main(){

	int N;
	cin>>N;
	
	vector<Hsegment> segments;
	
	int *results = new int[N];
	
	Hsegment tempStart;
	tempStart.start = true;
	Hsegment tempEnd;
	tempEnd.start = false;
	
	
	for(int i=0;i<N;i++){
		cin>>tempStart.x1>>tempStart.y;
		cin>>tempEnd.x2>>tempEnd.y;
		
		tempEnd.x1 = tempStart.x1;
		tempStart.x2 = tempEnd.x2;
		
	    tempStart.rectangleNum = i;
	    tempEnd.rectangleNum = i;
		
		segments.push_back(tempStart);
		segments.push_back(tempEnd);
		
	}
	
	 
	sort(segments.begin() , segments.end() , lty);
	
	
/*	
	for(int i=0;i<2*N;i++){
		segments[i].print();		
	}
*/	 
	findResults(segments , results);
	
	
//	cout<<"----------------------"<<endl;
	for(int i=0;i<N;i++)
	  cout<<results[i]<<endl;
	
	
	return 0;
}

