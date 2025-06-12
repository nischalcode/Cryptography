#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    if (areCoprime(a, b)) cout << "Coprime" << endl;
    else cout << "Not Coprime" << endl;
    return 0;
}