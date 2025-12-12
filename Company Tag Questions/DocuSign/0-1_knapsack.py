class Solution:
    def maximumProfit(self, profit: List[int], weight: List[int], capacity: int) -> int:
        N, M = len(profit), capacity+1
        cache = [[0] * M for _ in range(N)]
        return self.bottom_up(capacity, profit, weight, cache)
        # return self.dfs(0, capacity, profit, weight, cache)

    def dfs(self, i: int, c: int, profit: List[int], weight: List[int], cache: List[List[int]]) -> int:
        if i == len(profit):
            return 0
        if cache[i][c] != -1:
            return cache[i][c]
        # skip the current and calculate the profit.
        max_profit = self.dfs(i + 1, c, profit, weight, cache)
        # include this state.
        newCapacity = c - weight[i]
        if newCapacity >= 0:
            max_profit = max(max_profit, profit[i] + self.dfs(i + 1, newCapacity, profit, weight, cache))
        cache[i][c] = max_profit
        return max_profit
        
    def print_mat(self, dp: List[List[int]], r: int, c: int) -> None:
        for i in range(r):
            for j in range(c):
                print(dp[i][j], end=" ")
            print()

    def bottom_up(self, c: int, profit: List[int], weight: List[int], dp: List[List[int]]) -> int:
        n, m = len(profit), c+1
        self.print_mat(dp, n, m)
        for c in range(m):
            if c - weight[0] >= 0:
                dp[0][c] = profit[0]
        
        for i in range(n):
            for j in range(1, m):
                skip = dp[i-1][j]
                include = 0
                new_cap = j - weight[i]
                if new_cap >= 0:
                    include = profit[i] + dp[i-1][new_cap]
                dp[i][j] = max(skip, include)
        
        return dp[n-1][m-1]
        



