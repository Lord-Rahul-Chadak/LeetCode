class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int minD = INT_MAX;

        for(int i = 0; i < n; i++){
            int currD = 0;
            if(nums[i] == target){
                currD = abs(i - start);

                minD = min(currD, minD);

                if(minD == 0) return 0;
            }
        }

        return minD;
    }
};