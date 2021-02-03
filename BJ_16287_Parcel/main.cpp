#include <stdio.h>

using namespace std;

int main() {
    int w, n, weight_pair[12497500], a[5000];
    
    scanf("%d %d", &w, &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0 ; i < n ; i++) {
        for (int j = i + 1 ; j < n ; j++) {
            if (a[i] + a[j] >= w) {
                continue;
            }
            if (weight_pair[w - a[i] - a[j]] == 1) {
                printf("YES");
                return 0;
            }
        }
        for (int j = 0 ; j < i ; j++) {
            if (a[i] + a[j] < w) {
                weight_pair[a[i] + a[j]] = 1;
            }
        }
    }
    printf("NO");
}