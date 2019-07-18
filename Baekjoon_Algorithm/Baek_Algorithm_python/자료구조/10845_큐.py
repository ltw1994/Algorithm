
if __name__ == "__main__" :
    N = int(input())
    queue= []
    for _ in range(N) :
     #   print(queue)
        tmp = list(input().split())
        if tmp[0] == 'push' :
            queue.append(int(tmp[1]))
        elif tmp[0] == 'pop' :
            if len(queue) == 0 :
                print(-1)
            else :
                print(queue[0])
                del queue[0]
        elif tmp[0] == 'size' :
            print(len(queue))
        elif tmp[0] == "empty" :
            if len(queue) == 0 :
                print(1)
            else :
                print(0)
        elif tmp[0] == "back" :
            if len(queue) == 0 :
                print(-1)
            else :
                last = len(queue)
                last -= 1
                print(queue[last])
        elif tmp[0] == "front" :
            if len(queue) == 0 :
                print(-1)
            else :
                print(queue[0])

