
if __name__ == "__main__" :
    N = int(input())
    stack = []
    for _ in range(N) :
        tmp = list(input().split())
        if tmp[0] == 'push' :
            stack.append(int(tmp[1]))
        elif tmp[0] == 'pop' :
            if len(stack) == 0 :
                print(-1)
            else :
                last = len(stack)
                last -= 1
                print(stack[last])
                del stack[last]
        elif tmp[0] == 'size' :
            print(len(stack))
        elif tmp[0] == "empty" :
            if len(stack) == 0 :
                print(1)
            else :
                print(0)
        elif tmp[0] == "top" :
            if len(stack) == 0 :
                print(-1)
            else :
                last = len(stack)
                last -= 1
                print(stack[last])


