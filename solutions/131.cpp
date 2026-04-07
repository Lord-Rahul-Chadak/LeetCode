class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int ind = 0;
        recurse(ind, s, temp, res);
        return res;
    }

    void recurse(int a, string s, vector<string>& temp, vector<vector<string>>& res){
        if(a == s.size()){
            res.push_back(temp);
            return;
        }

        for(int i = a; i<s.size(); i++){
            if(palindrome(s, a, i)){
                temp.push_back(s.substr(a, i-a+1));
                recurse(i+1, s, temp, res);
                temp.pop_back();
            }
        }
    }

    bool palindrome(string s, int l, int r){
        while(l <= r){
            if(s[l] == s[r]){
                l++; r--;
                continue;
            }
            return false;
        }
        return true;
    }
};