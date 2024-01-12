class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1,tmp,zero = 0;
        for(auto x:nums) {
            if(x != 0) {
                sum *=x;
                continue;
            }
            zero += 1;
        }
        for(int i=0;i<nums.size();i++){
            tmp = sum;
            if(nums[i] != 0 ) {
                if (zero > 0) {
                    nums[i] = 0;
                    continue;
                }
                nums[i] = tmp / nums[i];
            } else {
                if (zero == 1) {
                    nums[i] = tmp;
                    continue;
                }
                nums[i] = 0;
            }

           
        }

        return nums;
    }
};
