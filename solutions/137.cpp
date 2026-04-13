class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int oneTime = 0;
        int twoTimes = 0;

        for(int i : nums){
            oneTime = ((i^oneTime) & ~(twoTimes));
            twoTimes = ((i^twoTimes) & ~(oneTime));
        }

        return oneTime;
    }
};