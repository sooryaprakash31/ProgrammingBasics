'''
Stack:

- A linear data structure which follows a particular order in which
the operations are performed.
- LIFO (Last In First Out)

Representation:

Access--> Node 2 ---------------------------- |-> data|next
          Node 1 ------------- |-> data|next -|     
          Node 0 -- data|next -|

Operations:
1. Push()
2. Pop()
3. GetPeek()
'''

class Node:
    def __init__(self, data= None):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.head = None
    
    #pushes the node at the top
    def push(self, node):
        node.next = self.head
        self.head = node
        print("Pushed!")

    #pop the node at the top
    def pop(self):
        if self.head is None:
            print("Empty list")
            return -1
        else:
            temp = self.head
            self.head = temp.next
            data = temp.data
            del temp
            return data
    
    #returns the data of the node at the top
    def getPeek(self):
        if self.head is None:
            print("Empty list")
            return -1
        else:
            data = self.head.data
            return data


s=Stack()
choice =0
while True:
    print("1.Push\t2.Pop\t3.Peak\t4.Stop ")
    choice = int(input("Enter choice "))
    node = Node()
    if choice==1:
        node.data = int(input("Enter data "))
        s.push(node)
    elif choice==2:
        result = s.pop()
        if result!=-1:
            print(result, " Popped")
    elif choice==3:
        result = s.getPeek()
        if result!=-1:
            print("Peek is ",result)
    elif choice==4:
        break
    else:
        print("Invalid choice")