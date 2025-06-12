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

int main() {
    long long p, g, a, b;
    cout << "Enter prime p and base g: ";
    cin >> p >> g;
    cout << "Enter private key a: ";
    cin >> a;
    cout << "Enter private key b: ";
    cin >> b;
    long long A = power(g, a, p);
    long long B = power(g, b, p);
    long long keyA = power(B, a, p);
    long long keyB = power(A, b, p);
    cout << "Shared key: " << keyA << endl;
    return 0;
}