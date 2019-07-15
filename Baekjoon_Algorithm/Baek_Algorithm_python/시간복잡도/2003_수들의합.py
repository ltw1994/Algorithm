




if __name__ == "__main__" :
    N, M = map(int, input().split())
    A = list(map(int,input().split()))
    result = 0
    for i in range(N) :
        count = 0
        num = 0
        while(True) :
            num += A[i+count]
            if num > M :
                break
            elif num == M :
                result += 1
                break
            count += 1
            if i + count > N-1 :
                break
    print(result)