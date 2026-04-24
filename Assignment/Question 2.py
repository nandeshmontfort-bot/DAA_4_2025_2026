def hamiltonianCycle(graph):
    n = len(graph)
    path = [-1] * n
    path[0] = 0

    def isSafe(v, pos):
        if graph[path[pos - 1]][v] == 0:
            return False
        if v in path:
            return False
        return True

    def backtrack(pos):
        if pos == n:
            return graph[path[pos - 1]][path[0]] == 1
        for v in range(1, n):
            if isSafe(v, pos):
                path[pos] = v
                if backtrack(pos + 1):
                    return True
                path[pos] = -1
        return False
    if backtrack(1):
        print("Hamiltonian Cycle exists:")
        print(path + [path[0]])
        return True
    else:
        print("No Hamiltonian Cycle")
        return False

graph = [
    [0, 1, 1, 0],
    [1, 0, 1, 1],
    [1, 1, 0, 1],
    [0, 1, 1, 0]
]

hamiltonianCycle(graph)
