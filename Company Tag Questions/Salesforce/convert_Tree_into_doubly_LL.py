class Solution:
    def bToDLL(self,root):
        # Code here
        inorder = []
        def traverse_inorder(root):
            if root is None:
                return
            elif root.left == None and root.right == None:
                inorder.append(root)
                return
            traverse_inorder(root.left)
            inorder.append(root)
            traverse_inorder(root.right)
            return
        traverse_inorder(root)
        
        head = None
        tail = None
        for node in inorder:
            if head == None:
                head = node
                tail = node
                head.left = None
            else:
                tail.right = node
                node.left = tail
                tail = node
        tail.right = None
        return head