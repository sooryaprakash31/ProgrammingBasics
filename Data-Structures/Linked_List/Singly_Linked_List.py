

class Node:
    def __init__(self,data=None):
        self.data=data
        self.next=None
    
class SinglyLinkedList:
    def __init__(self):
        self.head=Node()

    def append(self, node):
        temp = self.head
        if temp.data==None:
            self.head=node
        else:
            while temp.next!=None:
                temp=temp.next
            temp.next=node

    def printAll(self):
        temp = self.head
        if temp.data==None:
            print("Empty List")
        else:
            while temp!=None:
                print("print", temp.data)
                temp=temp.next

s=SinglyLinkedList()

choice = 0
while choice!=6:
    print("1.Append\t2.Prepend\t3.InsertAt\t4.DeleteAt\t5.PrintAll\t6.Stop")
    choice = int(input("Enter choice: "))
    node = Node()
    if choice==1:
        node.data = int(input("Enter data "))
        s.append(node)
        break
    elif choice==5:
        s.printAll()
        pass
    elif choice==6:
        break