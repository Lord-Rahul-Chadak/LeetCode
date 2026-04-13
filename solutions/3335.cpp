class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        long long MOD = 1e9 + 7;
        vector<long long> noOfChar(26, 0);

        for (char c : s) {
            noOfChar[c - 'a']++;
        }

        for (int i = 0; i < t; i++) {
            vector<long long> newNoOfChar(26, 0);
            for (int j = 0; j < 26; j++) {
                if (noOfChar[j] == 0) continue;

                if (j == 25) {
                    newNoOfChar[0] = (newNoOfChar[0] + noOfChar[j]) % MOD;
                    newNoOfChar[1] = (newNoOfChar[1] + noOfChar[j]) % MOD;
                } else {
                    newNoOfChar[j + 1] = (newNoOfChar[j + 1] + noOfChar[j]) % MOD;
                }
            }
            noOfChar = newNoOfChar;
        }

        long long totalLength = 0;
        for (int i = 0; i < 26; i++) {
            totalLength = (totalLength + noOfChar[i]) % MOD;
        }

        return (int)totalLength;
    }
};