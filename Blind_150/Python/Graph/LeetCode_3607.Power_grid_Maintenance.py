from sortedcontainers import SortedSet

INT_MAX = 2**31 - 1
class ConnectedComponent:
    def __init__(self, size: int):
        self.size = size
        self.cur_size = 0
        self.mapping = [INT_MAX for _ in range(0, size+1)]
        self.isOnline = [True for _ in range(0, size+1)]
        self.ConnectedNodes = dict()

    def build_cc(self, connections):
        for (u, v) in connections:
            if self.mapping[u] != INT_MAX and self.mapping[u] == self.mapping[v]:
                continue
            elif self.mapping[u] == INT_MAX and self.mapping[v] == INT_MAX:
                self.cur_size += 1
                self.ConnectedNodes[self.cur_size] = SortedSet([u, v])
                self.mapping[u] = self.mapping[v] = self.cur_size
            elif self.mapping[u] == INT_MAX: # u is the new node.
                cc = self.mapping[v]
                self.ConnectedNodes[cc].add(u)
                self.mapping[u] = cc
            elif self.mapping[v] == INT_MAX: # v is the new node
                cc = self.mapping[u]
                self.ConnectedNodes[cc].add(v)
                self.mapping[v] = cc
            else:
                uc = min(self.mapping[u], self.mapping[v])
                vc = max(self.mapping[u], self.mapping[v])
                for vertex in self.ConnectedNodes[vc]:
                    self.ConnectedNodes[uc].add(vertex)
                    self.mapping[vertex] = uc
                del self.ConnectedNodes[vc]
    
    def get_status(self, node: int) -> int:
        if self.isOnline[node]:
            return node
        elif self.mapping[node] == INT_MAX:
            return -1
        elif len(self.ConnectedNodes[self.mapping[node]]):
            return self.ConnectedNodes[self.mapping[node]][0]
        return -1

    def set_status(self, node: int) -> None:
        self.isOnline[node] = False
        if self.mapping[node] != INT_MAX:
            self.ConnectedNodes[self.mapping[node]].discard(node)

class Solution:
    def processQueries(self, c: int, connections: List[List[int]], queries: List[List[int]]) -> List[int]:
        cc = ConnectedComponent(c)
        cc.build_cc(connections)
        res = []
        for query in queries:
            if query[0] == 1:
                res.append(cc.get_status(query[1]))
            else:
                cc.set_status(query[1])
        return res