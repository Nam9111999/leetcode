class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        if(target >= nums[0]) {
            while(i+1<nums.size()  && nums[i+1]>nums[i]) {
                if(target == nums[i]) return i;
                i++;
            }
            if(target == nums[i]) return i;
        } else {
            i = nums.size() -1;
             while(i-1 >=0 && nums[i-1]<nums[i]) {
                if(target == nums[i]) return i;
                i--;
            }
            if(target == nums[i]) return i;
        }

        return -1;
    }
};
