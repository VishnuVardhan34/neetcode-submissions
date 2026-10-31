class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        # Considering that we can buy and sell by conserifing a window for max profit, but we can achieve the same thing, by doing multiple transactions as well
        profit = 0
        n = len(prices)
        for i in range(1,n):
            if prices[i] > prices[i - 1]:
                profit += prices[i] - prices[i - 1]

        return profit
