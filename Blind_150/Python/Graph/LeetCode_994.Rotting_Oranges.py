


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        self.INF = 2**31 - 1
        r, c = len(grid), len(grid[0])
        vis = [[False for _ in range(c)] for _ in range(r)]
        # graph = [[0 for _ in range(c)] for _ in range(r)]
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        queue = deque()
        for i in range(0, r):
            for j in range(0, c):
                # this is the entry gate of the tresure chest
                if grid[i][j] == 2: 
                    queue.append((i, j))
                    vis[i][j] = True
                    grid[i][j] = 0
                elif grid[i][j] == 1:
                    grid[i][j] = self.INF
                else:
                    grid[i][j] = -1
        # since we have the cordinates in the queue we will run the BFS now.
        while queue:
            # now we can iterate over all the chidrens and then do the calculation.
            cur_queue = deque()
            for _ in range(len(queue)):
                (x, y) = queue.popleft()
                dis = grid[x][y]
                for (dx, dy) in directions:
                    _x = x + dx
                    _y = y + dy
                    if _x < 0 or _x >= r or _y < 0 or _y >= c:
                        continue
                    elif grid[_x][_y] == -1 or grid[_x][_y] == 0 or vis[_x][_y]:
                        continue
                    grid[_x][_y] = min(grid[_x][_y], dis + 1)
                    cur_queue.append((_x, _y))
                    vis[_x][_y] = True

            if len(cur_queue):
                queue = cur_queue
        res = 0
        print(grid)
        for i in range(0, r):
            for j in range(0, c):
                if grid[i][j] == self.INF:
                    return -1
                res = max(res, grid[i][j])
        return res