#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, w, L;
    int time = 0;
    int total_weight_on_bridge = 0;
    queue<int> a; //trucks
    queue<int> bridge;

    cin >> n >> w >> L;
    for (int i=0 ; i<n ; i++) {
        int temp;
        cin >> temp;
        a.push(temp);
    }

    //put first truck on the bridge
    bridge.push(a.front());
    total_weight_on_bridge += bridge.back();
    a.pop();
    time++;

    while (a.size() > 0) {
        if (bridge.size() >= w) {
            total_weight_on_bridge -= bridge.front();
            bridge.pop();
        }
        if (a.front() <= L - total_weight_on_bridge) {
            bridge.push(a.front());
            total_weight_on_bridge += bridge.back();
            a.pop();
        }
        else {
            bridge.push(0);
        }
        time++;
    }
    cout << time + w;
}


