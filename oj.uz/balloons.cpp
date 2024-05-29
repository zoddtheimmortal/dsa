#include <bits/stdc++.h>
using namespace std;

double calc_r(pair<double, double> a, double bx) {
	return (a.first - bx) * (a.first - bx) / (4 * a.second);
}

int main() {
	int n;
	cin >> n;

	vector<double> final_radius(n);
	stack<pair<double, double>> to_check;

	for (int i = 0; i < n; i++) {
		double x, r;
		cin >> x >> r;
		double max_r = r;

		while (!to_check.empty()) {
			pair<double, double> last = to_check.top();
			max_r = min(max_r, calc_r(last,x));

			if (max_r >= last.second) {
				to_check.pop();
				continue;
			}

			else {
				break;
			}
		}
		to_check.push({x, max_r});

		final_radius[i] = max_r;
	}

	cout << fixed << setprecision(3);
	for (double &r : final_radius) { cout << r << "\n"; }
}