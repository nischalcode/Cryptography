#include <iostream>
#include <string>
using namespace std;

string vigenereCipher(string text, string key) {
    string result = "", k = "";
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        k += key[j % key.length()];
        j++;
    }
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += (char)(((text[i] - 'A' + (k[i] - 'A')) % 26) + 'A');
        } else if (islower(text[i])) {
            result += (char)(((text[i] - 'a' + (k[i] - 'A')) % 26) + 'a');
        } else {
            result += text[i];
        }
    }
    return result;
}

int main() {
    string text, key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;
    string cipher = vigenereCipher(text, key);
    cout << "Ciphertext: " << cipher << endl;
    return 0;
}