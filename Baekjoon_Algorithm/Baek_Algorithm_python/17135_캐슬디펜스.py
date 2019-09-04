import copy
from collections import deque

def combinations(iterable, r):
    # combinations('ABCD', 2) --> AB AC AD BC BD CD
    # combinations(range(4), 3) --> 012 013 023 123
  # print(iterable)
    pool = tuple(iterable)
  #  print(pool)
    n = len(pool)
    if r > n:
        return
    indices = list(range(r))
    yield tuple(pool[i] for i in indices)
    while True:
        for i in reversed(range(r)):
            if indices[i] != i + n - r:
                break
        else:
            return
        indices[i] += 1
        for j in range(i+1, r):
            indices[j] = indices[j-1] + 1
        yield tuple(pool[i] for i in indices)


def move_down() :
    global N, M
    for j in range(N-1, 0, -1) :
        for i in range(M) :
            graph[j][i] = graph[j-1][i]
    for i in range(M) :
        graph[0][i] = 0
        graph[N][i] = 0


def kill_enemy(a) :
    global D
    tmp_distance = 10000
    tmp_lft = 10000
    tmp_x, tmp_y = 1000, 1000
    for j in range(N) :
        for i in range(M) :
           # print(i, j)
            if graph[j][i] == 1 :
                lft = a - i
                distance = abs(N - j) + abs(a - i)
           #     print(distance)
                if distance <= D :
                    if distance < tmp_distance :
                        tmp_x, tmp_y, tmp_distance, tmp_lft = i, j, distance, lft
                    elif distance == tmp_distance and lft > tmp_lft :
                        tmp_x, tmp_y, tmp_distance, tmp_lft = i, j, distance, lft
    if tmp_distance == 1000 :
        remove_lst.append([tmp_x, tmp_y])
        return
    else :
        remove_lst.append([tmp_x, tmp_y])
        return



if __name__ == "__main__" :
    N, M, D = map(int, input().split())
    graph = []
    result = []
    for _ in range(N) :
        tmp = list(map(int, input().split()))
        graph.append(tmp)
    tmp = [0 for i in range(M)]
    graph.append(tmp)
    comb = set()
    for i in range(N) :
        comb.add(i)
    com = combinations(comb, 3)
    com_lst = list(com)
    tmp_graph = copy.deepcopy(graph)
    for lst in com_lst :
        graph = copy.deepcopy(tmp_graph)
        cnt = 0
        lst = list(lst)
        a = lst[0]
        b = lst[1]
        c = lst[2]
        #print("a =", a, "b =", b, "c =", c)
        for _ in range(N) :
        #    print(graph)
            remove_lst = []
            kill_enemy(a)
            kill_enemy(b)
            kill_enemy(c)
            for _ in range(3) :
         #       print(remove_lst)
                x, y = remove_lst[0][0], remove_lst[0][1]
          #      print(y, x)
                if x == 1000 :
                    result.append(-1)
                elif graph[y][x] == 1 :
                    cnt += 1
           #         print("cnt = ", cnt)
                    graph[y][x] = 0
            #    print(graph)
                del remove_lst[0]
            move_down()
       #     print(graph)
        result.append(cnt)
    #print(result)
    print(max(result))