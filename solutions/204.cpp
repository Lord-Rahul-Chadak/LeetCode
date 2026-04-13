class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;

        vector<int> primes(n, 1);

        primes[0] = 0;
        primes[1] = 0;

        for(int i = 2; i*i < n; i++){
            if(primes[i]){
                for(int j = i*i; j<n; j = j + i){
                    primes[j] = 0;
                }
            }
        }

        int number = 0;

        for(int i : primes){
            number+=i;
        }

        return number;
    }
};