#include <iostream>
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

int gcdExtended(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int gcd = gcdExtended(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int g = gcdExtended(a, m, x, y);
    return (x % m + m) % m;
}

int main() {
    int p = 61, q = 53;
    long long n = p * q, phi = (p - 1) * (q - 1), e = 17;
    int d = modInverse(e, phi);
    long long m;
    cout << "Enter message (number < " << n << "): ";
    cin >> m;
    long long c = power(m, e, n);
    long long decrypted = power(c, d, n);
    cout << "Ciphertext: " << c << endl;
    cout << "Decrypted: " << decrypted << endl;
    return 0;
}