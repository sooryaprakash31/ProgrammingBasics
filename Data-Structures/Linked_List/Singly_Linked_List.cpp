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
    Node(int d){
        data=d;
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
            cout<<"Successfully appended\n";
        }
        else{
            Node * ptr = head;
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
            while(count!=pos){
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

    //prints all the nodes
    void printAll(){
        if(head==NULL){
            cout<<"Empty list\n";
        }
        else{
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
        cout<<"\n1.Append\t2.Prepend\t3.InsertAt\t4.PrintAll\t6.Stop\n";
        cin>>choice;
        Node * node = new Node();
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
            int position;
            cout<<"\nEnter data: ";
            cin>>node->data;
            cout<<"\nEnter position: ";
            cin>>position;
            s.insertNodeAt(node,position);
            break;
        case 4:
            s.printAll();
            break;
        case 6:
            break;
        default:
            break;
        }
    }while(choice!=6);
    return 0;
}

