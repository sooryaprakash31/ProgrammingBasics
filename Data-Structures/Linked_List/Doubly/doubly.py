
class Node:
    
    def __init__(self,data=None):
        self.data = data
        self.previous = None
        self.next = None

class DoublyLinkedList:

    def __init__(self):
        self.head = None
    
    #appends the node at the end of the list
    def append(self, node):
        if self.head is None:
            self.head = node
        else:
            temp = self.head
            while temp.next != None:
                temp = temp.next
            temp.next = node
            node.previous = temp
        print("Appended!")

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
    print("\n1.Append\t4.PrintAll\t5.Stop")
    choice = int(input("Enter choice: "))
    node = Node()

    if choice ==1:
        node.data = int(input("Enter data: "))
        d.append(node)
    elif choice ==4:
        d.printAll()
    else:
        break