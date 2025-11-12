class Solution:
    def solve(self, board: List[List[str]]) -> None:
        row, col = len(board), len(board[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]

        def isBorderCell(r: int, c: int) -> bool:
            return r in [0, row-1] or c in [0, col-1]

        def capture(r: int, c: int) -> None:
            if r < 0 or c < 0 or r >= row or c >= col:
                return
            elif board[r][c] != "O":
                return
            board[r][c] = "T"
            for (dr, dc) in directions:
                capture(r + dr, c + dc)

        for i in range(row):
            for j in range(col):
                if board[i][j] == "O" and isBorderCell(i, j): 
                    capture(i, j)

        for i in range(row):
            for j in range(col):
                if board[i][j] == "O":
                    board[i][j] = "X"

        for i in range(row):
            for j in range(col):
                if board[i][j] == "T":
                    board[i][j] = "O"
        return