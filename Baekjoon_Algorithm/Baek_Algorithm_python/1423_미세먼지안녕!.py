from copy import deepcopy


def dust() :
    for y in range(R) :
        for x in range(C) :
            count = 0
            value = graph[y][x]
            expand = value // 5
            for i in range(4) :
                nx = x + dx[i]
                ny = y + dy[i]
                if graph[y][x] == -1 :
                    continue
                if nx < 0 or ny < 0 or nx > C-1 or ny > R-1 or graph[ny][nx] == -1 :
                    continue
                new_graph[ny][nx] += expand
                count += 1
            new_graph[y][x] += value - (expand * count)


def up_clean(b) :
    global C
    for y in range(b):
        for x in range(C) :
            if graph[y][x] == -1 :
                new_graph[y][x] = -1
            elif y == b-1 and x < C-1 :
                new_graph[y][x+1] = graph[y][x]
            elif y > 0 and x == C-1 :
                new_graph[y-1][x] = graph[y][x]
            elif y == 0 and x > 0 :
                new_graph[y][x-1] = graph[y][x]
            elif y >= 0 and y < b-1 and x == 0 and graph[y+1][x] != -1:
                new_graph[y+1][x] = graph[y][x]
            else :
                new_graph[y][x] = graph[y][x]

def down_clean(b) :
    global C, R
    for y in range(b,R) :
        for x in range(C) :
            if graph[y][x] == -1 :
                new_graph[y][x] = -1
            elif y == b and x < C-1 :
                new_graph[y][x+1] = graph[y][x]
            elif y < R-1 and x == C-1 :
                new_graph[y+1][x] = graph[y][x]
            elif y == R-1 and x > 0 :
                new_graph[y][x-1] = graph[y][x]
            elif y <= R-1 and y > b+1 and x==0 and graph[y-1][x] != -1 :
                new_graph[y-1][x] = graph[y][x]
            else :
                new_graph[y][x] = graph[y][x]





if __name__ == "__main__" :

    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]

    R, C, T = map(int, input().split())
    graph = []
    for _ in range(R) :
        line = input().split()
        graph.append(line)

    for i in range(R) :
        for j in range(C) :
            graph[i][j] = int(graph[i][j])

    for i in range(R):
        for j in range(C):
            if graph[i][j] == -1:
                b = i
                break

    for aa in range(T) :
        new_graph = [[0 for _ in range(C)] for a in range(R)]
        dust()
        graph = deepcopy(new_graph)
        new_graph = [[0 for _ in range(C)] for a in range(R)]
        up_clean(b)
        down_clean(b)
        graph = deepcopy(new_graph)

    for i in range(R) :
        for j in range(C) :
            if graph[i][j] == -1 :
                b = i
                break

    result = 0
    for i in range(R) :
        for j in range(C) :
            if graph[i][j] >= 0 :
                result += graph[i][j]
    print(result)
