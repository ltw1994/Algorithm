

def Right() :
    return

def Left() :
    return

def Down() :
    return

def Up() :
    return




def DFS(cnt) :
    if cnt == N :
        for y in range(N) :
            for x in range(N) :
        for i in range(N) :
            if dfs_lst[i] == 0 :
                Right()
            elif dfs_lst[i] == 1 :
                Left()
            elif dfs_lst[i] == 2 :
                Down()
            else :
                Up()

    for i in range(4) :
        dfs_lst[cnt] = i
        DFS(cnt+1)




if __name__ == "__main__" :
    T = int(input())
    for t in range(T) :
        N = int(input())
        graph = []
        num_core = 0
        for i in range(N) :
            lst = list(map(int, input().split()))
            graph.append(lst)
        dfs_lst = [0 for i in range(num_core)]

