import sys
sys.setrecursionlimit(10**6)

def DFS(x, y) :
    global num

    while(True) :
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]
          #  print(nx, ny)
            if nx < 0 or nx >= M or ny < 0 or ny >=  N or graph[ny][nx] != 1 or visited[ny][nx] != 0 :
                continue
            elif graph[ny][nx] == 1 :
                graph[ny][nx] = num
                visited[ny][nx] = 1
                DFS(nx, ny)
        graph[y][x] = num
        visited[y][x] = 1
        break


if __name__ == "__main__" :
    T = int(input())
    for _ in range(T) :
        M, N, K = map(int, input().split())
        graph = [[0 for i in range(M)] for j in range(N)]
        visited = [[0 for i in range(M)] for j in range(N)]
        for __ in range(K) :
            x, y = map(int, input().split())
            graph[y][x] = 1
        num = 2

        dx = [1, 0, -1, 0]
        dy = [0, -1, 0, 1]

        for j in range(M) :
            for i in range(N) :
                if graph[i][j] == 1 and visited[i][j] == 0 :
                    DFS(j, i)
                    num += 1

        '''for i in range(N) :
            print(graph[i])
            print('\n')
            '''
        num -= 2
        print(num)
