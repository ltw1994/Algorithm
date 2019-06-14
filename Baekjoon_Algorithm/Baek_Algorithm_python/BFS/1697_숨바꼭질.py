from collections import deque


def BFS() :

    global K

    while(True) :

        tmp = queue.popleft()
        current = tmp
        #print(current, count)

        if current == K :
            return visited[current]


        minus = current - 1
        plus = current + 1
        twice = 2 * current
        visit(current, minus)
        visit(current, plus)
        visit(current, twice)


def visit(cur, nex) :

    if maxRange >= nex >= 0 and (visited[nex] == 0 or visited[nex] > 1 + visited[cur]) :
        visited[nex] = visited[cur] + 1
        queue.append(nex)

if __name__ == "__main__" :
    N, K =  map(int,input().split())
    queue = deque()
    queue.append(N)
    maxRange = 100000
    visited = [0] * 100001
    result = BFS()

    print(result)