#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class node
{
public:
    node *left;
    node *right;
    int data;

    node(int data)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = data;
    }
};

node *buildTree(node *root)
{
    node *temp = root;
    int data;
    cout << "Enter Data : " << endl;
    cin >> data;


    if (data == -1)
    {
        return nullptr;
    }

    root = new node(data);

    cout << "Enter Data for left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter Data for right of " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    cout << endl;
}

void reverseLevelOrderTraversal(node *root)
{
    stack<node *> s;
    queue<node *> q;
    q.push(root);
    q.push(nullptr);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        s.push(temp);

        if (temp == nullptr)
        {
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
        else
        {
            if (temp->right)
            {
                q.push(temp->right);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
        }
    }
    s.pop();
    while (!s.empty())
    {
        node *temp = s.top();
        s.pop();
        if (temp == nullptr)
        {
            cout << endl;
        }
        else
        {
            cout << temp->data << " ";
        }
    }
    cout << endl;
}

void inOrder(node* root){
    //LNR : Left Node Right
    if(root == nullptr){
        return;
    }
    inOrder(root->left);
    cout << root ->data << " ";
    inOrder(root->right);
}


void preOrder(node* root){
    //NLR : Node Left Right
    if(root == nullptr){
        return;
    }
    cout << root ->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void postOrder(node* root){
    //LRN : Left Right Node
    if(root == nullptr){
        return;
    } 
    postOrder(root->left);
    postOrder(root->right);
    cout << root ->data << " ";
}
 

int main()
{
    node *root = nullptr;

    // g++ .\BinaryTree.cpp -o xyz.exe
    // ./xyz.exe
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    root = buildTree(root);

    cout << "Level Order Traversal : " << endl;
    levelOrderTraversal(root);
    cout << "Reverse Level Order Traversal : " << endl;
    reverseLevelOrderTraversal(root);

    cout<< endl << "Inorder : " ;
    inOrder(root);

    cout<< endl << "Preorder : " ;
    preOrder(root);

    cout<< endl << "Postorder : " ;
    postOrder(root);
    return 0;
}