'''
Circular Linked List:

    - A linear data structure in which the elements are not stored in
    contiguous memory locations.
    - The last node will point to the head or first node thus forming a circular list

Representation:

    |--> data|next--> data|next--> data|next --|
    |------------------------------------------|  

'''

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

        if self.head is None:
            self.head = node
            node.next = self.head
        else:
            ptr = self.head
            while ptr.next != self.head:
                ptr = ptr.next
            ptr.next = node
            node.next = self.head
            self.head=node
        
        print("Prepended!")

    #inserts node at a position
    def insertAt(self,node,pos):
        if self.head is None:
            print("Position does not exist")
            return
        else:
            if pos == 0:
                ptr = self.head
                while ptr.next!=self.head:
                    ptr = ptr.next
                ptr.next = node
                node.next = self.head
                self.head = node
            else:
                ptr = self.head
                count=1
                #traversing to the position
                while count<pos:
                    ptr = ptr.next
                    if ptr==self.head:
                        print("Position does not exist")
                        return
                    count+=1
                
                node.next = ptr.next
                ptr.next = node

        print("Inserted!")

    #deletes the node at a position
    def deleteAt(self,pos):
        if self.head is None:
            print("Position does not exist")
            return
        else:
            if pos == 0:
                ptr = self.head
                while ptr.next != self.head:
                    ptr = ptr.next
                ptr.next = self.head.next
                self.head = self.head.next
            else:
                ptr = self.head
                count = 1
                while count<pos:
                    ptr = ptr.next
                    if ptr==self.head:
                        print("Position does not exist")
                        return
                    count+=1

                temp = ptr.next
                if temp == self.head:
                    ptr.next = self.head
                else:
                    ptr.next = temp.next
        print("Deleted!")


    #prints all the nodes in the list
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
    elif choice == 3:
        node.data = int(input("Enter data "))
        positon = int(input("Enter position "))
        c.insertAt(node,positon)
    elif choice == 4:
        positon = int(input("Enter position "))
        c.deleteAt(positon)
    elif choice == 5:
        c.printAll()
    else:
        break