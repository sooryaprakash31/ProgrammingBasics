#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
    Node *left;
    Node *right;
    int data;
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

class Tree
{
public:
    void createTree()
    {
        Node *root = new Node();
        Node *p;
        cout << "Enter root\n";
        cin >> root->data;
        root->left = root->right = NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int data;
            p = q.front();

            q.pop();
            cout << "Enter Left child of " << p->data << "\t";
            cin >> data;
            if (data != -1)
            {
                Node *temp = new Node();
                temp->data = data;
                p->left = temp;
                q.push(temp);
            }
            cout << "Enter Right child of " << p->data << "\t";
            cin >> data;
            if (data != -1)
            {
                Node *temp = new Node();
                temp->data = data;
                p->right = temp;
                q.push(temp);
            }
        }
    }
};

int main()
{

    int choice;
    Tree t;
    do
    {
        cout << "1. Add 2.Print 3.Stop\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            t.createTree();
            break;

        default:
            break;
        }

    } while (choice == 3);

    return 0;
}