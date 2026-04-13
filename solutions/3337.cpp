class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    vector<vector<ll>> multiply(vector<vector<ll>> a, vector<vector<ll>> b) {
        vector<vector<ll>> res(26, vector<ll>(26, 0));

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (a[i][j] == 0)
                    continue;

                for (int k = 0; k < 26; k++) {
                    res[i][k] = (res[i][k] + (a[i][j] * b[j][k])) % MOD;
                }
            }
        }

        return res;
    }

    vector<vector<ll>> pow(vector<vector<ll>> a, int t) {
        vector<vector<ll>> res(26, vector<ll>(26, 0));

        for (int i = 0; i < 26; i++) {
            res[i][i] = 1;
        }

        while (t > 0) {
            if (t & 1)
                res = multiply(res, a);

            a = multiply(a, a);
            t = t >> 1;
        }

        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> transform(26, vector<ll>(26, 0));
        int n = nums.size();
        vector<ll> noOfChar(26, 0);

        for (char c : s) {
            noOfChar[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= nums[i]; j++) {
                transform[i][(i + j) % 26] = 1;
            }
        }

        vector<vector<ll>> newTransform = pow(transform, t);
        ll res = 0;

        for (int j = 0; j < 26; j++) {
            for (int i = 0; i < 26; i++) {
                res = (res + noOfChar[i] * newTransform[i][j]) % MOD;
            }
        }

        return (int)res;
    }
};