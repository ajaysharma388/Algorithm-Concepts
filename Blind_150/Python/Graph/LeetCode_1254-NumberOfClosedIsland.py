class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        vis = set()
        res = 0
        def dfs(r: int, c: int) -> int:
            if(r < 0 or c < 0 or
               r == row or c == col):
               return 0
            if grid[r][c] or (r, c) in vis:
                return 1
            ans = 1
            vis.add((r, c))
            for (dr, dc) in directions:
                _r, _c = r + dr, c + dc
                ans = min(ans, dfs(_r, _c))
                
            return ans
        
        for i in range(row):
            for j in range(col):
                if grid[i][j] == 0 and (i, j) not in vis:
                    res += dfs(i, j)
        return res