/*
Queue:

- A linear data structure which follows a particular order in which
the operations are performed.
- FIFO (Last In First Out)

Representation:

Rear--> Node 2 ---------------------------- |-> data|next
        Node 1 ------------- |-> data|next -|     
Front-> Node 0 -- data|next -|

Operations:
1. Enqueue()
2. Dequeue()
3. GetFront()
4. GetRear()
*/


#include<iostream>
using namespace std;


class Node{
    public:
    int data;
    Node * next;
    Node(){
        data = 0;
        next = NULL;
    }
};

class Queue{
    public:
    Node *front, *rear;

    Queue(){
        front = NULL;
        rear = NULL;
    }
    
    //enqueues the node at the end
    void enqueue(Node * node)
    {
        if(rear==NULL){
            rear = front = node;
        }
        else{
            rear->next=node;
            rear = node;
        }
        cout<<"Enqueued!\n";
    }

    //dequeues the node at the beginning
    int dequeue(){
        if(front==NULL){
            cout<<"Empty Queue\n";
            return -1;
        }
        else{
            Node *temp = front;
            front = temp->next;
            int result = temp->data;
            if(front==NULL){
                rear = NULL;
            }
            free(temp);
            return result;
        }
    }

    //returns data of the node at the beginning of the queue
    int getFront(){
        if(front==NULL){
            cout<<"Empty queue\n";
            return -1;
        }
        return front->data;
    }  

    //returns data of the node at the end of the queue
    int getRear(){
        if(rear==NULL){
            cout<<"Empty queue\n";
            return -1;
        }
        return rear->data;
    }


};

int main(){

    Queue q;
    int data,choice,result;
    do{
        cout<<"1.Enqueue\t 2.Dequeue\t 3.Front\t 4.Rear\t 5.Stop\n";        
        cin>>choice;
        Node * node = new Node();
        switch (choice)
        {
        case 1:
            cout<<"Enter data ";
            cin>>node->data;
            q.enqueue(node);
            break;
        case 2:
            result = q.dequeue();
            if(result!=-1){
                cout<<result<<" Dequeued!\n";
            }
            break;
        case 3:
            result = q.getFront();
            if(result!=-1){
                cout<<"Front is "<<result<<endl;
            }
            break;
        case 4:
            result = q.getRear();
            if(result!=-1){
                cout<<"Rear is "<<result<<endl;
            }
            break;
        case 5:
            break;
        default:
            cout<<"Invalid choice!";
        }
    }while(choice!=5);
    return 0;
}