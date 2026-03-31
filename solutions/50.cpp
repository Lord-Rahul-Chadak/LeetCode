class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;

        long long N = (long long)n;

        if(n>0){
            return Pow(x, N);
        }else{
            double X = 1/x;
            return Pow(X, -1*N);
        }
    }

    double Pow(double x, long long n) {
        if(n == 0) return 1;
        if(n == 1) return x;

        double ans = Pow(x, n/2);

        if(n%2 == 0){
            return ans * ans;
        }else{
            return ans * ans * x;
        }
    }
};