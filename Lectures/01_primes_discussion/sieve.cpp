#include <iostream>

using namespace std;

const int MAXN = 1048576;  // 2^20
bool isPrime[MAXN];

void sieve() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[0] = isPrime[1] = false;  // 0 and 1 are not prime numbers
    for(int i = 2; i*i < MAXN; i++) {
        if(isPrime[i]) {
            for(int j = i*i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    sieve();
    int primecnt = 0;
    // Now isPrime[i] will be true if i is prime, and false otherwise.
    for(int i = 2; i < MAXN; i++) {  // Just printing primes less than 100 as an example.
        if(isPrime[i]) {
            primecnt++;
            
        }
    }
    cout << primecnt << " ";

    
    return 0;
}
