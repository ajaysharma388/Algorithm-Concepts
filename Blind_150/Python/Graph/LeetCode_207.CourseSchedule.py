class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        adjList = { i: [] for i in range(numCourses)}
        for crs_a, crs_b in prerequisites:
            adjList[crs_a].append(crs_b)
        visited = set()

        def dfs(crs: int) -> bool:
            if crs in visited:
                return False
            elif adjList[crs] == []:
                return True
            
            # now we can mark the current crs as visited.
            visited.add(crs)
            for crs_nbr in adjList[crs]:
                if not dfs(crs_nbr):
                    return False
            
            visited.remove(crs)
            adjList[crs] = []
            return True
        
        for crs in range(numCourses):
            if not dfs(crs):
                return False
        return True


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        indegree = [0] * numCourses
        adj = [[] for i in range(numCourses)]
        for src, dst in prerequisites:
            indegree[dst] += 1
            adj[src].append(dst)

        q = deque()
        for n in range(numCourses):
            if indegree[n] == 0:
                q.append(n)

        finish = 0
        while q:
            node = q.popleft()
            finish += 1
            for nei in adj[node]:
                indegree[nei] -= 1
                if indegree[nei] == 0:
                    q.append(nei)

        return finish == numCourses