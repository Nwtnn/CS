#include <iostream>
#include <cmath>

using namespace std;

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)  
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    printf("Name: Newton Tiwari\n");
    
    long long p = 97;
    long long g = 10;

    long long a = 23;
    long long b = 42;

    long long A = mod_exp(g, a, p);
    long long B = mod_exp(g, b, p);

    long long shared_secret_A = mod_exp(B, a, p);
    long long shared_secret_B = mod_exp(A, b, p);

    cout << "Prime (p): " << p << ", Generator (g): " << g << endl;
    cout << "Alice's Private Key: " << a << ", Public Key: " << A << endl;
    cout << "Bob's Private Key: " << b << ", Public Key: " << B << endl;
    cout << "Shared Secret (Alice): " << shared_secret_A << endl;
    cout << "Shared Secret (Bob): " << shared_secret_B << endl;

    if (shared_secret_A == shared_secret_B)
        cout << "Key Exchange Successful! Shared Key: " << shared_secret_A << endl;
    else
        cout << "Error in Key Exchange!" << endl;

    return 0;
}
