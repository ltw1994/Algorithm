from collections import deque

def BFS() :

    while(True) :

        if N == 1 and M == 1 :
            return 1

        current = queue.popleft()

        y, x, current_count = current[0], current[1], current[2]

        #print("current x =", x, "current y =", y)

        for i in range(4) :
            count = current_count

            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or nx >= M or ny < 0 or ny >= N or visited_node[ny][nx] == 1 or graph[ny][nx] == 0  :
                continue

            elif nx == M-1 and ny == N-1 :
                count += 1
                return count

            else :
                count += 1
                #print("current x =", nx, "current y =", ny, "count =", count)
                visited_node[ny][nx] = 1
                queue.append([ny, nx, count])


if __name__ == "__main__" :
    N, M = map(int, input().split())
    graph = []
    for i in range(N) :
        tmp = str(input())
        tmp_list = list(tmp)
        graph.append(tmp_list)

   # print(graph)
    for i in range(N) :
        for j in range(M) :
            graph[i][j] = int(graph[i][j])

    visited_node = [[0 for _ in range(M)] for e in range(N)]
    visited_node[0][0] = 1


    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]

    count = 0

    queue = deque()

    init = [0,0,1]

    queue.append(init)

    result = BFS()
    print(result)
