import sys


if __name__ == "__main__" :
    N, M = map(int, sys.stdin.readline().split())
    dp = [[0 for _ in range(N+1)]]
    for _ in range(N) :
        lst = [0]
        ls = list(map(int, sys.stdin.readline().split()))
        lst += ls
        dp.append(lst)
  #  print(dp)

    for i in range(1, N+1) :
        for j in range(1, N+1) :
            if i == 1 and j == 1 :
                continue
            elif j == 1 :
                dp[i][j] += dp[i-1][j]
            elif i == 1 :
                dp[i][j] += dp[i][j-1]
            else :
                dp[i][j] += (dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1])

#    print(dp)
    for k in range(M) :
        y1, x1, y2, x2 = map(int, sys.stdin.readline().split())
        print(dp[y2][x2] - dp[y2][x1-1] - dp[y1-1][x2] + dp[y1-1][x1-1])
        '''
        if x1 == 1 and y1 == 1 :
       #     print(k, "번째임1")
            print(dp[y2-1][x2-1])
        elif y2 == 1 :
            if x1 == 1:
                print(dp[0][x2 - 1] - dp[0][0])
            else :
                print(dp[0][x2-1] - dp[0][x1-2])
        elif x2 == 1 :
            if y1 == 1 :
                print(dp[y2 - 1][0] - dp[0][0])
            else :
                print(dp[y2-1][0] - dp[y1-2][0])
        elif x1 == 1 :
          #  print(k, "번째임4")
            print(dp[y2-1][x2-1] - dp[y2-1][0] - dp[y1-2][x2-1] + dp[y1-2][0])
        elif y1 == 1 :
          #  print(k, "번째임5")
            print(dp[y2-1][x2-1] - dp[y2-1][x1-2] - dp[0][x2-1] + dp[0][x1-2])
        else :
          #  print(k, "번째임6")
            print(dp[y2-1][x2-1] - dp[y2-1][x1-2] - dp[y1-2][x2-1] + dp[y1-2][x1-2])
            '''
