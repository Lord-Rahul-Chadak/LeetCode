class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        int totalLen = n + m - 1;
        
        string res(totalLen, '?');
        
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != '?' && res[i + j] != str2[j]) {
                        return "";
                    }
                    res[i + j] = str2[j];
                }
            }
        }

        for (int i = 0; i < totalLen; i++) {
            if (res[i] == '?') {
                res[i] = 'a';
            }
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;
                for (int j = 0; j < m; j++) {
                    if (res[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }
                
                if (match) {
                    bool fixed = false;
                    for (int k = i + m - 1; k >= i; k--) {
                        bool isPartOfT = false;
                        for (int st = max(0, k - m + 1); st <= min(n - 1, k); st++) {
                            if (str1[st] == 'T') {
                                isPartOfT = true;
                                break;
                            }
                        }

                        if (!isPartOfT) {
                            for (char ch = 'a'; ch <= 'z'; ch++) {
                                if (ch != str2[k - i]) {
                                    res[k] = ch;
                                    fixed = true;
                                    break;
                                }
                            }
                        }
                        if (fixed) break;
                    }
                    
                    bool stillMatch = true;
                    for (int j = 0; j < m; j++) {
                        if (res[i + j] != str2[j]) {
                            stillMatch = false;
                            break;
                        }
                    }
                    if (stillMatch) return "";
                }
            }
        }

        return res;
    }
};