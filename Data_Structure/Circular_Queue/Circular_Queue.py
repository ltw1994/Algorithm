class CircularQueue() :

    def __init__(self, max) :
        self.max = max
        self.queue = [None] * self.max
        self.size = self.front = 0
        self.rear = None

    def is_empty(self) :
        return self.size == 0

    def next_index(self, idx) :
        return (idx+1) % self.max

    def is_full(self) :
        if self.rear == None :
            return False
        return self.next_index(self.size) == self.front

    def enqueue(self, data) :
        if self.is_full() :
            raise print(" Queue if full !! ")

        if self.rear == None :
            self.rear = 0
        else :
            self.rear = self.next_index(self.rear)

        self.queue[self.rear] = data
        self.size += 1
        return self.queue[self.rear]

    def deque(self) :
        if self.is_empty() :
            raise print(" Queue if empty !! ")

        self.queue[self.front] = None
        self.front = self.next_index(self.front)
        return self.queue[self.front]

    def display(self):
        print(self.queue)


if __name__ == "__main__" :
    CQ = CircularQueue(5)
    CQ.display()
    CQ.enqueue(3)
    CQ.enqueue(2)
    CQ.enqueue(3)
    CQ.enqueue(4)
    CQ.display()
    CQ.enqueue(3)
    #CQ.enqueue(3)
    CQ.display()
    CQ.deque()
    CQ.display()
    CQ.display()
    print(CQ.deque())
    CQ.display()


