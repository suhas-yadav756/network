#include <iostream>
using namespace std;

void linear_congruential_generator(int seed, int a, int c, int m, int n) {
    int X = seed;

    cout << "Generated Pseudo-Random Numbers:" << endl;

    for (int i = 0; i < n; i++) {
        X = (a * X + c) % m;
        cout << X << " ";
    }

    cout << endl;
}

int main() {
    int seed = 7;
    int a = 5;
    int c = 3;
    int m = 16;
    int n = 10;

    cout << "Linear Congruential Generator (LCG) Example:" << endl;

    linear_congruential_generator(seed, a, c, m, n);

    return 0;
}
