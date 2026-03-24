class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long aageKaProd = 1;
        int mod = 12345;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n, vector<int>(m));

        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                res[i][j] = aageKaProd;
                aageKaProd = (aageKaProd * grid[i][j]) % mod;
            }
        }

        long long picheKaProd = 1;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res[i][j] = (picheKaProd * res[i][j]) % mod;
                picheKaProd = (picheKaProd * grid[i][j]) % mod;
            }
        }

        return res;
    }
};