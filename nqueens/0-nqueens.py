#!/usr/bin/python3
"""N-Queens Module"""
import sys


def nQueens(n):
    """Solves the N-Queens problem and returns all distinct solutions.

    Args:
                    n (int): The size of the chessboard and the number
                    of queens.

    Returns:
                    list: A list of solutions; each solution is a list of
                    [row, col] pairs indicating queen positions.
    """
    def is_not_under_attack(row, col):
        for prev_row in range(row):
            prev_col = board[prev_row]
            if prev_col == col or abs(prev_col - col) == abs(prev_row - row):
                return False
        return True

    def place_queen(row):
        if row == n:
            solutions.append([[r, board[r]] for r in range(n)])
            return
        for col in range(n):
            if is_not_under_attack(row, col):
                board[row] = col
                place_queen(row + 1)
                board[row] = -1

    solutions = []
    board = [-1] * n
    place_queen(0)
    return solutions


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = nQueens(n)
    for sol in solutions:
        print(sol)
