/*
Circular Linked List:

    - A linear data structure in which the elements are not stored in
    contiguous memory locations.
    - The last node will point to the head or first node thus forming a circular list

Representation:

    |--> data|next--> data|next--> data|next --|
    |------------------------------------------|  

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

class CircularLinkedList{
    
    public:
        Node * head;

    CircularLinkedList(){
        head = NULL;
    }

    CircularLinkedList(Node * node){
        head = node;
        node->next = head;
    }

    //appends the node at the end of the list
    void appendNode(Node * node){
        if(head==NULL){
            head=node;
            node->next = head;
        }
        else{
            Node * ptr = head;
            //traversing to the end of the list
            while(ptr->next!=head){
                ptr=ptr->next;
            }
            ptr->next=node;
            node->next=head;
        }
    cout<<"Appended\n";
    }

    //prepends the node at the beginning of the list
    void prependNode(Node * node){
        
        if(head!=NULL){
            Node * ptr = head;
             do{
                ptr=ptr->next;
            }while(ptr!=head);
            ptr->next = node;   
        }
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
            if(pos==0){
                Node * ptr = head;
                do{
                    ptr=ptr->next;
                }while(ptr!=head);
                ptr->next = node;
                node->next=head;
                head=node;
            }
            else{
                Node *ptr = head;
                int count=1;
                //traversing to the position
                while(count<pos){
                ptr=ptr->next;
                if(ptr==head){
                    cout<<"Position does not exist\n";
                    return;
                }
                count++;
                }
                node->next = ptr->next;
                ptr->next=node;
                
            }
        }
        cout<<"Inserted! \n";
    }

    //deletes the node at a position
    void deleteNodeAt(int pos){
        if(head==NULL){
            cout<<"Position does not exist\n";
        }
        else{
                if(pos==0){
                    Node * ptr = head;
                    do{
                        ptr=ptr->next;
                    }while(ptr!=head);
                    ptr->next = head->next;   
                    head=head->next;

                }
                else{
                    int count=1;
                    Node *ptr = head,*temp;
                    //traversing to the position
                    while(count<pos){
                    ptr=ptr->next;
                    if(ptr==head){
                        cout<<"Position does not exist\n";
                        return;
                    }
                    count++;
                    }
                    
                    temp = ptr->next;
                    if (temp->next == head){
                        ptr->next = head;
                    }
                    else{
                        ptr->next=temp->next;
                    }
                    free(temp);
                }       
        }
        cout<<"Deleted!\n";
    }

    //prints all the nodes
    void printAll(){
        if(head==NULL){
            cout<<"Empty list\n";
        }
        else{
            //Traversing the nodes until the next of a node is NULL
            Node *ptr=head;
            do{
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }while(ptr!=head);
            cout<<"\n";
        }
    }

};


int main(){

    CircularLinkedList c;
    int data , choice;

    do{
        cout<<"\n1.Append\t2.Prepend\t3.InsertAt\t4.DeleteAt\t5.PrintAll\t6.Stop\n";
        cin>>choice;
        Node * node = new Node();
        int position;
        switch (choice)
        {
        case 1:
            cout<<"\nEnter data: ";
            cin>>node->data;
            c.appendNode(node);
            break;
        case 2:
            cout<<"\nEnter data: ";
            cin>>node->data;
            c.prependNode(node);
            break;
        case 3:
            cout<<"\nEnter data: ";
            cin>>node->data;
            cout<<"\nEnter position: ";
            cin>>position;
            c.insertNodeAt(node,position);
            break;
        case 4:
            cout<<"Enter position: ";
            cin>>position;
            c.deleteNodeAt(position);
            break;
        case 5:
            c.printAll();
            break;
        case 6:
            break;
        }
    }while(choice!=6);
    
    return 0;
}