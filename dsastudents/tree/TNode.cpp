#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "stacknqueue/Stack.h"
#include "stacknqueue/Queue.h"
#include "list/DLinkedList.h"
template <class T>
struct TNode
{
    T data;
    TNode<T> *left, *right;
    TNode(T data, TNode<T> *left = NULL, TNode<T> *right = NULL)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

//             0, 1, 2, 3, 4, 5, 6, 7, 8,  9
void create_tree(TNode<int> *&root, int *list)
{
    TNode<int> **p = new TNode<int> *[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = new TNode<int>(list[i]);
    }
    p[0]->left = p[2];
    p[0]->right = p[4];
    p[2]->left = p[3];
    p[2]->right = p[5];
    p[4]->left = p[1];
    p[4]->right = p[7];
    p[5]->left = p[6];
    p[1]->left = p[9];
    p[7]->right = p[8];
    root = p[0];
    delete[] p;
}

int height(TNode<int> *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if(leftHeight>rightHeight)
            return 1 + leftHeight;
        else
            return 1 + rightHeight;
    }
}

void preOrder(TNode<int> *r)
{
    if (r != NULL)
    {
        cout << r->data << " ";
        preOrder(r->left);
        preOrder(r->right);
    }
}

void inOrder(TNode<int> *r)
{
    if (r != NULL)
    {
        inOrder(r->left);
        cout << r->data << " ";
        inOrder(r->right);
    }
}

void postOrder(TNode<int> *r)
{
    if (r != NULL)
    {
        postOrder(r->left);
        postOrder(r->right);
        cout << r->data << " ";
    }
}

void bfsV1(TNode<int> *root)
{
    Queue<TNode<int> *> queue;
    queue.push(root);

    while (queue.empty() == false)
    {
        TNode<int> *Node = queue.pop();
        cout << Node->data << " ";
        if (Node->left != NULL)
            queue.push(Node->left);
        if (Node->right != NULL)
            queue.push(Node->right);
        /* code */
    }
}

int getLeaves(TNode<int>* root)
{
    if(root == 0)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return (getLeaves(root->left) + getLeaves(root->right));
}

int main()
{
    int arr[10] = {5, 7, 2, 1, 8, 4, 3, 9, 10, 6};
    TNode<int> *root;
    create_tree(root, arr);
    preOrder(root);
    cout << endl;
    inOrder(root);
    cout << endl;
    postOrder(root);
    cout << endl;
    bfsV1(root);
    cout << endl;
    cout << "Height is: " << height(root) << endl;
    cout << "Leaves is: " <<  getLeaves(root) << endl;
    return 0;
}
/*
int is_balanced(TNode<int>* root, bool& balanced){
    
    bool balancedL=true;
    bool balancedR=true;
    
    if ( root == NULL) return 0; 

    int  leftH = is_balanced(root->left, balancedL);
    int  rightH = is_balanced(root->right, balancedR);
    balanced = false;
    if (balancedL && balancedR) {
        if (  abs(leftH - rightH) <= 1 ) {
            balanced = true;
        }
        else balanced = false;
    }
    return max(leftH,rightH) + 1; 
}

*/