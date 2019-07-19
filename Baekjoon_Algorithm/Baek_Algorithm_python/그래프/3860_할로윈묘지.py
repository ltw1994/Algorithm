from collections import deque

def BFS() :
    global t
    tmp = q.pop()
    y = tmp[1]
    x = tmp[0]
    count = tmp[2]
    while(True) :
        for i in range(4) :
            ny = y + dy[i]
            nx = x + dx[i]
            if ny == H-1 and nx == W-1 :
                return count
            elif ny > H-1 or ny < 0 or nx > W-1 or nx < 0 or graph[ny][nx] == 1 :
                continue
            elif graph[ny][nx] != (0 and 1) :
                num = graph[ny][nx]
                for yy in range(H) :
                    for xx in range(W) :
                        if graph[y][x] == (num + 1) :
                            ny = yy
                            nx = xx
                            count += t
                            q.append(nx, ny, count)


            q.append(nx,ny)



if __name__ == "__main__" :
    dx = [1, 0, -1, 0]
    dy = [0, -1, 0, 1]
    W, H = map(int, input().split())
    G = int(input())
    graph = [[0 for x in range(W)] for y in range(H)]
    for _ in range(G) :
        x, y = map(int, input().split())
        graph[y][x] = 1
    G = int(input())
    if G != 0 :
        count = 2
        for _ in range(G) :
            x1, y1, x2, y2, t = map(int,input().split())
            graph[y1][x1] = count
            count += 1
            graph[y2][x2] = count
            count += 1
    q = deque()
    q.append([0,0,0])
    result = BFS()
    print(result)