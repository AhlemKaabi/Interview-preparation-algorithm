#!/usr/bin/python3

if __name__ == '__main__':
    def solveNQueens(n):
        solutions = []
        state = []
        search(state, solutions, n)
        return solutions

    def is_valid_state(state, n):
        # check if it is a valid solution
        return len(state) == n

    def get_candidates(state, n):
        print("get candidate starting state", state)
        if not state:
            return range(n)

        # find the next position in the state to populate
        position = len(state)
        candidates = set(range(n))
        # prune down candidates that place the queen into attacks
        for row, col in enumerate(state):
            print("starting the loop")
            print("the row:", row, "the col", col)
            print("the statring candidate", candidates)
            # discard the column index if it's occupied by a queen
            candidates.discard(col)
            print("after first discard (col) coandidate:", candidates)
            dist = position - row
            print("the distance:", dist)
            # discard diagonals
            candidates.discard(col + dist)
            candidates.discard(col - dist)
            print("after second discard (diagonal) and the enf of iteration candidate:", candidates)
        # the final candidates list is the possible rows index that we can place a safe queen!
        return candidates

    def search(state, solutions, n):
        if is_valid_state(state, n):
            state_string = state_to_string(state, n)
            solutions.append(state_string)
            return
        candidates = get_candidates(state, n)
        print("the return of the get_candidte function", candidates)
        for candidate in candidates:
            # recurse
            state.append(candidate)
            print(state)
            search(state, solutions, n)
            state.remove(candidate)
            print(state)


    def state_to_string(state, n):
        # ex. [1, 3, 0, 2]
        # output: [".Q..","...Q","Q...","..Q."]
        ret = []
        for i in state:
            string = '.' * i + 'Q' + '.' * (n - i - 1)
            ret.append(string)
        return ret

    print(solveNQueens(4))