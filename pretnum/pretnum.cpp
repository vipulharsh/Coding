#include <iostream>
#include <vector>
using namespace std;

#define NCHECKPRIMES 13
int primes[NCHECKPRIMES] = {3,5,7,11,13,17,19,23,29,31,37,41,43};

vector<long long> primes1n;

vector<long long> genPrime1n(long long n){
	
	vector<long long> primes;
	vector<bool> potentialPrimes;
	for(long long i=0; i<=n;i++){
		potentialPrimes.push_back(true);
	}
	
	long long  currIndex = 2;
	while(currIndex<=n){
		if(potentialPrimes[currIndex]){
			for(long long k = currIndex * 2; k<=n; k += currIndex)
				potentialPrimes[k] = false;
		}	
		currIndex++;
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

	long long j;
	vector<long long>::iterator it;
	for(it = primes1n.begin(); it!=primes1n.end(); it++){
		j = (*it);
		if((j*j) > R) break;
		long long first = (((L-1)/j) * j) + j; //first multiple of j in [L,R] 
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
	
	int T;
	cin>>T;
	int primeDivisors;
	primes1n = genPrime1n(1000000);
	long long L,R;
	while(T-->0){
		cin>>L;
		cin>>R;
		primeDivisors = 0;
		vector<long long>::iterator it;
		for(it=primes1n.begin();it!=primes1n.end();it++){
			long long i = *it;
			int exp = 0;
			int prev_exp = 0;
			int curr_exp;
			long long curr = 1;
			bool overflow = false;
			while(exp<NCHECKPRIMES){
				curr_exp = primes[exp]-1;
				while(prev_exp < curr_exp){
					curr = curr * i;
					prev_exp++;
					if(curr > (long long)1<<40)
						overflow = true;
				}
				if(curr > R || overflow) break;
				if((curr >= L) && (curr <= R)){
					primeDivisors++;
				}
				exp++;
			}
		}
		primeDivisors += genPrime(L,R).size();
		cout<<primeDivisors<<endl;
	}
	return 0;
}
