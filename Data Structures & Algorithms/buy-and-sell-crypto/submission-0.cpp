class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, profit=0, minValue=INT_MAX;
        for(int &price: prices) {
            minValue = min(minValue, price);
            profit = price - minValue;
            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};
