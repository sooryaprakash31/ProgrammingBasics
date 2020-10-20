#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * previous;

    Node(){
        data = 0;
        next = NULL;
        previous = NULL;
    }
};

class DoublyLinkedList{

    public:
    Node * head;

    DoublyLinkedList(){
        head = NULL;    
    }

    DoublyLinkedList(Node * node){
        head = node;
    }

    //appends the node at the end of the list
    void appendNode(Node * node){
        if(head==NULL){
            head = node;
        }
        else{
            Node * ptr = head;
            //traversing to the end of the list
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = node;
            node->previous = ptr;
            node->next = NULL;
        }
        cout<<"\nAppended";
    }

    //prepends the node at the beginning of the list
    void prependNode(Node * node){

        head->previous = node;
        node->next = head;
        head = node;
        cout<<"\nPrepended!";
    }

    //prints all the nodes
    void printAll(){
        if(head==NULL){
            cout<<"Empty list\n";
        }
        else{
            //Traversing the nodes until the next of a node is NULL
            Node * ptr = head;
            while(ptr!=NULL){
                cout<<ptr->data<<" ";
                ptr=ptr->next;
            }
            cout<<"\n";
        }
    }
};


int main(){

    DoublyLinkedList d;
    int choice,data;
    do{
        cout<<"\n1. Append\t2. Prepend\t4. PrintAll\t8.Stop\n";
        cin>>choice;
        Node * node = new Node();
        switch (choice)
        {
        case 1:
            cout<<"Enter data ";
            cin>>node->data;
            d.appendNode(node);
            break;
        case 2:
            cout<<"Enter data ";
            cin>>node->data;
            d.prependNode(node);
            break;
        case 4:
            d.printAll();
            break;
        default:
            break;
        }
    }while(choice!=8);
    
    return 0;
}