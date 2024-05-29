class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> ans;
        for (int mask = 0; mask < (1 << n); mask++) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i))
                    tmp.push_back(arr[i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};