class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int totalBeauty = 0;

        for (int i = 0; i < n; i++) {
            int freq[26] = {0}; // sabhi letters ke liye jagah bna do 26 hi hai
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; //sabki frequency badhao agar vo aaye
                
                int maxFreq = 0; // max 0 se to badhi hi hogi
                int minFreq = n; // min 0 se to chhoti hi hogi

                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]); // max nikalo
                        minFreq = min(minFreq, freq[k]); // min nikalo
                    }
                }
                
                totalBeauty += (maxFreq - minFreq); // beauty mein add kr do
            }
        }
        return totalBeauty;
    }
};