'''def fibonacci(n) :
    if n == 1 :
        return 0
    elif n == 2 :
        return 1
    elif n == 3 :
        return 1
    else :
        return fibonacci(n-1) + fibonacci(n-2)
        '''

if __name__ == "__main__" :
    n = int(input())
   # result = fibonacci(n)
    A = []
    A.append(0)
    A.append(1)
    num = 2

    while(True) :
        k = A[num-1] + A[num-2]
        A.append(k)
        if num == n :
            print(A)
            print(A[num])
            break
        num += 1
