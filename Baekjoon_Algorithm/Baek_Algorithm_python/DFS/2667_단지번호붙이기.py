def DFS(x, y) :
    global num

    while(True) :
        for i in range(4) :
            nx = x + dx[i]
            ny = y + dy[i]

            if ny < 0 or ny >= N or nx <0 or nx >= N or graph[ny][nx] != 1 or visited[ny][nx] != 0 :
                continue

            elif graph[ny][nx] == 1 :
                visited[ny][nx] = 1
                graph[ny][nx] = num
                DFS(nx, ny)

        visited[y][x] = 1
        graph[y][x] = num
        break



if __name__ == "__main__" :

    N = int(input())
    graph = []
    for _ in range(N) :
        graph.append(list(str(input())))


    dx = [1,0,-1,0]
    dy = [0,-1,0,1]

    visited = [[0 for i in range(N)] for j in range(N)]

    for i in range(N) :
        for j in range(N) :
            graph[j][i] = int(graph[j][i])


    num = 2

    for i in range(N) :
        for j in range(N) :
            if graph[j][i] == 1 :
                DFS(i, j)
                num += 1
              #  print(graph)
               # print("x = ", i, "y = ", j)
                #print(num)
    num -= 1
    count_num = []
    num_result = num - 1
    while(num > 1 ) :
        tmp = 0
        for i in range(N) :
            for j in range(N) :
                if graph[j][i] == num :
                    tmp += 1
        count_num.append(tmp)
        num -= 1

    count_num = sorted(count_num)
    #reversed(count_num)
    print(num_result)
    for i in range(len(count_num)) :
        print(count_num[i])

