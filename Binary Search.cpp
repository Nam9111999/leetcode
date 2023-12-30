class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        int mid = (l+r)/2;
        if (nums[mid] == target) return mid;
        if(l>r) return -1;
        if(target>nums[mid]) {
          return  binarySearch(nums,mid+1,r,target);
        }else {
           return binarySearch(nums,l,mid-1,target);
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums,0, nums.size()-1,target);
    }
};
