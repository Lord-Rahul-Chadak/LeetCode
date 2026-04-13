class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long long totalXor = 0;

        for(int i : nums){
            totalXor = totalXor ^ i;
        }

        long long alagBit = totalXor & -totalXor;
        int grpA = 0, grpB = 0;

        for(int i = 0; i<n; i++){
            if(nums[i] & alagBit){
                grpA = grpA ^ nums[i];
            }else{
                grpB = grpB ^ nums[i];
            }
        }

        return {grpA, grpB};
    }
};