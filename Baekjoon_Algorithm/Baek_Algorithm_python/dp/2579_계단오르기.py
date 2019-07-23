import sys


if __name__ == "__main__" :
    n = int(sys.stdin.readline())
    stair = [0]
    dp = [0 for _ in range(302)]
    for _ in range(n) :
        a = int(sys.stdin.readline())
        stair.append(a)
    dp[1] += stair[1]
    dp[2] += stair[1] + stair[2]
    for i in range(3, n+1) :
        dp[i] += max((stair[i] + stair[i-1] + dp[i-3] , stair[i] + dp[i-2]))
 #   print(dp)
    print(dp[n])