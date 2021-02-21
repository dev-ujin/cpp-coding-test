#include <iostream>
#include <algorithm>

using namespace std;

int get_answer() {
    int k, n;
    cin >> k >> n;
    int c1[n], c2[n], c3[n], c4[n], sum12[n*n], sum34[n*n];

    for (int i=0 ; i < n ; i++) {
        cin >> c1[i];
    }
    for (int i=0 ; i < n ; i++) {
        cin >> c2[i];
    }
    for (int i=0 ; i < n ; i++) {
        cin >> c3[i];
    }
    for (int i=0 ; i < n ; i++) {
        cin >> c4[i];
    }
    
    int index = 0;
    for (int i=0 ; i < n ; i++) {
        for (int j=0 ; j < n ; j++) {
            sum12[index] = c1[i] + c2[j];
            sum34[index] = c3[i] + c4[j];
            index++;
        }
    }

    sort(sum12, sum12+(n*n));
    sort(sum34, sum34+(n*n));

    int min_diff = 40000000-4;
    int answer = 40000000;
    for (int i=0 ; i < n*n ; i++) {
        int goal = k - sum12[i];
        int left = 0, right = n*n - 1;

        while (left <= right) {
            int index = (left + right) / 2;
            if (goal == sum34[index]) {
                return k;
            }
            if ((min_diff == abs(goal - sum34[index])) && (answer > sum12[i] + sum34[index])) {
                answer = sum12[i] + sum34[index];
            }
            else if (min_diff > abs(goal - sum34[index])) {
                min_diff = abs(goal - sum34[index]);
                answer = sum12[i] + sum34[index];
            }
            if (goal > sum34[index]) {
                left = index + 1;
            }
            else if (goal < sum34[index]) {
                right = index - 1;
            }
        }
    }
    return answer;
}

int main() {
    int T, k, n;
    cin >> T;
    while(T--) {
        cout << get_answer() << "\n";
    }
    return 0;
}