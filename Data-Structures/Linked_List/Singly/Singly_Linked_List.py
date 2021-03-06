'''
Linked List:

A linear data structure in which the elements are not stored in
contiguous memory locations. 

Representation:
    data|next--> data|next--> data|next

Advantage:
    - Dynamic size
    - Memory allocated during runtime and not compile time
    - Efficient memory utilization

Operations:

1. Append()
2. Prepend()
3. InsertNodeAT()
4. DeleteNodeAt()
5. DeleteAll()
6. SwapTwoNodes()
7. PrintAll()
8. GetLength()

'''

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
            #traversing to the end of the list
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
        if self.head is None:
            print("Position does not exist")
            return
        else:
            if pos == 0:
               node.next = self.head
               self.head=node 
            else:
                temp = self.head
                count=1
                #traversing to the position
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
        if self.head is None:
            print("Position does not exist")
            return
        else:
            if pos == 0:
                self.head = self.head.next
            else:
                temp=self.head
                count=1
                #traversing to the position
                while count<pos:
                    temp = temp.next
                    if temp is None:
                        print("Position does not exist")
                        return
                    count+=1
                nextNode = temp.next
                temp.next = nextNode.next
            print("Deleted!")

    #swaps two nodes in the list
    def swapTwoNodes(self,x,y):
        if x==y:
            return
        prevX=None
        currX=self.head
        while currX and currX.data!=x:
            prevX = currX
            currX=currX.next
        prevY = None
        currY = self.head

        while currY and currY.data!=y:
            prevY=currY
            currY=currY.next

        #if x or y is not present
        if currX is None or currY is None:
            print("Enter valid elements")
            return
        #if x is at the head
        if prevX is None:
            self.head = currY
        else:
            prevX.next = currY
        #if y is at the head
        if prevY is None:
            self.head = currX
        else:
            prevY.next = currX
        
        currX.next, currY.next = currY.next, currX.next 
        print("Nodes swapped! ")
        
    #deletes all the nodes in the linked list
    def deleteAll(self):
        temp = self.head
        while temp:
            nextNode = temp.next
            del temp.data
            temp = nextNode

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
            l=[]
            temp = self.head
            while temp:
                l.append(temp.data)
                temp=temp.next
            print(*l)


s=SinglyLinkedList()
choice = 0
while True:
    print("1.Append\t2.Prepend\t3.InsertAt\t4.DeleteAt\t5.SwapTwoNodes\t6.PrintAll\t7.Length\t8.Stop")
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
        x,y = map(int, input("Enter two values").split())
        s.swapTwoNodes(x,y)
    elif choice==6:
        s.printAll()
    elif choice==7:
        s.getLength()
    elif choice==8:
        break
    else:
        print("Invalid choice")