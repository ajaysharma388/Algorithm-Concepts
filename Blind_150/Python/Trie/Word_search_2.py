class Trie:
    def __init__(self, ch: chr, isTerminal: bool):
        self.val = ch
        self.isTerminal = isTerminal
        self.childs = dict()
        
class Solution:
    def __init__(self):
        self.root = Trie('\0', False)
        self.dx = [-1, 0, 1, 0]
        self.dy = [ 0, 1, 0,-1]
      
    def add(self, word: str) -> None:
        cur = self.root
        for ch in word:
            if ch not in cur.childs:
                cur.childs[ch] = Trie(ch, False)
            cur = cur.childs[ch]
        cur.isTerminal = True

    def add_words(self, words: list[str]) -> None:
        for word in words:
            self.add(word)
    
    def word_search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            if ch not in cur.childs:
                return False
            cur = cur.childs[ch]
        return cur.isTerminal
    
    def dfs(self, cur: Trie, board: list[list[str]], i: int, j: int, pre: str) -> None:
        if cur.isTerminal: 
    	    self.result.add(pre)

        if i < 0 or j < 0 or i >= len(board) or j >= len(board[0]):
            return    
        elif self.vis[i][j]:
            return

        ch = board[i][j]
        if ch not in cur.childs: 
            return
        
        pre += ch
        self.vis[i][j] = True
        for (x, y) in zip(self.dx, self.dy):
            self.dfs(cur.childs[board[i][j]], board, x+i, y+j, pre)

        pre = pre[:-1]
        self.vis[i][j] = False
        return

    def findWords(self, board: list[list[str]], words: list[str]) -> list[str]:
        self.add_words(words)
        self.result = set()
        self.vis = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        for i in range(0, len(board)):
        	for j in range(0, len(board[i])):
        	    self.dfs(self.root, board, i, j, "")
        return list(self.result)

def main():
	n = int(input())
	words = list()
	for i in range(0, n):
		words.append(input())

	x = int(input())
	y = int(input())
	board = list()
	for i in range(0, x):
		cur = list()
		for j in range(0, y):
			cur.append(input())
		board.append(cur)
	
	solution = Solution()
	res = solution.findWords(board, words)
	print(res)

if __name__ == "__main__":
	main()
	
# Sample Input:
# 6
# cate
# bat
# cat
# back
# backend
# stack
# 4
# 4
# a
# b
# c
# d
# s
# a
# a
# t
# a
# c
# k
# e
# a
# c
# d
# n

# Sample Output:
# ['backend', 'cate', 'cat', 'back']