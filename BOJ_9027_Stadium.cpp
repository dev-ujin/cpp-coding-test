#include <iostream>

using namespace std;

int villages[100000], fans[100000];

int get_stadium() {
    int N, fan_sum=0, temp_sum=0, index=0;

    cin >> N;

    for (int i=0 ; i < N ; i++) {
        cin >> villages[i];
    }

    for (int i=0 ; i < N ; i++) {
        cin >> fans[i];
        fan_sum += fans[i];
    }

    while(temp_sum <= ((float)fan_sum / 2)) {
        temp_sum += fans[index++];
    }

    return villages[--index];
}

int main() {
    int T;
    cin >> T;

    while(T--) {
      cout << get_stadium() << endl;
    }

    return 0;
}