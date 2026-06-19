#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void generate_key(const string &text, const string &key, string &new_key) {
    int key_len = key.length();
    new_key = "";

    for (int i = 0, j = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            new_key += key[j % key_len];
            j++;
        } else {
            new_key += text[i];
        }
    }
}

void encrypt_vigenere(string &text, const string &key) {
    string new_key;
    generate_key(text, key, new_key);

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char key_base = isupper(new_key[i]) ? 'A' : 'a';
            text[i] = (text[i] - base + (new_key[i] - key_base)) % 26 + base;
        }
    }
}

void decrypt_vigenere(string &text, const string &key) {
    string new_key;
    generate_key(text, key, new_key);

    for (int i = 0; i < text.length(); i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';
            char key_base = isupper(new_key[i]) ? 'A' : 'a';
            text[i] = (text[i] - base - (new_key[i] - key_base) + 26) % 26 + base;
        }
    }
}

int main() {
    string text, key;

    cout << "Enter a string: ";
    getline(cin, text);

    cout << "Enter keyword: ";
    getline(cin, key);

    encrypt_vigenere(text, key);
    cout << "Encrypted text: " << text << endl;

    decrypt_vigenere(text, key);
    cout << "Decrypted text: " << text << endl;

    return 0;
}
