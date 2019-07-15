from collections import deque
import sys
from copy import deepcopy
sys.setrecursionlimit(10**6)

def BFS(x, y) :
    while(True) :
        tmp = queue.popleft()
        current, count = tmp[0], tmp[1]
        tmp_graph = deepcopy(current)
        for i in range(4)
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx > M-1 or ny > N-1 or graph[ny][nx] == 0 :
                continue
            for i in range(N) :
                for j in range(M) :



if __name__ == "__main__" :
    M, N = map(int, input().split())
    graph = []

    dx = [1,0,-1,0]
    dy = [0,-1,0,1]
    for _ in range(N) :
        tmp = input().split()
        graph.append(tmp)

    for i in range(N) :
        for j in range(M) :
            graph[i][j] = int(graph[i][j])

    queue = deque()
    ini = 0
    queue.append([graph,ini])