class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mini = prices[0];
        int cost = 0;
        int profit = 0;

        int n= prices.size();

        for(int i=0; i<n; i++){
            
            cost = prices[i];
            profit = max(cost - mini, profit);
            mini = min(mini, prices[i]);
        }

        return profit;
    }
};