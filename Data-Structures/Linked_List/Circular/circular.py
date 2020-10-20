class Node:
    def __init__(self,data=None):
        self.data=data
        self.next=None

class CircularLinkedList:
    def __init__(self):
        self.head = None
    
    #appends the node at the end of the list
    def append(self, node):
        if self.head is None:
            self.head=node
            node.next = self.head
            print("Appended!")
        else:
            temp=self.head
            #traversing to the end of the list
            while temp.next!=self.head:
                temp=temp.next
            temp.next = node
            node.next = self.head
            print("Appended!")

    #prepends the node at the beginning of the list
    def prepend(self, node):

        if self.head is not None:
            temp = self.head
            while temp!=self.head:
                temp = temp.next
            temp.next = node

        node.next = self.head
        self.head=node
        
        print("Prepended!")

    def printAll(self):
        if self.head is None:
            print("Empty List")
        else:
            l=[]
            temp = self.head
            while True:
                l.append(temp.data)
                temp=temp.next
                if temp == self.head:
                    break
            print(*l)


c = CircularLinkedList()
choice = 0

while True:
    print("1.Append\t2.Prepend\t3.InsertAt\t4.DeleteAt\t5.PrintAll\t6.Stop")
    choice = int(input("Enter choice: "))
    node = Node()
    if choice==1:
        node.data = int(input("Enter data "))
        c.append(node)
    elif choice == 2:
        node.data = int(input("Enter data "))
        c.prepend(node)
    elif choice == 5:
        c.printAll()
    else:
        break