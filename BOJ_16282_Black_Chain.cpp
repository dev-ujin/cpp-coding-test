#include <iostream>

using namespace std;

int main() {
    long n;
    cin >> n;
    
    for (int cut = 1 ; ; cut++) {
        long max = 1;
        for (int i = 0 ; i < cut + 1 ; i++) {
            max = max * 2;
        }
        max = max * (cut + 1) - 1;
        if (max >= n) {
            cout << cut;
            return 0;
        }
    }
}