#include <iostream>
#include <cstdlib>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}

bool millerTest(long long d, long long n) {
    long long a = 2 + rand() % (n - 4);
    long long x = power(a, d, n);
    if (x == 1 || x == n - 1) return true;
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == 1) return false;
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(long long n, int k = 5) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (int i = 0; i < k; i++) {
        if (!millerTest(d, n)) return false;
    }
    return true;
}

int main() {
    long long n;
    cout << "Enter number: ";
    cin >> n;
    if (isPrime(n)) cout << "Prime" << endl;
    else cout << "Not Prime" << endl;
    return 0;
}