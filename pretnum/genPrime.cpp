#include <iostream>
#include <vector>
#include <list>
#include <math.h>
using namespace std;



vector<long long> genPrime1n(long long n){
	
	
	vector<long long> primes;
	vector<bool> potentialPrimes;
	
	for(long long i=0; i<=n;i++){
		potentialPrimes.push_back(true);
	}
	
	long long limit = sqrt(n) + 1;
	for(long long currIndex = 2;currIndex<=limit; currIndex++){
		if(potentialPrimes[currIndex]){
			for(long long k = currIndex * currIndex; k<=n; k += currIndex)
				potentialPrimes[k] = false;
		}
	}
	
	for(long long i=2; i<=n;i++){
		if(potentialPrimes[i])
			primes.push_back(i);
	}
	return primes;
}





vector<long long> genPrime(long long L, long long R){
	
	if(L == 1) L++;
	
	vector<long long> primes;
	vector<bool> potentialPrimes;
	
	for(long long i=L; i<=R;i++){
		potentialPrimes.push_back(true);
	}
	
	long long j = sqrt(R) + 1;
	
	vector<long long> primes1n = genPrime1n(j);
	vector<long long>::iterator it;
	for(it = primes1n.begin(); it!=primes1n.end(); it++){
		j = (*it);
		long long first = ((L/j) * j) + (j * (L%j != 0)); //first multiple of j in [L,R] 
		if(first == j) first += j;
		for(long long k = first; k <= R; k += j)
			potentialPrimes[k-L] = false;
	}
	
	
	for(long long i=L; i<=R; i++){
		if(potentialPrimes[i-L])
			primes.push_back(i);
	}
	return primes;
}


int main(){

	vector<long long> primes = genPrime1n(100000);
	vector<long long>::iterator it;

	int count=0;
	for(it = primes.begin(); it!= primes.end(); it++){
		cout<<(*it)<<endl;
		count++;
	}
	cout<<count<<endl; 
	return 0;
}
