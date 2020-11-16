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
    Node *root = new Node();
    void createTree()
    {
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

    void preorder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data << "\t";
        preorder(node->left);
        preorder(node->right);
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
        case 2:
            t.preorder(t.root);
            break;
        default:
            break;
        }

    } while (choice != 3);

    return 0;
}