#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int mod_inverse(int e, int phi) {
    for (int d = 2; d < phi; d++) {
        if ((e * d) % phi == 1) {
            return d;
        }
    }

    return -1;
}

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

void generate_keys(int p, int q, int *n, int *e, int *d) {
    *n = p * q;
    int phi = (p - 1) * (q - 1);

    *e = 3;

    while (gcd(*e, phi) != 1) {
        (*e)++;
    }

    *d = mod_inverse(*e, phi);
}

long long rsa_encrypt(long long plaintext, int e, int n) {
    return mod_exp(plaintext, e, n);
}

long long rsa_decrypt(long long ciphertext, int d, int n) {
    return mod_exp(ciphertext, d, n);
}

int main() {
    int p = 61, q = 53;
    int n, e, d;

    generate_keys(p, q, &n, &e, &d);

    cout << "Public Key: (n = " << n << ", e = " << e << ")" << endl;
    cout << "Private Key: (n = " << n << ", d = " << d << ")" << endl;

    long long plaintext = 42;

    long long ciphertext = rsa_encrypt(plaintext, e, n);
    cout << "\nEncrypted: " << ciphertext << endl;

    long long decrypted = rsa_decrypt(ciphertext, d, n);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
