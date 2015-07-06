#Implementing a finite sized Stack using a list

class Stack:
    top = -1
    list = []

    def __init__(self, size):
        self.size = size

    def push(self, value):
        if len(self.list) >= self.size:
            print "Stack is full"
        else:
            self.top += 1
            self.list.append(value)


    def pop(self):
        if self.empty():
            print "Stack is empty"
        else:
            returned = self.list[self.top]
            del self.list[self.top]
            self.top -= 1
            return returned

    def empty(self):
        if self.top == -1:
            return True
        return False



