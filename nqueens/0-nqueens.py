#!/usr/bin/python3
"""N-Queens Module"""


def nQueens(n):
    """Solves the N-Queens problem and returns all distinct solutions.

    Args:
                    n (int): The size of the chessboard and the number
                    of queens.

    Returns:
                    list: A list of lists, where each inner list represents
                    a valid arrangement of queens on the chessboard.
    """
    def is_not_under_attack(row, col):
        for prev_row in range(row):
            if (board[prev_row] == col or
                    board[prev_row] - prev_row == col - row or
                    board[prev_row] + prev_row == col + row):
                return False
        return True

    def place_queen(row):
        if row == n:
            solution = []
            for r in range(n):
                line = ['.'] * n
                line[board[r]] = 'Q'
                solution.append(''.join(line))
            solutions.append(solution)
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
