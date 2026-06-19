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

int euler_totient(int n) {
    int result = 1;

    for (int i = 2; i < n; i++) {
        if (gcd(i, n) == 1) {
            result++;
        }
    }

    return result;
}

long long fermat_mod_inverse(int a, int p) {
    return mod_exp(a, p - 2, p);
}

long long euler_theorem(int a, int n) {
    int phi_n = euler_totient(n);
    return mod_exp(a, phi_n, n);
}

int main() {
    int a = 7;
    int p = 13;
    int n = 10;

    long long fermat_inverse = fermat_mod_inverse(a, p);

    cout << "Fermat's Theorem:" << endl;
    cout << "Modular Inverse of " << a << " mod " << p << ": "
         << fermat_inverse << endl << endl;

    long long euler_result = euler_theorem(a, n);

    cout << "Euler's Theorem:" << endl;
    cout << a << "^f(" << n << ") mod " << n << ": "
         << euler_result << endl;

    return 0;
}
