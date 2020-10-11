'''
Queue:

- A linear data structure which follows a particular order in which
the operations are performed.
- FIFO (Last In First Out)

Representation:

Rear--> Node 2 ---------------------------- |-> data|next
        Node 1 ------------- |-> data|next -|     
Front-> Node 0 -- data|next -|

Operations:
1. Enqueue()
2. Dequeue()
3. GetFront()
4. GetRear()
'''



class Node:
    def __init__(self,data=None):
        self.data = data
        self.next = None

class Queue:
    def __init__(self):
        self.front = None
        self.rear = None
    
    #enqueues the node at the end of the queue
    def enqueue(self, node):
        if self.rear is None:
            self.rear = node
            self.front = node
        else:
            self.rear.next = node
            self.rear = node
        print("Enqueued!")
    
    #dequeues the node at the beginning of the queue
    def dequeue(self):
        if self.front is None:
            print("Empty Queue")
            return -1
        else:
            temp = self.front
            self.front = temp.next
            result = temp.data
            if self.front is None:
                self.rear = None
            del temp
            return result

    #returns the data at the Front node
    def getFront(self):
        if self.front is None:
            print("Empty Queue")
            return -1
        else:
            return self.front.data
    
    #returns the data at the Rear node
    def getRear(self):
        if self.rear is None:
            print("Empty Queue")
            return -1
        else:
            return self.rear.data



q=Queue()
choice =0

while True:
    print("1.Enqueue\t2.Dequeue\t3.Front\t4.Rear\t5.Stop")
    choice = int(input("Enter choice "))
    node = Node()
    if choice==1:
        node.data = int(input("Enter data "))
        q.enqueue(node)
    elif choice==2:
        result = q.dequeue()
        if result !=-1:
            print(result," Dequeued!")
    elif choice == 3:
        result = q.getFront()
        if result !=-1:
            print("Front is ",result)
    elif choice ==4:
        result = q.getRear()
        if result !=-1:
            print("Rear is ",result)
    elif choice == 5:
        break
    else:
        print("Invalid choice!")