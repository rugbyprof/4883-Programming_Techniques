## Problem UVa 11086 - Composite Prime. 

**Problem Summary**:
Given a number **`n`**, determine whether **`n`** is a composite prime number. A composite prime number is a composite number (non-prime) which, when factored, is only composed of prime numbers greater than or equal to a certain threshold (in the context of the problem, the threshold is a specific prime number).

**Abstract Approach**:

1. **Prime Sieve Initialization**:
   - Before processing the input numbers, construct a Sieve of Eratosthenes to efficiently check if a number is prime. This precomputation helps in speeding up prime checking during the actual processing of input numbers.

2. **Factorization**:
   - For each given number **`n`**, if it's less than the square of the threshold prime, then it's not a composite prime. This is because it cannot be the product of two primes both of which are greater than or equal to the threshold prime.
   - If **`n`** is greater than or equal to the square of the threshold prime, factorize **`n`** to get its prime divisors.
     - If **`n`** is a prime number itself, then it's not a composite prime. 
     - If all prime divisors of **`n`** are greater than or equal to the threshold prime, then **`n`** is a composite prime.
     - Otherwise, it's not.

3. **Output**:
   - For each **`n`**, after applying the above tests, output whether **`n`** is a composite prime or not.

**Considerations**:
- Precomputing the primes up to a certain limit using the Sieve of Eratosthenes significantly speeds up the process.
- For the factorization process, you only need to check up to the square root of **`n`** as potential divisors because if **`n`** has a divisor greater than its square root, it must also have one smaller than its square root.
  
The beauty of this problem lies in the application of number theory principles combined with computational optimization techniques. From a teaching perspective, it’s an excellent way to bridge theory with practical coding. If students can grasp the logic behind the sieve and efficient factorization, they'll be well-equipped to tackle a variety of number-theoretic problems in competitive programming.

### Walkthrough

Remember, a composite prime is a composite number (i.e., non-prime) such that when it's factored, it's only composed of prime numbers greater than or equal to a certain threshold prime. In this problem, the threshold prime is 2.

Given the input numbers `3,4,6,8`, let's assess each one:

1. **3**:
   - It's a prime number.
   - So, it's not a composite prime.
   
2. **4**:
   - It's a composite number.
   - Prime factorization: `4 = 2 * 2 `.
   - Both prime factors (which are 2) are equal to the threshold prime.
   - Thus, 4 is a composite prime.
   
3. **6**:
   - It's a composite number.
   - Prime factorization: `6 = 2 * 3`.
   - The prime factors are 2 and 3. While 3 is greater than the threshold, 2 is equal to it.
   - Thus, 6 is also a composite prime.

4. **8**:
   - It's a composite number.
   - Prime factorization: `8 = 2 * 2 * 2`.
   - All prime factors (which are 2) are equal to the threshold prime.
   - However, remember, for the number to be a composite prime, it must be the product of **two** primes greater than or equal to the threshold. So, since 8 is a product of three 2s, it doesn't count as a composite prime.

From the above, the numbers **4** and **6** from the input `3,4,6,8` are composite primes. Thus, the result is indeed two composite primes.

## Prime Factorization

Factoring a number into two prime numbers is a central problem, especially in the context of RSA encryption where the security is based on the difficulty of factoring a large semiprime (a number that's the product of two prime numbers) back into its constituent primes. 

Here are some strategies to factor a number into two primes:

1. **Brute Force**:
   - Start from the smallest prime (i.e., 2) and divide the given number.
   - If it divides evenly, check if the quotient is also prime.
   - This method is very slow and is impractical for large numbers.

2. **Pollard's rho algorithm**:
   - A probabilistic factorization algorithm, which outputs one non-trivial factor of the number.
   - This algorithm is particularly effective on numbers with small factors.
   - If the found factor is prime, then the quotient will be the other prime factor.

3. **Fermat's Factorization Method**:
   - Based on the representation of an odd integer as the difference of two squares.
   - For a number **`n`**, try to express it as **`n = a^2 - b^2`**.
   - If such **`a `** and **`b `** are found, then **`n`** can be factored as **`(a+b)(a-b) `**.
   - It's efficient if the two prime factors of **`n`** are close to each other.

4. **Quadratic Sieve**:
   - One of the fastest known algorithms for factoring large numbers.
   - It's based on the principle of Fermat's method but uses quadratic forms.
   - More efficient than Fermat's method, especially for semiprimes.

5. **Elliptic Curve Factorization**:
   - Uses properties of elliptic curves to find factors.
   - Can be faster than quadratic sieve for numbers of certain sizes.

6. **General Number Field Sieve (GNFS)**:
   - The most efficient known method to factor very large numbers.
   - Highly complex and involves both algebraic number theory and lattice basis reduction.

7. **Special Number Field Sieve (SNFS)**:
   - A variant of GNFS but is efficient for numbers that have a special form.

For many applications, a combination of the above methods is used. For instance, trial division might be used to quickly identify small factors, after which a more complex algorithm like the quadratic sieve or elliptic curve factorization is employed for the larger factors.

When factoring a number known to be a product of two primes (like in RSA), once one prime is found, the other can be quickly determined by a simple division. However, factoring such numbers becomes computationally difficult as the numbers increase in size, which is why it's used as the foundation for cryptographic security in systems like RSA.


## Factorization Implementation
A C++ function to factorize relatively small numbers into their prime factors:

```cpp
#include<iostream>
using namespace std;

vector<int> primeFactorization(int n) {
    vector<int> factors;

    // Extract all the 2s
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Now n must be odd, so we can skip one element (note i = i +2)
    for (int i = 3; i <= sqrt(n); i += 2) {
        // While i divides n, add i to the list and divide n
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n becomes a prime number greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

int main() {
    int num = 315;  // Example number for factorization
    vector<int> factors = primeFactorization(num);
    
    cout << "Prime factors of " << num << " are: ";
    for (int factor : factors) {
        cout << factor << " ";
    }

    return 0;
}
```

In this function, we first handle the smallest prime, `2`, and then move on to odd numbers. We only need to check up to the square root of `n` because, by that point, if `n` has no divisors, then `n` itself is prime. This approach efficiently factorizes numbers, especially when they are relatively small.

This function returns a vector containing the prime factors. If a prime divides the number multiple times, that prime will appear multiple times in the vector (e.g., for 12, the vector will contain `2, 2, 3`).

This code should work efficiently for "relatively small numbers", but remember that for very large numbers or for a huge number of factorization operations, more sophisticated techniques or optimizations would be needed.