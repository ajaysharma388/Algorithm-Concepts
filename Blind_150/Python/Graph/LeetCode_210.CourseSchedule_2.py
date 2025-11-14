from collections import defaultdict

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        adjList = defaultdict(list)
        indegree = [0]*numCourses
        for edge in prerequisites:
            src, dest = edge[1], edge[0]
            adjList[src].append(dest)
            indegree[dest] += 1

        # now we can start the dfs.
        queue = deque()
        res = []
        finish = 0
        for i in range(numCourses):
            if indegree[i] == 0:
                queue.append(i)
                finish += 1
        
        while queue:
            cur = queue.popleft()
            res.append(cur)
            for nbr in adjList[cur]:
                indegree[nbr] -= 1
                if indegree[nbr] == 0:
                    queue.append(nbr)
                    finish += 1
        
        if finish == numCourses:
            return res
        return []