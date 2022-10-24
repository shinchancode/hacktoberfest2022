// Count Primes

// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
  
// Constraints:
// 0 <= n <= 5 * 106

int SieveOfEratosthenes(int n){
    int c=0;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p < n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p < n; p++)
        if (prime[p])
            c++;
    return c;
}
int countPrimes(int n) {
    return SieveOfEratosthenes(n);
}

// TIME COMPLEXITY: O(sqrt(N))
// AUXILIARY SPACE: O(N)
