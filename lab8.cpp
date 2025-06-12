#include <iostream>
using namespace std;

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
    if (g != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    int a, m;
    cout << "Enter number and modulus: ";
    cin >> a >> m;
    int inverse = modInverse(a, m);
    if (inverse == -1) cout << "No inverse exists" << endl;
    else cout << "Inverse: " << inverse << endl;
    return 0;
}