import sys



if __name__ == "__main__" :
    N, M = map(int, sys.stdin.readline().split())
    lst = list(map(int, sys.stdin.readline().split()))
   # print(N, " ", M)
   # print(lst)
    for i in range(1, N) :
        lst[i] += lst[i-1]
    for _ in range(M) :
        a, b = map(int, sys.stdin.readline().split())
        if a == 1 :
            print(lst[b-1])
       ## elif a == b :
         ##   print()
        else :
            print(lst[b-1]-lst[a-2])