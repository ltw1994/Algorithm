import copy

def right(x, y) :
    while (True):
        x += 1
        if x < 0 or x > M - 1 or graph[y][x] == 6:
            return
        if graph[y][x] != (1 or 2 or 3 or 4 or 5):
            graph[y][x] = 7

def left(x, y) :

    while (True):
        x -= 1
        if x < 0 or x > M - 1 or graph[y][x] == 6:
            return
        if graph[y][x] != (1 or 2 or 3 or 4 or 5):
            graph[y][x] = 7


def up(x, y) :

    while (True):
        y += 1
        if y < 0 or y > N - 1 or graph[y][x] == 6:
            return
        if graph[y][x] != (1 or 2 or 3 or 4 or 5):
            graph[y][x] = 7

def down(x, y) :
    while (True):
        y -= 1
        if y < 0 or y > N - 1 or graph[y][x] == 6:
            return
        if graph[y][x] != (1 or 2 or 3 or 4 or 5):
            graph[y][x] = 7

def game(x, y, num, di) :
    if num == 1 :
        if di == 0 :
          #  print("!")
            right(x, y)
        elif di == 1 :
            down(x, y)
        elif di == 2 :
            left(x, y)
        elif di == 3 :
            up(x, y)
    elif num == 2 :
        if di == 2 or di == 3 :
            return
        elif di == 0 :
            right(x, y)
            left(x, y)
        elif di == 1 :
            down(x, y)
            up(x, y)
    elif num == 3 :
        if di == 0 :
            up(x, y)
            right(x, y)

        elif di == 1 :
            right(x, y)
            down(x, y)

        elif di == 2 :
            down(x, y)
            left(x, y)

        else :
            left(x, y)
            up(x, y)

    elif num == 4 :
        if di == 0 :
            left(x, y)
            up(x, y)
            right(x, y)

        elif di == 1 :
            up(x, y)
            right(x, y)
            down(x, y)

        elif di == 2 :
            right(x, y)
            down(x, y)
            left(x, y)

        else :
            down(x, y)
            left(x, y)
            up(x, y)

    elif num == 5 :
        if di == 0 :
            left(x, y)
            up(x, y)
            right(x, y)
            down(x, y)
        else :
            return
    return





def DFS(cnt) :
    if (cnt == len(cctvs)) :
     #   print(cctvs)
        for z in range(N) :
            for x in range(M) :
                graph[z][x] = save[z][x]
        for a in range(len(cctvs)) :
            game(cctvs[a][0], cctvs[a][1], cctvs[a][2], cctvs[a][3])
        temp = 0
       # print(graph)
        for c in range(N):
            for d in range(M) :
                if graph[c][d] == 0 :
                    temp += 1

        result.append(temp)

    else :
        for b in range(4) :
            cctvs[cnt][3] = b
            DFS(cnt+1)

if __name__ == "__main__" :
    N, M = map(int, input().split())
    graph = []
    cctvs = []
    result = []
    for i in range(N) :
        line = list(map(int, input().split()))
        graph.append(line)
    for i in range(N) :
        for j in range(M) :
            if graph[i][j] == 1 or graph[i][j] == 2 or graph[i][j] == 3 or graph[i][j] == 4 or graph[i][j] == 5  :
                cctvs.append([j, i, graph[i][j], 0])
    save = copy.deepcopy(graph)
    DFS(0)
   # print(result)
    print(min(result))
