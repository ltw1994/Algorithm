from collections import deque

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]


def check_dir(current_dir, cnt) :
    if len(dir_lst) == 0 :
        return current_dir
    else :
        time = int(dir_lst[0][0])
        if cnt == time :
            ch = dir_lst[0][1]
            del dir_lst[0]
            if current_dir == 0 and ch == "D" :
                return 1
            elif current_dir == 0 and ch == "L" :
                return 3
            elif current_dir == 1 and ch == "D" :
                return 2
            elif current_dir == 1 and ch == "L" :
                return 0
            elif current_dir == 2 and ch == "D" :
                return 3
            elif current_dir == 2 and ch == "L" :
                return 1
            elif current_dir == 3 and ch == "D" :
                return 0
            elif current_dir == 3 and ch == "L" :
                return 2
    return current_dir
def game(current_dir) :

    cnt = 0

    while(True) :
        #print("now =", now,"current_dir =",  current_dir, "snake = ", snake)

        x = now[0]
        y = now[1]

        nx = x + dx[current_dir]
        ny = y + dy[current_dir]

        if nx < 0 or ny < 0 or nx > N-1 or ny > N-1 :
            return cnt
        for p in snake :
            if ny == p[1] and nx == p[0] :
                return cnt
        snake.append([nx,ny])
        if graph[ny][nx] == 0 :
            snake.popleft()
        else :
            graph[ny][nx] = 0

        cnt += 1
        current_dir = check_dir(current_dir, cnt)
        now.append(nx)
        now.append(ny)
        del now[0]
        del now[0]




if __name__ == "__main__" :
    N = int(input())
    K = int(input())
    graph = [[0 for i in range(N)] for j in range(N)]
    for i in range(K) :
        y, x = map(int, input().split())
        graph[y-1][x-1] = 1
    L = int(input())
    dir_lst = []
    for i in range(L) :
        a, b = map(str, input().split())
        dir_lst.append([a,b])
    now = [0,0]
    snake = deque()
  #  print(graph)
    snake.append([0,0])
    result = game(0)
    print(result+1)