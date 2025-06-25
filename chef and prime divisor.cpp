#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;

int sieve[1000000];

set<int> getsetofprimedivisors(const vector<int>& primes, int n){
    int sqrtn = sqrt(n);
    set<int> bdivisors;

    for(int i = 0; i < primes.size() && primes[i] <= sqrtn; i++){
        if(n % primes[i] == 0){
            bdivisors.insert(primes[i]);
            while(n % primes[i] == 0){
                n /= primes[i];
            }
            sqrtn = sqrt(n); // update after division
        }
    }

    if(n > 1){
        bdivisors.insert(n); // n is prime
    }

    return bdivisors;
}

int main(){
    for(int i = 0; i < 1000000; i++) sieve[i] = 0;
    sieve[0] = sieve[1] = 1;

    for(int i = 2; i * i < 1000000; i++){
        if(sieve[i] == 0){
            for(int j = i * i; j < 1000000; j += i){
                sieve[j] = 1;
            }
        }
    }

    vector<int> primes;
    for(int i = 2; i < 1000000; i++){
        if(sieve[i] == 0){
            primes.push_back(i);
        }
    }

    int a = 120, b = 75;
    set<int> all = getsetofprimedivisors(primes, b);

    vector<int> allDivisors(all.begin(), all.end());
    int flag=0;
    for(int i = 0; i < allDivisors.size(); i++){
    	if(a%allDivisors[i]!=0)
    	flag=1;
    	break;
        }
        
       cout << ((flag == 0) ? "YES" : "NO") << endl;


    return 0;
}

