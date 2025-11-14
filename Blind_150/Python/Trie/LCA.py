class Solution:
    def lca(self, root, n1, n2):
        # code here
        self.res = root
        path_A = []
        path_B = []
        
        def dfs(cur_node, num, path):
            if cur_node is None:
                return False
            elif cur_node.data == num:
                path.append(cur_node)
                return True
            leftAns = dfs(cur_node.left, num, path)
            rightAns = dfs(cur_node.right, num, path)
            if leftAns or rightAns:
                path.append(cur_node)
                return True
            return leftAns or rightAns
            
        dfs(root, n1, path_A)
        dfs(root, n2, path_B)
        path_A = path_A[::-1]
        path_B = path_B[::-1]
        for a, b in zip(path_A, path_B):
            if a.data == b.data:
                self.res = a
        return self.res

class Solution:
    def lca(self, root, n1, n2):
        # code here
        
        def dfs(cur_node):
            if cur_node is None:
                return None
            elif cur_node.data in [n1, n2]:
                return cur_node

            leftAns = dfs(cur_node.left)
            rightAns = dfs(cur_node.right)

            if leftAns and rightAns:
                return cur_node

            return leftAns if leftAns != None else rightAns
            
        return dfs(root)