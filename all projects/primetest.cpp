
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {
    unsigned long n;
    while (cin >> n) {
        bool primenum = true;
        if (n < 2) {
            primenum = false;
        }
        for (unsigned i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                primenum = false;
            }
        }
        if (primenum) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}

