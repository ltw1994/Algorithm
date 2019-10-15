class stack :

    def __init__(self) :
        self.data = []

    def push(self, item) :
        self.data.append(item)

    def pop(self):
        self.data.pop()

    def size(self):
        if len(self.data) >= 0 : return len(self.data)
        else : return -1

    def empty(self):
        if len(self.data) == 0 : return True
        else : return False

    def top(self):
        return self.data[len(self.data)-1]

    def print(self, num):
        print(self.data[num])

    def print_whole(self):
        print(self.data)

if __name__ == "__main__" :

    stack = stack()
    stack.push(3)
    stack.push([2,4])
    stack.push(5)
    stack.print_whole()
    top = stack.top()
    print("top", top)
    stack.pop()
    stack.print_whole()
    top = stack.top()
    print("top", top)
    stack.pop()
    stack.print_whole()
    top = stack.top()
    print("top", top)
    em = stack.empty()
    print(em)
