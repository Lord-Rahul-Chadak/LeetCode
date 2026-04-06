class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        sum(1, k, n, temp, res);
        return res;
    }

    void sum(int start, int k, int n, vector<int>& temp, vector<vector<int>>& res) {
        if (temp.size() == k) {
            if (n == 0) res.push_back(temp);
            return;
        }
        
        if (start > 9 || n < 0) return;

        temp.push_back(start);
        sum(start + 1, k, n - start, temp, res);

        temp.pop_back();
        sum(start + 1, k, n, temp, res);
    }
};