class CircularQueue() :

    def __init__(self, max):
        self.max = max
        self.queue = [None] * self.max
        self.size = self.front = 0
        self.rear = None

    def is_empty(self):
        return self.size = 0

    def next_index(self, idx):
        return (idx+1) % self.max

    def is_full(self):
        if self.rear == None :
            return False
        return self.next_index(self.rear) == self.front

    def enqueue(self, data) :
