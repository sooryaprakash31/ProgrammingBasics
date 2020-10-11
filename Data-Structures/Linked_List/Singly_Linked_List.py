class Node:
    def __init__(self,data=None):
        self.data=data
        self.next=None
    
class SinglyLinkedList:
    def __init__(self):
        self.head=None
    
    #appends the node at the end of the list
    def append(self, node):
        if self.head is None:
            self.head=node
            print("Appended!")
        else:
            temp=self.head
            while temp.next!=None:
                temp=temp.next
            temp.next=node
            print("Appended!")

    #prepends the node at the beginning of the list
    def prepend(self, node):
        node.next = self.head
        self.head=node
        print("Prepended!")

    #inserts node at a position
    def insertAt(self, node, pos):
        temp = self.head
        if self.head is None:
            print("Position does not exist")
            return
        else:
            count=1
            while count<pos:
                temp = temp.next
                if not temp:
                    print("Position does not exist")
                    return
                count+=1
            node.next = temp.next
            temp.next = node
            print("Inserted!")

    #deletes node at a position
    def deleteAt(self,pos):
        temp=self.head
        if self.head is None:
            print("Position does not exist")
            return
        else:
            count=1
            while count<pos:
                temp = temp.next
                if temp is None:
                    print("Position does not exist")
                    return
                count+=1
            nextNode = temp.next
            temp.next = nextNode.next
            print("Deleted!")

    #returns the length of the list
    def getLength(self):
        temp = self.head
        total=0
        while temp:
            total+=1
            temp = temp.next
        print("Length ",total)

    #prints all the nodes in the list
    def printAll(self):
        if self.head is None:
            print("Empty List")
        else:
            temp = self.head
            while temp:
                print(temp.data, sep=' ')
                temp=temp.next


s=SinglyLinkedList()
choice = 0
while True:
    print("1.Append\t2.Prepend\t3.InsertAt\t4.DeleteAt\t5.PrintAll\t6.Length\t7.Stop")
    choice = int(input("Enter choice: "))
    node = Node()
    if choice==1:
        node.data = int(input("Enter data "))
        s.append(node)
    elif choice==2:
        node.data = int(input("Enter data "))
        s.prepend(node)
    elif choice==3:
        node.data = int(input("Enter data "))
        pos = int(input("Enter position "))
        s.insertAt(node,pos)
    elif choice==4:
        pos = int(input("Enter position "))
        s.deleteAt(pos)
    elif choice==5:
        s.printAll()
    elif choice==6:
        s.getLength()
    elif choice==7:
        break
    else:
        print("Invalid choice")