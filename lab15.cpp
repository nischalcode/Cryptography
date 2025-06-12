#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("malicious.txt");
    if (!file) {
        cout << "File error" << endl;
        return 1;
    }
    long long i = 0;
    while (true) {
        file << "Malicious data " << i++ << endl;
        if (i % 1000000 == 0) cout << "Written " << i << " lines" << endl;
    }
    file.close();
    return 0;
}