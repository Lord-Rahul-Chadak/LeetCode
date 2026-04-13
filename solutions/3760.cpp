class Solution {
public:
    int maxDistinct(string s) {
        vector<int> atoz(26, 0);
        int res = 0;

        for(char c : s){
            if(atoz[c - 'a'] == 1) continue;

            atoz[c - 'a'] = 1;
        }

        for(int i : atoz){
            res += i;
        }

        return res;
    }
};