# this is simple dfs based solution but somehow it is failing for some textcases.
# but this is simple solution as it simply tries to recursively check on all 
# four side from the bounded cell i,j to it's left, right, top, bottom to get the max
# height in the all four directions. then it is finding the water stored at some point 
# i,j by subtracting the min out of all four directions.

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        row, col = len(heightMap), len(heightMap[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        INT_MAX = (1 << 31) - 1 
        INT_MIN = (-1)*(1 << 31) - 1
        def dfs(x: int, y: int, dx: int) -> int:
            if x < 0 or x == row or y < 0 or y == col:
                return INT_MIN
            ans = dfs(x + directions[idx][0], y + directions[idx][1], idx)
            return max(ans, heightMap[x][y])
        
        res = 0
        for i in range(1, row-1):
            for j in range(1, col-1):
                ans = INT_MAX
                for idx in range(4):
                    ans = min(ans, dfs(i, j, idx))
                cur = ans - heightMap[i][j]
                print(cur, end = " ")
                res += cur if cur else 0 
            print()
        return res

# this is the solution to the same problem but it uses the multi source bfs and
# priority queue to fix the problem.

class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        row, col = len(heightMap), len(heightMap[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        min_heap = []
        # adding the boundary elements into the heap
        for i in range(row):
            heappush(min_heap, (heightMap[i][0],i,0))
            heappush(min_heap, (heightMap[i][col-1],i,col-1))
            heightMap[i][0] = heightMap[i][col-1] = -1
        
        for j in range(col):
            heappush(min_heap, (heightMap[0][j],0,j))
            heappush(min_heap, (heightMap[row-1][j],row-1,j))
            heightMap[0][j] = heightMap[row-1][j] = -1

        max_height = -1
        res = 0
        while min_heap:
            h, r, c = heappop(min_heap)
            max_height = max(max_height, h)
            res += max_height - h
            for dr, dc in directions:
                _r, _c = r+dr, c+dc
                if not (_r < 0 or _r == row or _c < 0 or _c == col or heightMap[_r][_c] == -1):
                    heappush(min_heap, (heightMap[_r][_c],_r,_c))
                    heightMap[_r][_c] = -1
        return res