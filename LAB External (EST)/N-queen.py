def solvequeens(n):
    def issafe(row, col):
        for i in range(row):
            if board[i] == col or abs(board[i] - col) == abs(i - row):
                return False
        return True

    def solve(row):
        if row == n:
            res.append(["." * c + "Q" + "." * (n - c - 1) for c in board])
            return
        for col in range(n):
            if issafe(row, col):
                board[row] = col
                solve(row + 1)

    res = []
    board = [-1] * n
    solve(0)
    return res

result = solvequeens(4)
for solution in result:
    for row in solution:
        print(row)
    print()
