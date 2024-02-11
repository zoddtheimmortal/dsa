#include <bits/stdc++.h>


using namespace std;


int main() {

	// freopen("angry.in", "r", stdin);

	// freopen("angry.out", "w", stdout);


	int n, k;

	cin >> n >> k;

	int ar[n];


	for (int i = 0; i < n; i++) { cin >> ar[i]; }


	sort(ar, ar + n);


	int lo = 1, hi = 1e9;

	int sol = 1e9;


	while (lo <= hi) {

		int mid = lo + (hi - lo) / 2;

		int i = 0;

		for (int kas = 0; kas < k && i < n; kas++) {

			int hasta = ar[i];

			hasta += mid * 2;

			while (i < n - 1 && ar[i + 1] <= hasta) i++;

			i++;

		}

		bool ok;

		ok = (i >= n);

		if (ok) {

			sol = min(sol, mid);

			hi = mid - 1;

		} else {

			lo = mid + 1;

		}

	}


	cout << sol << '\n';

}

