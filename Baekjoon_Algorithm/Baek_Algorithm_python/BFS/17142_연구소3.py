import copy


def diffuion() :
    for i in range(N) :
        for j in range(N) :
            if graph[i][j] < 100000 :
                count = 4
                while (count > 0):
                    x = j
                    y = i
                    nx = x + dx[count]
                    ny = y + dy[count]
                    if nx < 0 or ny < 0 or nx >= N or ny >= N or graph[ny][nx] >= 99999 :
                        continue
                    else :
                        graph[ny][nx] += 1





if __name__ == "__main__" :
    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]
    virus_place = []
    N, M = map(int, input().split())
    graph = []
    for i in range(N) :
        tmp_input = list(map(int, input().split()))
        graph.append(tmp_input)
    for i in range(N) :
        for j in range(N) :
            if graph[i][j] == 2 :
                virus_place.append([j, i])
