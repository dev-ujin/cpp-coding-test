#include <iostream>
using namespace std;

int main() {
	int a, b, n, w;
	int sheep, goat;
	int feed_weight;
	int total_sheep;
	int total_goat;
	int count_solution = 0;

	cin >> a >> b >> n >> w;

	for (int i = 1; i < n; i++) {
		sheep = i; 
		goat = n - sheep;
		feed_weight = a * sheep + b * goat;
		if (count_solution > 1) {
			break;
		}
		if (feed_weight == w) {
			total_sheep = sheep;
			total_goat = goat;
			count_solution++;
		}
	}

	if (count_solution == 1) {
		cout << total_sheep << " " << total_goat;
	}
	else {
		cout << "-1";
    }
}
