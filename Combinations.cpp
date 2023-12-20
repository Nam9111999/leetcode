class Solution {
public:
      void combineRecursive(std::vector<std::vector<int>>& res, std::vector<int>& mem, int k, int start, int n) {
        if (mem.size() == k) {
            res.push_back(mem);
            return;
        }

        for (int i = start; i <= n; ++i) {
            mem.push_back(i);
            combineRecursive(res, mem, k, i + 1, n);
            mem.pop_back();
        }
    }
        vector<vector<int>> combine(int n, int k) {
            vector<int> mem(0);
            vector<vector<int>> res(0);
            combineRecursive(res,mem,k,1,n);
            return res;
        }
};
