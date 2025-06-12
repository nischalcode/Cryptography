#include <iostream>
#include <string>
using namespace std;

string desEncrypt(string text, string key) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        result += text[i] ^ key[i % key.length()];
    }
    return result;
}

int main() {
    string text, key;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter key: ";
    cin >> key;
    string cipher = desEncrypt(text, key);
    cout << "Ciphertext (XOR-based): ";
    for (char c : cipher) cout << (int)c << " ";
    cout << endl;
    return 0;
}