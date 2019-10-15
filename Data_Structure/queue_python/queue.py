class queue :

    def __init__(self):
        self.data = []

    def push(self, item):
        self.data.append(item)

    def pop(self):
        self.data.pop(0)

    def size(self):
        if len(self.data) >= 0 : return len(self.data)
        else : return -1

    def empty(self):
        if len(self.data) == 0 : return True
        else : return False

    def front(self):
        return self.data[0]

    def print(self, num):
        print(self.data[num])

    def print_whole(self):
        print(self.data)

if __name__ == "__main__" :

    stack = queue()
    stack.push(3)
    stack.push([2,4])
    front = stack.front()
    print("front", front)
    stack.push(5)
    front = stack.front()
    print("front", front)
    stack.print_whole()
    stack.pop()
    stack.print_whole()
    em = stack.empty()
    print(em)
