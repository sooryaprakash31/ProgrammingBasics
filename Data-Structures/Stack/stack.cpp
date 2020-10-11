/*
Stack:

- A linear data structure which follows a particular order in which
the operations are performed.
- LIFO (Last In First Out)

Representation:

Access--> Node 2 ---------------------------- |-> data|next
          Node 1 ------------- |-> data|next -|     
          Node 0 -- data|next -|

Operations:
1. Push()
2. Pop()
3. GetPeek()
*/

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node(){
        data = 0;
        next=NULL;
    }
};

class Stack{
    public:
    Node * head;

    Stack(){
        head=NULL;
    }
    Stack(Node *node){
        head=node;
    }

    //pushes the node at the top
    void push(Node *node){
        node->next = head;
        head = node;
        cout<<"Pushed!\n";
    }

    //pops the node at the top
    int pop(){
        if(head==NULL){
            cout<<"Empty stack";
            return -1;
        }
        else{
            Node * temp = head;
            head = temp->next;
            int popped = temp->data;
            free(temp);
            return popped;
        }
    }

    //returns the data of the node at the top
    int getPeek(){
        if(head==NULL){
            cout<<"Empty list\n";
            return -1;
        }
        else{
            return head->data;
        }
    }
};

int main(){

    Stack s;
    int data,choice;
    do{ 
        cout<<"\n1.Push\t2.Pop\t3.Peek\t4.Stop\n";
        cin>>choice;
        Node * node = new Node();
        switch(choice){
            case 1:
                cout<<"Enter data ";
                cin>>node->data;
                s.push(node);
                break;
            case 2:
                int result = s.pop();
                if(result !=-1){
                    cout<<result<<" Popped!";
                }
                break;
            case 3:
                int result = s.getPeek();
                if(result!=-1){
                    cout<<"Peek element is "<<s.getPeek();
                }
                break;
            case 4:
                break;
        }

    }while(choice!=4);
    return 0;
}