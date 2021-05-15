// Normal algorith of Sieve Of Eratosthenes has time complexity O(n log(log(n)))
// because any number is accessed the its count of divisors time
// this modified algorith is O(n) and access every number ones
// This algorithm is copied from gfg link : https://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/

// O(n) but takes more space than normal method

#include<bits/stdc++.h> 
using namespace std; 


// function generate all prime number less then N in O(n) 
void manipulated_seive(int n, vector<bool> &isprime, vector<int> &prime, vector<int> &SPF)
{
	isprime[0] = isprime[1] = false ; 

	for (int i=2; i < n ; i++) {
		if (isprime[i]) { 
			prime.push_back(i); 
			SPF[i] = i; 
		}

		// Remove all multiples of i*prime[j] which are 
		// not prime by making isprime[i*prime[j]] = false 
		// and put smallest prime factor of i*Prime[j] as prime[j] 
		// [ for exp :let i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ] 
		// so smallest prime factor of '10' is '2' that is prime[j] ] 
		// this loop run only one time for number which are not prime 
		for (int j=0; j < prime.size() && i*prime[j] < n && prime[j] <= SPF[i]; j++){ 
			isprime[i*prime[j]]=false; 
			SPF[i*prime[j]] = prime[j] ;   // put smallest prime factor of i*prime[j] 
		} 
	} 
} 

int main() 
{ 
	int n = 100 ; // output wont include 13
	vector<bool> isprime(n, true);
	vector<int> prime;
	vector<int> SPF(n); // if not needed move inside function
	manipulated_seive(n, isprime, prime, SPF);

	// SPF[] that store smallest prime factor of number 
	// [for Exp : smallest prime factor of '8' and '16' 
	// is '2' so we put SPF[8] = 2 , SPF[16] = 2 ] 
	return 0; 
}
