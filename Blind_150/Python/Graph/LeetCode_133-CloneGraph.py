"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        node_map = dict()
        def dfs(root: Optional['None']) -> Node:
            if root == None: return None
            if root.val in node_map: return node_map[root.val]
            node_map[root.val] = Node(root.val)
            for neighbor in root.neighbors:
                node_map[root.val].neighbors.append(dfs(neighbor))

            return node_map[root.val]
        return dfs(node)
        