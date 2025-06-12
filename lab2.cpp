#include <iostream>
#include <string>
using namespace std;

string caesarCipher(string text) {
    string result = "";
    for (char c : text) {
        if (isupper(c)) {
            result += (char)(((c - 'A' + 3) % 26) + 'A');
        } else if (islower(c)) {
            result += (char)(((c - 'a' + 3) % 26) + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    string cipher = caesarCipher(text);
    cout << "Ciphertext: " << cipher << endl;
    return 0;
}