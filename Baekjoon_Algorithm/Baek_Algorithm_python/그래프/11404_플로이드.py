
def FLOYD() :
    for num in range(N) :
        for y in range(N) :
            for x in range(N) :
                if graph[y][num] == 1 and graph[num][x] == 1 :
                    graph[y][x] = 1



if __name__ == "__main__" :
    N, M = map(int,input().split())
    graph = [[0 for i in range(N)] for j in range(N)]

    for _ in range(M) :
        x, y = map(int, input().split())
        x -= 1
        y -= 1
        graph[y][x] = 1

    rank = [0 for _ in range(N)]
    FLOYD()

    res = 0
    for y in range(N) :
        cnt = 0
        for x in range(N) :
            if y != x :
                cnt += (graph[y][x] + graph[x][y])
   #     print(cnt)
        if cnt == N-1 :
            res += 1
  #  print(graph)
    print(res)
'''
    for num in range(N) :
        for x in range(N) :
            if graph[num][x] == 1 :
                for k in range(N) :
                    if graph[x][k] == 1 :
                        graph[num][k] = 1
        for y in range(N) :
            if graph[y][num] == 1 :
                for k in range(N) :
                    if graph[k][y] == 1 :
                        graph[k][num] = 1

    print(graph)
'''


'''

    for num in range(N) :
        count = 0
        for y in range(N) :
            if graph[y][num] == 1 and y != num :
                count += 1
        for x in range(N) :
            if graph[num][x] == 1 and x != num :
                count += 1
                

        if count == N-1 :
            rank[num] = 1

    print(rank.count(1))
'''