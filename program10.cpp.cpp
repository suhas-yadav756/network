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

int main() {
    long long p = 23;
    long long g = 5;

    long long a = 6;
    long long b = 15;

    long long A = mod_exp(g, a, p);
    long long B = mod_exp(g, b, p);

    cout << "Public prime (p): " << p << endl;
    cout << "Public base (g): " << g << endl;
    cout << "Alice's Private Key: " << a << endl;
    cout << "Bob's Private Key: " << b << endl;
    cout << "Alice's Public Key (A): " << A << endl;
    cout << "Bob's Public Key (B): " << B << endl;

    long long alice_secret = mod_exp(B, a, p);
    long long bob_secret = mod_exp(A, b, p);

    cout << "Alice's Computed Secret Key: " << alice_secret << endl;
    cout << "Bob's Computed Secret Key: " << bob_secret << endl;

    return 0;
}
