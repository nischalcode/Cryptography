#include <iostream>
#include <string>
using namespace std;

void generateKeyTable(string key, char table[5][5]) {
    bool used[26] = {false};
    int x = 0, y = 0;
    for (char c : key) {
        if (!used[toupper(c) - 'A'] && isalpha(c)) {
            table[x][y] = toupper(c);
            used[toupper(c) - 'A'] = true;
            y++;
            if (y == 5) { x++; y = 0; }
        }
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'J') continue;
        if (!used[c - 'A']) {
            table[x][y] = c;
            y++;
            if (y == 5) { x++; y = 0; }
        }
    }
}

string playfairCipher(string text, string key) {
    char table[5][5];
    generateKeyTable(key, table);
    string result = "", processed = "";
    for (char c : text) {
        if (isalpha(c)) processed += toupper(c);
    }
    for (int i = 0; i < processed.length(); i += 2) {
        if (i + 1 >= processed.length()) processed += 'X';
        if (processed[i] == processed[i + 1]) processed.insert(i + 1, "X");
        int r1, c1, r2, c2;
        for (int r = 0; r < 5; r++) {
            for (int c = 0; c < 5; c++) {
                if (table[r][c] == processed[i]) { r1 = r; c1 = c; }
                if (table[r][c] == processed[i + 1]) { r2 = r; c2 = c; }
            }
        }
        if (r1 == r2) {
            result += table[r1][(c1 + 1) % 5];
            result += table[r2][(c2 + 1) % 5];
        } else if (c1 == c2) {
            result += table[(r1 + 1) % 5][c1];
            result += table[(r2 + 1) % 5][c2];
        } else {
            result += table[r1][c2];
            result += table[r2][c1];
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
    string cipher = playfairCipher(text, key);
    cout << "Ciphertext: " << cipher << endl;
    return 0;
}