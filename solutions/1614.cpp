class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int n = s.length();
        int temp = 0;

        for(char c : s){
            if(c == '('){
                temp++;
            }
            else if(c == ')'){
                temp--;
            }
            else continue;
            ans = max(temp,ans);
        }
        return ans;
    }
};