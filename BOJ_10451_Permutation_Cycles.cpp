#include <iostream>
#include <cstring>

using namespace std;

int input[1001];
bool visited[1001];

void dfs(int i) {
    if (visited[i]) {
        return;
    }
    visited[i] = true;
    dfs(input[i]);
}

int find_cycle(int N) {
    memset(visited, false, sizeof(visited));
    int cycle = 0;
    for (int i=1 ; i <= N ; i++) {
        if (!visited[i]) {
            dfs(i);
            cycle++;
        }
    }
    return cycle;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i=1 ; i <= N ; i++) {
            cin >> input[i];
        }
        cout << find_cycle(N) << "\n";
    }
    return 0;
}