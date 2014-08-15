#include <iostream>
using namespace std;
int N,M;

bool **A;
bool *where;

 




int main(){

A = new bool*[502];
where = new bool[502];

for(int i=0;i<502;i++)
  A[i] = new bool[502];



int T;
cin>>T;
int a,b;
while(T-->0){
	
	
	cin>>N>>M;
	
	
	
	for(int i=0;i<N;i++)
	 for(int j=0;j<N;j++)
	  A[i][j] = false;
	
	
	
	for(int i=0;i<M;i++){
	  cin>>a>>b;
	  A[a-1][b-1] = (A[b-1][a-1] = true);   
	}

       
 /*      
       for(int i=0;i<N;i++){
       
         for(int j=0; j<N;j++)
          cout<<A[i][j]<<" ";
         cout<<endl; 
       
       
       }
       
*/        
        
        bool done=false;
        
	for(int curr=0;curr<N;curr++){
	
	bool ans1=true;  //for independent set
	  
	   for(int g=0;g<N;g++){
	     if(g==curr || A[curr][g]) continue;
	     for(int h=g+1;h<N;h++){
	    
	       ans1 = ans1 && (!(A[g][h]) || (h==curr) || (A[curr][h])); 
	     
	    } 
	 }
	      
	      
//	   cout<<"ans1 is"<<ans1<<" curr : "<<curr<<endl;   
	  
	 bool ans2=true;  //for clique
	   for(int g=0;g<N;g++){
//	    cout<<"up mein ans 2 is "<<ans2<<endl;
	     if(g==curr || !A[curr][g]) continue;
	     for(int h=g+1;h<N;h++){
 
	       ans2 = ans2 && ((h==curr) || (!A[curr][h]) || (A[g][h])); 
	     
	    }
	  //    cout<<"here ans2 is: "<<ans2<<endl;  
	 
	 } 
	 
//	 cout<<"ans2 is"<<ans2<<endl;
	  
	  
	  if(ans1 && ans2){ cout<<"YES"<<endl; done=true; break;}
	  if((!ans1) &&  (!ans2)) { cout<<"NO"<<endl; done=true; break;}
	  
	  //ind is true
	  if(ans1){
	     where[curr] = 1; 
	  }
	  
	  else where[curr]= 0;
	  
      }
      
      if(done) continue;
      bool finalans=true;
      for(int c=0;c<N;c++){
          for(int v=0;v<N;v++)
            finalans = finalans && ((c==v) || (where[c]!= where[v]) || (where[c] && A[c][v]) || (!where[c] && !A[c][v]));
      }
	
    if(finalans) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;	
}
	 	
  


return 0;
}
