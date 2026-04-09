// CodestorywithMIK is god !!!!!!

/* basically yahan pr phle nums ko chunks mein baant lo of sqrt(n) size (n nums ka size hai)
fir do case banenge ya to k block mein ek baar hi aa rha hai fir jump kr jarha hai to some other block (k>=blocksize)
ya fir vo ek hi block mein multiple time aa rha hai(k<blocksize)

ab agar (k>=blocksize) to kuch optimise nhi ho paega kyunki jitne block hai utna iterate to hoga hi
but agar (k<blocksize) fir hum queries ko k ke according ek map mein store krwa lenge or fir 1 'k' ki value ko saath mein hi solevee kr denge
*/ 

class Solution {
public:
    int MOD = 1e9 + 7;

    long long Pow(long long a, long long b) {
        if(b == 0)
            return 1;

        long long half   = Pow(a, b/2);
        long long result = (half * half) % MOD;

        if(b % 2 == 1) {
            result = (result * a) % MOD;
        }

        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blocksize = ceil(sqrt(n)); 

        unordered_map<int, vector<vector<int>>> kmap;

        for(auto& q : queries){
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];


            if(k >= blocksize){
                for(int i = l; i<=r; i+=k){
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
            }else{
                kmap[k].push_back(q);
            }
        }

        for(auto& [k, qSet] : kmap){
            vector<long long> diff(n, 1);

            for(auto &q : qSet){
                int l = q[0];
                int r = q[1];
                int v = q[3];

                diff[l] = (diff[l] * v) % MOD;

                int steps = (r-l)/k;
                int next = l + (steps + 1) * k;

                // diff[next] = (diff[next] / v) % MOD;
                // isko likhne ka tarika alag hai
                // (a/b) % m = (a * ( b ^ ( m-2 ) ) ) % m //Fermat little theorem
                if(next < n) diff[next] = (diff[next] * Pow(v, MOD-2)) % MOD;
            }

            for(int i = 0; i<n; i++){
                if(i-k >= 0) diff[i] = (diff[i] * diff[i-k]) % MOD;
            }

            for(int i = 0; i<n; i++){
                nums[i] = (1LL * nums[i] * diff[i]) % MOD;
            }
        }

        int result = 0;
        for(int i : nums){
            result = result ^ i;
        }

        return result; 
    }
};