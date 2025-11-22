class Solution:
    def findOrder(self, words):
        adjList = {c: set() for w in words for c in w}

        # now lets iterate over the list of words and prepare the adjlist
        for i in range(len(words)-1):
            w1, w2 = words[i], words[i+1]
            min_len = min(len(w1), len(w2))
            if len(w1) > len(w2) and w1[:min_len] == w2[:min_len]:
                return ""
            # now since this is a valid case now we can figure out first diff.
            for j in range(min_len):
                if w1[j] != w2[j]:
                    adjList[w1[j]].add(w2[j])
                    break

        visited = {}
        path = []
        # now we have the adjecency list we can call the dfs function over the graph
        def dfs(c) -> bool:
            if c in visited:
                return visited[c]

            visited[c] = True
            # now we have to iterate over all of it's nbr.
            for nbr in adjList[c]:
                if dfs(nbr):
                    return True

            visited[c] = False
            path.append(c)
            return False

        for c in adjList:
            if dfs(c):
                return ""

        path.reverse()
        return "".join(path)