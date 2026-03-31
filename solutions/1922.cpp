class Solution {
public:
    
    long long MOD = 1e9 + 7;
    
    int countGoodNumbers(long long n) {
        if(n == 1) return 5;

        long long a = 0;

        if(n%2 == 0){
            a = n/2;
        }else{
            a = n/2 + 1;
        }

        long long ans = (Pow(5, a) * Pow(4, n-a)) % MOD;

        return (int)(ans);
    }

    long long Pow(int x, long long n) {
        if(n == 0) return 1;
        if(n == 1) return x;

        long long ans = Pow(x, n/2);

        if(n%2 == 0){
            return (ans * ans) % MOD;
        }else{
            return (((ans * ans) % MOD) * x) % MOD;
        }
    }
};