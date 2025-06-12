#include <iostream>
#include <string>
using namespace std;

string railfenceCipher(string text, int rails) {
    char fence[rails][100];
    for (int i = 0; i < rails; i++) for (int j = 0; j < 100; j++) fence[i][j] = '\0';
    int row = 0, col = 0, dir = 0; // 0 = down, 1 = up
    for (char c : text) {
        fence[row][col++] = c;
        if (row == 0) dir = 0;
        else if (row == rails - 1) dir = 1;
        row += (dir == 0) ? 1 : -1;
    }
    string result = "";
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < 100; j++) {
            if (fence[i][j] != '\0') result += fence[i][j];
        }
    }
    return result;
}

int main() {
    string text;
    int rails;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter number of rails: ";
    cin >> rails;
    string cipher = railfenceCipher(text, rails);
    cout << "Ciphertext: " << cipher << endl;
    return 0;
}