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

def find_all(place) :
    print("@", place)
    q = deque()
    for aaa in range(len(place)) :
        q.append(place[aaa])
        check = []
        for qq in range(N) :
            check.append(False)
        print("!!!")
        print(place[aaa])
        check[place[aaa]] = True
        changed = True
        while(q) :
            a = q.popleft()
            if changed == False :
                break
            changed = False
            for m in place :
                print(a, m-1)
                if graph[a-1][m-1] == 1 and check[m-1] == False:
                    q.append(m-1)
                    check[m-1] = True
                    changed = True
        for qq in place :
            if check[qq-1] == False :
                print(check)
                print("@@@@@@@@",place)
                return False
    return True



def find_valid(place1, place2) :
    global cnt
    global N
    cnt1 = 0
    cnt2 = 0
    bool1 = False
    bool2 = False
    peo1 = 0
    peo2 = 0
    print(place1)

    if len(place1) == 1 :
        bool1 = True
    elif len(place1) == N :
        bool1 = False
    else :
        for a in place1 :
            for b in place1 :
                if graph[a-1][b-1] == 1 :
                    cnt1 += 1
                    break
        if cnt1 == len(place1) :
            bool1 = find_all(place1)

    if len(place2) == N :
        bool2 = False
    elif len(place2) == 1 :
        bool2 = True
    else :
        for a in place2 :
            for b in place2 :
                if graph[a-1][b-1] == 1 :
                    cnt2 += 1
                    break
        if cnt2 == len(place2) :
            bool2 = find_all(place2)

    if bool1 == True and bool2 == True  :
        cnt += 1
        for a in place1 :
            peo1 += nums[a-1]
        for b in place2 :
            peo2 += nums[b-1]
        result.append(abs(peo2 - peo1))
        print("-", place1)
        return
    else :
        return


if __name__ == "__main__" :
    N = int(input())
    cnt = 0
    result = []
    nums = list(map(int, input().split()))
    graph = [[0 for i in range(N)] for j in range(N)]
    for i in range(N) :
        tmp_lst = list(map(int, input().split()))
        for j in range(len(tmp_lst)) :
            if j == 0 :
                continue
            else :
                graph[i][tmp_lst[j]-1] = 1
    comb = set()
    for i in range(1, N+1) :
        comb.add(i)
    for i in range(1, N) :
        com = combinations(comb, i)
        com_lst = list(com)
        com_lst.sort()
        for j in range(len(com_lst)) :
            place2 = [k for k in range(1, N + 1)]
            place1 = list(com_lst[j])
            for p in place1 :
                place2.remove(p)
            find_valid(place1, place2)

#    print(cnt)
#    print(result)
    if cnt == 0 :
        print(-1)
    else :
        print(cnt)
        print(result)
        print(min(result))

''' 

6
2 2 2 2 2 2
1 3
1 4
1 1
1 2
1 6
1 5

'''