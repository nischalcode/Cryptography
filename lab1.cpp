#include <iostream>
#include <string>
using namespace std;

string shiftCipher(string text, int key) {
    string result = "";
    for (char c : text) {
        if (isupper(c)) {
            result += (char)(((c - 'A' + key) % 26) + 'A');
        } else if (islower(c)) {
            result += (char)(((c - 'a' + key) % 26) + 'a');
        } else {
            result += c;
        }
    }
    return result;
}

int main() {
    string text;
    int key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter shift key: ";
    cin >> key;
    string cipher = shiftCipher(text, key);
    cout << "Ciphertext: " << cipher << endl;
    return 0;
}