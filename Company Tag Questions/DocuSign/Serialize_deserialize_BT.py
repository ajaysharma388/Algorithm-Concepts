class Codec:
    def serialize(self, root):
        if root is None:
            return "N|"

        cur = str(root.val) + "|" 
        left = self.serialize(root.left)
        right = self.serialize(root.right)
        cur += left
        cur += right
        return cur

    def deserialize(self, data):
        buf = data.split("|")
        self.idx = 0
        def dfs():
            if buf[self.idx] == 'N' or buf[self.idx] == '':
                self.idx += 1
                return None
            root = TreeNode(int(buf[self.idx]))
            self.idx += 1
            root.left = dfs()
            root.right = dfs()
            return root
        return dfs()