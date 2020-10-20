'''
Doubly Linked List:

    - A linear data structure in which the elements are not stored in
      contiguous memory locations.
    - Doubly Linked List contains an extra pointer to keep track of the previous
      node to a particular node.

Representation:

    previous|data|next <---> previous|data|next <---> previous|data|next

Advantages:
    - Can be traversed from both direction
    - Deletion of node is efficient if the pointer to node is known

Operations:

1. Append()
2. Prepend() 
3. InsertAt()
4. DeleteAt()
5. PrintAll()

'''
class Node:
    
    def __init__(self,data=None):
        self.data = data
        self.previous = None
        self.next = None

class DoublyLinkedList:

    def __init__(self):
        self.head = None
    
    #appends the node at the end of the list
    def appendNode(self, node):
        if self.head is None:
            self.head = node
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = node
            node.previous = temp
        print("Appended!")
    
    #prepends the node at the beginning of the list
    def prependNode(self,node):
        node.next = self.head
        node.previous = None
        self.head = node
        print("Prepended!")

    #inserts the node at a position
    def insertAt(self, node, pos):
        if self.head is None:
            print("Position does not exist")
        else:
            if pos == 0:
                node.next = self.head
                node.previous = None
                self.head = node
            else:
                temp = self.head
                count = 1
                while count<pos:
                    temp = temp.next
                    if temp is None:
                        print("Position does not exist")
                        return
                    count+=1
                node.next = temp.next
                node.previous = temp
                temp.next = node
        print("Inserted!")
                
    #deletes the node at the position
    def deleteAt(self, pos):
        if self.head is None:
            print("Position does not exist")
        else:
            if pos == 0:
                self.head = self.head.next
                self.head.previous = None
            else:
                temp = self.head
                count = 1
                while count<pos:
                    temp = temp.next
                    if temp is None:
                        print("Position does not exist")
                        return
                    count+=1
                
                nextNode = temp.next.next
                temp.next = nextNode
                nextNode.previous = temp
        print("Deleted!")

    #prints all the nodes in the list
    def printAll(self):
        if self.head is None:
            print("Empty List")
        else:
            l = []
            temp = self.head
            while temp:
                l.append(temp.data)
                temp = temp.next
            print(*l)


d = DoublyLinkedList()
choice = 0

while True:
    print("\n1.Append\t2.Prepend\t3. InsertAt\t4.DeleteAt\t5.PrintAll\t6.Stop")
    choice = int(input("Enter choice: "))
    node = Node()

    if choice == 1:
        node.data = int(input("Enter data: "))
        d.appendNode(node)
    elif choice == 2:
        node.data = int(input("Enter data: "))
        d.prependNode(node)
    elif choice == 3:
        node.data = int(input("Enter data: "))
        position = int(input("Enter position: "))
        d.insertAt(node,position)
    elif choice == 4:
        position = int(input("Enter position: "))
        d.deleteAt(position)
    elif choice == 5:
        d.printAll()
    else:
        break