def solveNQueens(n):
    def backtrack(row):
        if row == n:
            result.append(["".join(r) for r in board])
            return 1

        count = 0
        for col in range(n):
            if col in cols or (row - col) in diag1 or (row + col) in diag2:
                continue
            board[row][col] = 'Q'
            cols.add(col)
            diag1.add(row - col)
            diag2.add(row + col)

            count += backtrack(row + 1)

            board[row][col] = '.'
            cols.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)

        return count

    board = [['.'] * n for _ in range(n)]
    cols = set()
    diag1 = set()
    diag2 = set()
    result = []

    total_count = backtrack(0)
    return result, total_count

solutions, count = solveNQueens(4)
print("Total Solutions:", count)
print("\nSolutions:")
for sol in solutions:
    for row in sol:
        print(row)
    print()
