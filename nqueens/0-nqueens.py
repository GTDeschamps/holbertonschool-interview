#!/usr/bin/python3
# -*- coding: utf-8 -*-

import sys


def is_valid(board, row, col, n):
    for i in range(row):
        if board[i][1] == col or \
           board[i][1] - i == col - row or \
           board[i][1] + i == col + row:
            return False
    return True


def solve_n_queens(n, row=0, board=[]):
    if row == n:
        print(board)
        return
    for col in range(n):
        if is_valid(board, row, col, n):
            solve_n_queens(n, row + 1, board + [[row, col]])

if len(sys.argv) != 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    n = int(sys.argv[1])
except ValueError:
    print("N must be a number")
    sys.exit(1)

if n < 4:
    print("N must be at least 4")
    sys.exit(1)

solve_n_queens(n)
