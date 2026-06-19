#include <iostream>
#include <cstring>
using namespace std;

#define MOD 26

int determinant(int key[2][2]) {
    return ((key[0][0] * key[1][1]) - (key[0][1] * key[1][0])) % MOD;
}

int mod_inverse(int det) {
    det = (det % MOD + MOD) % MOD;

    for (int i = 1; i < MOD; i++) {
        if ((det * i) % MOD == 1)
            return i;
    }

    return -1;
}

void inverse_key_matrix(int key[2][2], int inverseKey[2][2]) {
    int det = determinant(key);
    int det_inv = mod_inverse(det);

    if (det_inv == -1) {
        cout << "Inverse does not exist (key is not invertible)." << endl;
        return;
    }

    inverseKey[0][0] = (key[1][1] * det_inv) % MOD;
    inverseKey[1][1] = (key[0][0] * det_inv) % MOD;
    inverseKey[0][1] = (-key[0][1] * det_inv) % MOD;
    inverseKey[1][0] = (-key[1][0] * det_inv) % MOD;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            inverseKey[i][j] = (inverseKey[i][j] + MOD) % MOD;
        }
    }
}

void encrypt_hill(char *text, int key[2][2]) {
    int len = strlen(text);

    if (len % 2 != 0) {
        strcat(text, "X");
        len++;
    }

    for (int i = 0; i < len; i += 2) {
        int vec[2] = {text[i] - 'A', text[i + 1] - 'A'};
        int res[2];

        res[0] = (key[0][0] * vec[0] + key[0][1] * vec[1]) % MOD;
        res[1] = (key[1][0] * vec[0] + key[1][1] * vec[1]) % MOD;

        text[i] = res[0] + 'A';
        text[i + 1] = res[1] + 'A';
    }
}

void decrypt_hill(char *text, int key[2][2]) {
    int inverseKey[2][2];

    inverse_key_matrix(key, inverseKey);

    int len = strlen(text);

    for (int i = 0; i < len; i += 2) {
        int vec[2] = {text[i] - 'A', text[i + 1] - 'A'};
        int res[2];

        res[0] = (inverseKey[0][0] * vec[0] + inverseKey[0][1] * vec[1]) % MOD;
        res[1] = (inverseKey[1][0] * vec[0] + inverseKey[1][1] * vec[1]) % MOD;

        text[i] = res[0] + 'A';
        text[i + 1] = res[1] + 'A';
    }
}

int main() {
    int key[2][2] = {{6, 24}, {1, 13}};
    char text[100];

    cout << "Enter text (uppercase only): ";
    cin.getline(text, 100);

    encrypt_hill(text, key);
    cout << "Encrypted text: " << text << endl;

    decrypt_hill(text, key);
    cout << "Decrypted text: " << text << endl;

    return 0;
}
