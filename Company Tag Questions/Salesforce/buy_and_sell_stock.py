class Solution:
	def maxProfit(self, prices: List[int]) -> int:
		# whatever price we have at the left pointer that will be 
		# price of buying and whatever we have on the right that will be 
		# my selling price.
		l, n = 0, len(prices) 
		maxProfit = 0
		for r in range(1, n):
			if prices[l] < prices[r]:
				profit = prices[r] - prices[l]
				maxProfit = max(maxProfit, profit)
			else:
				l = r 

		return maxProfit