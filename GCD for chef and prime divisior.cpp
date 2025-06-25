#include<iostream>
#include<algorithm>
using namespace std;

// Function to check if all prime factors of b divide a
bool allPrimeFactorsDivide(int a, int b) {
    int g = __gcd(a, b);
    while (b != 1) {
        int g1 = __gcd(g, b);
        if (g1 == 1) return false;
        while (b % g1 == 0) {
            b /= g1;
        }
    }
    return true;
}

int main() {
    int a = 7, b = 8;

    if (allPrimeFactorsDivide(a, b))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}

