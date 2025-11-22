# https://leetcode.com/problems/create-binary-tree-from-descriptions/

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        tree_map = defaultdict()
        parent_map = defaultdict()
        root_val = 0
        for desc in descriptions:
            parent = tree_map[desc[0]] if desc[0] in tree_map else TreeNode(desc[0])
            child = tree_map[desc[1]] if desc[1] in tree_map else TreeNode(desc[1])
            if parent.val not in parent_map:
                parent_map[parent.val] = -1
                root_val = parent.val # this code can introduce the bug in the system.
            parent_map[child.val] = parent.val
            if desc[2]:
                parent.left = child
            else:
                parent.right = child
        
        print(parent_map, root_val)
        return tree_map[root_val]



# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        tree_map = defaultdict()
        parent_map = defaultdict()
        
        def get_node_from_tree(node: int) -> TreeNode:
            if node not in tree_map:
                tree_map[node] = TreeNode(node)
            return tree_map[node]
        
        def get_parent() -> int:
            for k in parent_map:
                if parent_map[k] == -1:
                    return k
            return -1

        root_val = 0
        for desc in descriptions:
            parent = get_node_from_tree(desc[0])
            child = get_node_from_tree(desc[1])
            if parent.val not in parent_map:
                parent_map[parent.val] = -1
                root_val = parent.val # this code can introduce the bug in the system.
            parent_map[child.val] = parent.val
            if desc[2]:
                parent.left = child
            else:
                parent.right = child
        
        root = tree_map[get_parent()]
        return root


def createBinaryTree(self, descriptions: list[list[int]]) -> Optional[TreeNode]:
        if len(descriptions) == 0: return None
        tree_map = defaultdict()
        parent_map = set()
        
        def get_node_from_tree(node: int) -> TreeNode:
            if node not in tree_map:
                tree_map[node] = TreeNode(node)
            return tree_map[node]
            
        def process_the_nodes(child: int, parent: int) -> None:
            if child in parent_map:
                parent_map.discard(child)
            parent_map.add(parent)

        for desc in descriptions:
            parent = get_node_from_tree(desc[0])
            child = get_node_from_tree(desc[1])
            process_the_nodes(child.val, parent.val)
            if desc[2]:
                parent.left = child
            else:
                parent.right = child
        print(parent_map)
        return root

https://leetcode.com/problems/create-binary-tree-from-descriptions/
