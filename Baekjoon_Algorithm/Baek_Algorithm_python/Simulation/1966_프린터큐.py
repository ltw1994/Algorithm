def replace() :
    while priority :

        if max(priority) == priority[0] :
            del priority[0]
            result.append(rank[0])
            del rank[0]

        else :
            tmp = priority[0]
            tmp2 = rank[0]
            for i in range(len(priority)-1) :
                priority[i] = priority[i+1]
                rank[i] = rank[i+1]
            priority[len(priority)-1] =  tmp
            rank[len(rank)-1] = tmp2




if __name__ == "__main__" :
    test_case = int(input())
    for _ in range(test_case) :
        N, M = map(int, input().split())
        priority = input().split()
        for i in range(N) :
            priority[i] = int(priority[i])
        result = []
        rank = [int(i) for i in range(N)]
        replace()

        for i in range(len(result)) :
            if result[i] == M :
                print(i+1)