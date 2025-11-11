class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        row, col = len(heights), len(heights[0])
        pacific, atlantic = set(), set()
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        def dfs(r: int, c: int, vis: set(), height: int):
            if r < 0 or c < 0 or r >= row or c >= col:
                return 
            elif (r, c) in vis or height > heights[r][c]:
                return
            vis.add((r, c))
            for (dr, dc) in directions:
                _r, _c = r + dr, c + dc
                dfs(_r, _c, vis, heights[r][c])
            
        for c in range(col):
            # visit the first row which is atached to the pacific ocean.
            # and last col which is attached to the atlantic
            dfs(0, c, pacific, heights[0][c])
            dfs(row-1, c, atlantic, heights[row-1][c])

        for r in range(row):        
            # visit the first col which is attached to the pacific ocean.
            # and last col which is attached to the atlantic 
            dfs(r, 0, pacific, heights[r][0])
            dfs(r, col-1, atlantic, heights[r][col-1])

        res = []
        for r in range(row):
            for c in range(col):
                if (r, c) in atlantic and (r, c) in pacific:
                    res.append([r,c])
        return res

        