/*
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
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node(){
        data=0;
        next=NULL;
    }
};

class SinglyLinkedList{
    public:
    Node * head;

    SinglyLinkedList(){
        head=NULL;
    }
    SinglyLinkedList(Node *node){
        head=node;
    }

    //appends the node at the end of the list
    void appendNode(Node * node){
        if(head==NULL){
            head=node;
            cout<<"Appended\n";
        }
        else{
            Node * ptr = head;
            //traversing to the end of the list
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=node;
            node->next=NULL;
            cout<<"Appended\n";
        }
    }

    //prepends the node at the beginning of the list
    void prependNode(Node * node){
        node->next=head;
        head=node;
        cout<<"Prepended! \n";
    }

    //inserts node at a position
    void insertNodeAt(Node *node, int pos){
        if(head==NULL){
            cout<<"Position does not exist\n";
            return;
        }
        else{
            Node *ptr = head;
            int count=1;
            if(pos==0){
                node->next=head;
                head=node;
                cout<<"Inserted\n";
            }
            else{
                //traversing to the position
                while(count<pos){
                ptr=ptr->next;
                if(ptr==NULL){
                    cout<<"Position does not exist\n";
                    return;
                }
                count++;
                }
                node->next = ptr->next;
                ptr->next=node;
                cout<<"Inserted! \n";
            }
            
        }
    }

    //deletes the node at a position
    void deleteNodeAt(int pos){
        if(head==NULL){
            cout<<"Position does not exist\n";
        }
        else{
            int count=1;
            Node *ptr = head;
                if(pos==0){
                    head=head->next;
                    cout<<"Deleted!\n";
                    return;
                }
                else{
                    //traversing to the position
                    while(count!=pos){
                    ptr=ptr->next;
                    if(ptr==NULL){
                        cout<<"Position does not exist\n";
                        return;
                    }
                    count++;
                    }
                    ptr->next=ptr->next->next;
                    cout<<"Deleted! \n";
                }       
        }
    }

    void swapTwoNodes(int x, int y){
        if(x==y){
            return;
        }
        Node * prevX = NULL;
        Node * currX = head;
        //finds the node with x value as data
        while(currX && currX->data!=x){
            prevX = currX;
            currX=currX->next;
        }
        
        Node * prevY = NULL;
        Node * currY = head;
        //finds the node with y value as data
        while(currY && currY->data!=y){
            prevY = currY;
            currY=currY->next;
        }
        //if x is at the head
        if(prevX==NULL){
            head = currY;
        }else{
            prevX->next = currY;
        }
        
        //if x or y is not present
        if (currX==NULL||currY==NULL){
            cout<<"Enter valid elements";
            return;
        }
        //if y is at the head
        if(prevY==NULL){
            head = currX;
        }else{
            prevY->next = currX;
        }

        Node *temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
        cout<<"Nodes swapped!\n";
    }

    //prints the length of the linked list
    void getLength(){
        int total=0;
        Node *ptr=head;
        while(ptr!=NULL)
        {
        total++;
        ptr=ptr->next;
        }
        cout<<"\nLength: "<<total<<endl;
    }

    //deletes the entire linked list
    void deleteAll(){
        Node * ptr=head;
        Node * next;
        while(ptr!=NULL){
            next = ptr->next;
            free(ptr);
            ptr=next;
        }
        head=NULL;
    }

    //prints all the nodes
    void printAll(){
        if(head==NULL){
            cout<<"Empty list\n";
        }
        else{
            //Traversing the nodes until the next of a node is NULL
            Node *ptr= head;
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<"\n";
        }
    }

};

int main(){

    SinglyLinkedList s;
    int data, choice;
    do{
        cout<<"\n1.Append\t2.Prepend\t3.InsertAt\t4.DeleteAt\t5.SwapTwoNodes\t6.PrintAll\t7.Length\t8.Stop\n";
        cin>>choice;
        Node * node = new Node();
        int position;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter data: ";
            cin>>node->data;
            s.appendNode(node);
            break;
        case 2:
            cout<<"\nEnter data: ";
            cin>>node->data;
            s.prependNode(node);
            break;
        case 3:
            cout<<"\nEnter data: ";
            cin>>node->data;
            cout<<"\nEnter position: ";
            cin>>position;
            s.insertNodeAt(node,position);
            break;
        case 4:
            cout<<"Enter position: ";
            cin>>position;
            s.deleteNodeAt(position);
            break;
        case 5:
            int x,y;
            cout<<"Enter two values ";
            cin>>x>>y;
            s.swapTwoNodes(x,y);
            
            break;
        case 6:
            s.printAll();
            break;
        case 7:
            s.getLength();
            break;
        case 8:
            break;
        default:
            break;
        }
    }while(choice!=8);
    return 0;
}

