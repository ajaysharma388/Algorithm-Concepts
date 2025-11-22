def count_modified_islands(grid, k):
    if not grid or not grid[0]:
        return 0
    rows, cols = len(grid), len(grid[0])
    visited = [[False] * cols for _ in range(rows)]
    island_count = 0
    # 8 directions: horizontal, vertical, and diagonal
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

    def dfs(r, c):
        if not (0 <= r < rows and 0 <= c < cols) or visited[r][c] or grid[r][c] == 0:
            return
        visited[r][c] = True
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            dfs(nr, nc) # This assumes direct adjacency

    # To incorporate the gap < k condition:
    # The 'dfs' needs to change. It would need to check cells up to 'k' steps away
    # and possibly use BFS to manage the 'gap count' to avoid infinite loops.
    # The 'dfs' logic above only handles direct neighbors.

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1 and not visited[r][c]:
                island_count += 1
                dfs(r, c) # Call modified traversal here
    return island_count
