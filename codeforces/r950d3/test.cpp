#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    while(t--) {
        int n, f, k;
        std::cin >> n >> f >> k;
        std::vector<std::pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            std::cin >> a[i].first;
            a[i].second = i;
        }
        std::sort(a.rbegin(), a.rend());
        int new_pos = std::distance(a.begin(), std::find_if(a.begin(), a.end(), [&](const std::pair<int, int>& p) {
            return p.second == f-1;
        })) + 1;
        if(new_pos <= k) {
            std::cout << "YES" << std::endl;
        } else if(new_pos > k) {
            std::cout << "NO" << std::endl;
        } else {
            std::cout << "MAYBE" << std::endl;
        }
    }
    return 0;
}