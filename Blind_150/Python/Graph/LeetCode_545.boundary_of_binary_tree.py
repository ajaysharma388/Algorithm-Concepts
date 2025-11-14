class Solution:
        
    def boundaryTraversal(self, root):
        res = []
        if root == None:
            return res
        else:
            res.append(root.data)
        
        def inorder(root):
            if root == None:
                return
            if root.left == None and root.right == None:
                res.append(root.data)
                return
            inorder(root.left)
            inorder(root.right)
            return 
        
        def traverse(root, is_left):
            if root == None or (root.left == None and root.right == None):
                return
            
            if is_left:
                res.append(root.data)
                if root.left == None:
                    traverse(root.right, True)
                else:
                    traverse(root.left, True)
            else:
                if root.right == None:
                    traverse(root.left, False)
                else:
                    traverse(root.right, False)
                res.append(root.data)
            return
        
        traverse(root.left, True)
        inorder(root.left)
        inorder(root.right)
        traverse(root.right, False)
        
        return res
        