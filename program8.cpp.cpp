#include <iostream>
using namespace std;

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

void blum_blum_shub(long long seed, long long p, long long q, int count) {
    long long n = p * q;
    long long X = (seed * seed) % n;

    cout << "Generated Pseudo-Random Numbers:" << endl;

    for (int i = 0; i < count; i++) {
        X = mod_exp(X, 2, n);
        cout << (X % 256) << " ";
    }

    cout << endl;
}

int main() {
    long long p = 11, q = 19;
    long long seed = 7;
    int count = 10;

    cout << "Blum Blum Shub (BBS) PRNG Example:" << endl;

    blum_blum_shub(seed, p, q, count);

    return 0;
}
