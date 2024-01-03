class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxVal = nums[0];
        int len = nums.size();
        int sum = 0;
        for(int i = 0 ;i <len;i++) {
          if(sum <0) {
              sum = 0;
          }
          sum += nums[i];
          maxVal= max(maxVal, sum);
        }
        return maxVal;
    }
};
