#!/usr/bin/python3
import sys

# Usage
if len(sys.argv) != 2:
    print("Usage: nqueens N")
    exit(1)
# N must be an integer greater or equal to 4:

# If N is not an integer
if not isinstance(int(sys.argv[1]), int):
    print("N must be a number")
    exit(1)
# If N is smaller than 4
if int(sys.argv[1]) < 4:
    print("N must be at least 4")
    exit(1)

n = int(sys.argv[1])

def solveNQueens(n):
    solutions = []
    state = []
    search(state, solutions, n)
    return solutions

def is_valid_state(state, n):
    # check if it is a valid solution
    return len(state) == n

def get_candidates(state, n):
    # print("get candidate starting state", state)
    if not state:
        return range(n)

    # find the next position in the state to populate
    position = len(state)
    candidates = set(range(n))
    # prune down candidates that place the queen into attacks
    for row, col in enumerate(state):
        # print("starting the loop")
        # print("the row:", row, "the col", col)
        # print("the statring candidate", candidates)
        # discard the column index if it's occupied by a queen
        candidates.discard(col)
        # print("after first discard (col) coandidate:", candidates)
        dist = position - row
        # print("the distance:", dist)
        # discard diagonals
        candidates.discard(col + dist)
        candidates.discard(col - dist)
        # print("after second discard (diagonal) and the enf of iteration candidate:", candidates)
    # the final candidates list is the possible rows index that we can place a safe queen!
    return candidates

def search(state, solutions, n):
    if is_valid_state(state, n):
        state_string = state_to_coor(state, n)
        solutions.append(state_string)
        # print(solutions)
        return
    candidates = get_candidates(state, n)
    # print("the return of the get_candidte function", candidates)
    for candidate in candidates:
        # recurse
        state.append(candidate)
        search(state, solutions, n)
        state.remove(candidate)


def state_to_coor(state, n):
    ret = []
    for x, y in enumerate(state):
        ret.append([x, y])
    return ret

for solution in solveNQueens(n):
    print(solution)