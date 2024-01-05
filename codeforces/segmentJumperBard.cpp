#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
  int left;
  int right;
};

bool compareSegments(const Segment& a, const Segment& b) {
  return a.left < b.left;
}

int solve(vector<Segment>& segments, int k) {
  sort(segments.begin(), segments.end(), compareSegments);
  int min_k = 0;
  int furthest_reachable = 0;
  for (const Segment& segment : segments) {
    if (segment.left > furthest_reachable + k) {
      return -1;
    }
    min_k = max(min_k, segment.right - furthest_reachable);
    furthest_reachable = max(furthest_reachable, segment.left + k);
  }
  return min_k;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
      cin >> segments[i].left >> segments[i].right;
    }
    int k;
    cin >> k;
    int min_k = solve(segments, k);
    if (min_k == -1) {
      cout << "IMPOSSIBLE" << endl;
    } else {
      cout << min_k << endl;
    }
  }
  return 0;
}