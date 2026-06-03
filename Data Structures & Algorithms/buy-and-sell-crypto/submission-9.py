class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = 101
        profit = 0
        n = len(prices)
        for i in range(n):
            if prices[i] < min_price:
                min_price = prices[i]
            profit = max(prices[i] - min_price, profit)
        print(profit)
        return profit if profit >= 0 else 0