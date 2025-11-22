class Solution:
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        self.ans = 0
        def dfs(root: Optional[TreeNode]):
            if not root: return defaultdict(int)
            if not root.left and not root.right:
                count = defaultdict(int)
                count[1] = 1
                return count

            leftdict = dfs(root.left)
            rightdict = dfs(root.right)

            for d1 in leftdict:
                for d2 in rightdict:
                    if d1 + d2 <= distance:
                        self.ans += (leftdict[d1] * rightdict[d2])

            alldict = defaultdict(int)
            for d in leftdict:
                if d + 1 <= distance:
                    alldict[d+1] = leftdict[d]
            for d in rightdict:
                if d + 1 <= distance:
                    alldict[d+1] += rightdict[d]
            return alldict
        
        dfs(root)
        return self.ans


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: Optional[TreeNode], distance: int) -> int:
        self.ans = 0
        def dfs(root: Optional[TreeNode]):
            if not root:
                return []
            if not root.left and not root.right:
                return [1]
            leftLst = dfs(root.left)
            rightLst = dfs(root.right)
            for d_l in leftLst:
                for d_r in rightLst:
                    if d_r + d_l <= distance:
                        self.ans += 1
            allLst = leftLst + rightLst
            return [d + 1 for d in allLst]
        
        dfs(root)
        return self.ans
        
        