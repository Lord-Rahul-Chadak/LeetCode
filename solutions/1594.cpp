class Solution {
    
public:
    int maxProductPath(vector<vector<int>>& grid) {
        const int mod = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();

        vector<vector<long long>> dpMax(m, vector<long long>(n));
        vector<vector<long long>> dpMin(m, vector<long long>(n));

        dpMax[0][0] = grid[0][0];
        dpMin[0][0] = grid[0][0];

        // first row
        for (int j = 1; j < n; j++) {
            dpMax[0][j] = dpMax[0][j - 1] * grid[0][j];
            dpMin[0][j] = dpMin[0][j - 1] * grid[0][j];
        }

        // first column
        for (int i = 1; i < m; i++) {
            dpMax[i][0] = dpMax[i - 1][0] * grid[i][0];
            dpMin[i][0] = dpMin[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                int val = grid[i][j];
                long long topMax = dpMax[i - 1][j] * val;
                long long topMin = dpMin[i - 1][j] * val;
                long long leftMax = dpMax[i][j - 1] * val;
                long long leftMin = dpMin[i][j - 1] * val;

                dpMax[i][j] = max({topMax, topMin, leftMax, leftMin});
                dpMin[i][j] = min({topMax, topMin, leftMax, leftMin});
            }
        }

        long long ans = dpMax[m - 1][n - 1];
        return ans < 0 ? -1 : (int)(ans % mod);
    }
};