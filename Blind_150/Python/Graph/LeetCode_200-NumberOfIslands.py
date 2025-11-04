class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        dx = [-1, 0, 1, 0]
        dy = [ 0, 1, 0,-1]
        cnt = 0
        n = len(grid)
        m = len(grid[0])
        vis = [[-1 for _ in range(0, m)] for _ in range(0, n)]
        def dfs(i: int, j: int, cnt: int):
            if i < 0 or j < 0 or i >= n or j >= m: return
            if grid[i][j] == 0 or vis[i][j] != -1: return
            vis[i][j] = cnt
            # try to visit the neighbours
            for (x, y) in zip(dx, dy):
                dfs(i + x, j + y, cnt)
        for i in range(0, n):
            for j in range(0, m):
                if grid[i][j] == 1 and vis[i][j] == -1:
                    cnt += 1
                    dfs(i, j, cnt)
        return cnt


def main():
	n = int(input())
	while n:
		m = int(input())
		grid = list()
		for i in range(0, m):
			cur = list(map(int, input().split()))
			grid.append(cur)
		sol = Solution()
		print(sol.numIslands(grid))
		n -= 1

if __name__ == "__main__":
	main()

# Sample Input

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