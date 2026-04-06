class Solution {
public:

    vector<string> all = {"",
                        "",
                        "abc",
                        "def",
                        "ghi",
                        "jkl",
                        "mno",
                        "pqrs",
                        "tuv",
                        "wxyz"};

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        string temp = "";
        vector<string> res;
        int index = 0;
        make(index, digits, temp, res);
        return res;
    }

    void make(int ind, string digits, string& temp, vector<string>& res){
        if(ind == digits.length()){
            res.push_back(temp);
            return;
        }
        
        for(char i : all[digits[ind] - '0']){
            temp.push_back(i);
            make(ind + 1, digits, temp, res);
            temp.pop_back();
        }
    }
};