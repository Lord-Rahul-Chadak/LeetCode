class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        long long totalSum = 0;
        vector<long long> rowSums(m, 0);
        vector<long long> colSums(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                totalSum += grid[i][j];
                rowSums[i] += grid[i][j];
                colSums[j] += grid[i][j];
            }
        }

        if (totalSum % 2 != 0) return false;

        long long target = totalSum / 2;

        long long currentSum = 0;
        
        for (int i = 0; i < m - 1; i++) {
            currentSum += rowSums[i];
            if (currentSum == target) return true;
        }

        currentSum = 0;
        for (int j = 0; j < n - 1; j++) {
            currentSum += colSums[j];
            if (currentSum == target) return true;
        }

        return false;
    }
};