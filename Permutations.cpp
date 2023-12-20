
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void swap(vector<int>& nums,int l,int r){
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
    }
    void permuteRecure(vector<vector<int>>& res,vector<int>& nums,int l,int r) {
        if(l==r) {
            res.push_back(nums);
        }
        for(int i = l;i<=r;i++ ){
            swap(nums,i,l);
            permuteRecure(res,nums,l+1,r);
            swap(nums,i,l);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permuteRecure(res,nums,0,nums.size() - 1);
        return res;
    }
};

int main()
{
   Solution su;
}
