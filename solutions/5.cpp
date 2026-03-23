class Solution {
    
public:
    string longestPalindrome(string s) {
        int anslen = 0;
        string ans = "";
        int n = s.length();
        if(n<1) return ans;
        
        for(int i = 0; i<n; i++){
            // agar palindrome ki le odd ho
            int left = i, right = i;
            while((left >= 0 && right < n) && s[left] == s[right]){
                if((right - left + 1) > anslen){
                    anslen = right - left + 1;
                    ans = s.substr(left,anslen);
                }
                left --;
                right ++;
            }

            // agar palindrome ki le even ho
            left = i, right = i+1;
            while((left >= 0 && right < n) && s[left] == s[right]){
                if((right - left + 1) > anslen){
                    anslen = right - left + 1;
                    ans = s.substr(left,anslen);
                }
                left --;
                right ++;
            }
        }
        return ans;
    }    
};