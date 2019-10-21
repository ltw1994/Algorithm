


def solution(m, n, puddles):
    answer = 0
    d = [[0 for i in range(m)] for _ in range(n)]
    d[0][0] = 1
    for i in range(m) :
        for j in range(n) :
            if [i+1,j+1] in puddles :
                #print(2)
                continue
            if j-1 >= 0 :
                d[j][i] += d[j-1][i]
            if i-1 >= 0 :
                d[j][i] += d[j][i-1]
    answer = d[n-1][m-1]
    #print(d)
    return answer % 1000000007

if __name__ == "__main__" :
    m = 4
    n = 3
    puddles = [[2,2]]
    ans = solution(m,n,puddles)
    print(ans)