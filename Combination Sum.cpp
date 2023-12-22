class Solution {
public:
    void combinationSumRes( vector<vector<int>>& res,vector<int>& candidates, int target) {
        static vector<int> state;
        int sum = 0;
        for (int i = 0; i < state.size(); ++i) {
            sum += state[i];
        }
        if(sum>=target){
            if (sum == target) res.push_back(state);
            return;
        }
        
        for(int i=0;i<candidates.size();i++) {
            vector<int> slicedVector(candidates.begin() + i, candidates.end());
            state.push_back(candidates[i]);
            combinationSumRes(res,slicedVector,target);
            state.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>> res;
         combinationSumRes(res,candidates,target);
         return res;
    }
};
