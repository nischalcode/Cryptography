#include <iostream>
using namespace std;

int totient(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) n /= i;
            result = result * (i - 1) / i;
        }
    }
    if (n > 1) result = result * (n - 1) / n;
    return result;
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;
    cout << "Totient: " << totient(n) << endl;
    return 0;
}