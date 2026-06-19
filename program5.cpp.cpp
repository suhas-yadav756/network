#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

void create_matrix(char *text, char matrix[MAX][MAX], int rows, int cols) {
    int len = strlen(text);
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (index < len) ? text[index++] : 'X';
        }
    }
}

void encrypt_transposition(char *text, int key[], int key_len) {
    int rows = (strlen(text) + key_len - 1) / key_len;
    char matrix[MAX][MAX];

    create_matrix(text, matrix, rows, key_len);

    cout << "Encrypted Text: ";
    for (int i = 0; i < key_len; i++) {
        int col = key[i] - 1;
        for (int j = 0; j < rows; j++) {
            cout << matrix[j][col];
        }
    }
    cout << endl;
}

void decrypt_transposition(char *cipher, int key[], int key_len) {
    int len = strlen(cipher);
    int rows = len / key_len;
    char matrix[MAX][MAX];

    int index = 0;

    for (int i = 0; i < key_len; i++) {
        int col = key[i] - 1;
        for (int j = 0; j < rows; j++) {
            matrix[j][col] = cipher[index++];
        }
    }

    cout << "Decrypted Text: ";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < key_len; j++) {
            cout << matrix[i][j];
        }
    }
    cout << endl;
}

void encrypt_double_transposition(char *text, int key1[], int key2[], int key_len) {
    char temp[MAX];

    strcpy(temp, text);

    cout << "After First Transposition:" << endl;
    encrypt_transposition(temp, key1, key_len);

    cout << "After Second Transposition:" << endl;
    encrypt_transposition(temp, key2, key_len);
}

void decrypt_double_transposition(char *cipher, int key1[], int key2[], int key_len) {
    char temp[MAX];

    strcpy(temp, cipher);

    cout << "After First Decryption:" << endl;
    decrypt_transposition(temp, key2, key_len);

    cout << "After Second Decryption:" << endl;
    decrypt_transposition(temp, key1, key_len);
}

int main() {
    char text[MAX];
    int key1[] = {3, 1, 4, 2};
    int key2[] = {2, 4, 1, 3};
    int key_len = 4;

    cout << "Enter plaintext: ";
    cin.getline(text, MAX);

    cout << "\n** Single Transposition Encryption **" << endl;
    encrypt_transposition(text, key1, key_len);

    cout << "\n** Single Transposition Decryption **" << endl;
    decrypt_transposition(text, key1, key_len);

    cout << "\n** Double Transposition Encryption **" << endl;
    encrypt_double_transposition(text, key1, key2, key_len);

    cout << "\n** Double Transposition Decryption **" << endl;
    decrypt_double_transposition(text, key1, key2, key_len);

    return 0;
}
