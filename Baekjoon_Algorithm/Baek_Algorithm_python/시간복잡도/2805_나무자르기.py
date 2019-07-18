import sys
sys.setrecursionlimit(10 ** 6)

def cutwood(H) :

    global mx, mn, N, M, find, result

    wood = 0
    for i in range(N) :
        if A[i] - H > 0 :
            wood += A[i] - H

   # print(H, wood)
  #  print("-")

    if wood > M and find == False:
        num = (H + mx) / 2
        num = int(num)
        cutwood(num)

    elif wood < M and find == True :
        cutwood(H-1)

    elif wood >= M and find == True :
        num = int(H)
      #  print("!")
        result = num


    elif wood <= M :
        find = True
        cutwood(H)






if __name__ == "__main__" :
    N, M = map(int, input().split())
    A = list(map(int, input().split()))

    mx = max(A)
    mn = min(A)
    H = 0
    find = False
    cutwood(H)
    print(result)