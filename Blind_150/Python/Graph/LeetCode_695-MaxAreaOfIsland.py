class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        dx = [-1, 0, 1, 0]
        dy = [ 0, 1, 0,-1]
        n = len(grid)
        m = len(grid[0])
        self.res = 0
        vis = [[-1 for _ in range(0, m)] for _ in range(0, n)]

        def dfs(i: int, j: int, size: int) -> None:
            if i < 0 or j < 0 or i >= n or j >= m: return
            if grid[i][j] == 0 or vis[i][j] != -1: return
            self.size += 1
            vis[i][j] = self.size
            # try to visit the neighbours
            for (x, y) in zip(dx, dy):
                dfs(i + x, j + y, self.size)
            self.res = max(self.res, vis[i][j])

        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == 1 and vis[i][j] == -1:
                    self.size = 0
                    dfs(i, j, self.size)

        return self.res


def main():
	n = int(input())
	while n:
		m = int(input())
		grid = list()
		for i in range(0, m):
			cur = list(map(int, input().split()))
			grid.append(cur)
		sol = Solution()
		print(sol.maxAreaOfIsland(grid))
		n -= 1

if __name__ == "__main__":
	main()
	
# Sample Input:
# 2
# 4
# 0 1 1 1 0
# 0 1 0 1 0
# 1 1 0 0 0
# 0 0 0 0 0
# 4
# 1 1 0 0 1 
# 1 1 0 0 1
# 0 0 1 0 0
# 0 0 0 1 1

# Sample Output:
# 7
# 4