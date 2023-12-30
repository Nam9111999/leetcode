class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];
        int maxPro = 0;
        for(auto x:prices) {
            mi = min(mi,x);
            maxPro = max(maxPro,x-mi);
        }
        return maxPro;
    }
};
