




if __name__ == "__main__" :
    N = int(input())
    runner = [0 for _ in range(N)]
    result = []
    for i in range(N) :
        runner[i] = int(input())
    for i in range(N) :
        current_runner = runner[i]
        count = 0
        for j in range(i) :
            if current_runner > runner[j] :
                count += 1
        num = i + 1 - count
        result.append(num)



    for i in range(N) :
        print(result[i])