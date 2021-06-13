#include <iostream>
using namespace std;
class Node
{
public:
    int value;
    Node* left;
    Node* right;
    Node(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
    Node()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
};

class AVLTree
{
public:
    Node* root;
    AVLTree()
    {
        root = NULL;
    }
    int height(Node* r)
    {
        if (r == NULL)
            return -1;
        else
        {
            int leftHeight = height(r->left);
            int rightHeight = height(r->right);
            if (leftHeight > rightHeight)
                return (1 + leftHeight);
            else
                return (1 + rightHeight);
        }
    }
    int getBalanceFactor(Node* r)
    {
        if (r == NULL)
            return -1;
        return (height(r->left) - height(r->right));
    }
    void insert(int value)
    {
        root = AVLInsert(root, value);
    }
    Node* AVLInsert(Node* r, int value)
    {
        if (r == NULL)
        {
            Node* new_node = new Node(value);
            r = new_node;
            return r;
        }
        else if (value < r->value)
            r->left = AVLInsert(r->left, value);
        else if (value > r->value)
            r->right = AVLInsert(r->right, value);
        else
        {
            cout << "No Duplicate Node" << endl;
            return r;
        }
        int bf = getBalanceFactor(r);
        if (bf > 1 && value < r->left->value)
            return rightRotation(r);
        else if (bf<-1 && value > r->right->value)
            return leftRotation(r);
        else if (bf > 1 && value > r->left->value)
        {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }
        else if (bf < -1 && value < r->right->value)
        {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }
        return r;
    }
    Node* maxLeft(Node* r)
    {
        while (r->right != NULL)
        {
            r = r->right;
        }
        return r;
    }
    Node* AVLDel(Node* r, int value)
    {
        if (r == NULL)
            return r;
        else if (value < r->value)
            r->left = AVLDel(r->left, value);
        else if (value > r->value)
            r->right = AVLDel(r->right, value);
        else
        {
            if (r->left == NULL)
            {
                Node* temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                Node* temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                Node* temp = maxLeft(r->left);
                r->value = temp->value;
                r->left = AVLDel(r->left, temp->value);
            }
        }
        // if(r == NULL)
        //   return r;
        int bf = getBalanceFactor(r);
        if (bf > 1)
        {
            if (height(r->left->left) - height(r->left->right) >= 0)
                return rightRotation(r);
            else
            {
                r->left = leftRotation(r->left);
                return rightRotation(r);
            }
        }
        else if (bf < -1)
        {
            if (height(r->right->left) - height(r->right->right) <= 0)
                return leftRotation(r);
            else
            {
                r->right = rightRotation(r->right);
                return leftRotation(r);
            }
        }
        return r;
    }
    void deletee(int value)
    {
        root = AVLDel(root, value);
    }
    void print()
    {
        print(root);
    }
    void print(Node* r)
    {
        if (r != NULL)
        {
            cout << r->value << " ";
            print(r->left);
            print(r->right);
        }
    }
    Node* leftRotation(Node* a)
    {
        Node* b = a->right;
        Node* d = b->left;
        b->left = a;
        a->right = d;
        return b;
    }
    Node* rightRotation(Node* a)
    {
        Node* b = a->left;
        Node* d = b->right;
        b->right = a;
        a->left = d;
        return b;
    }
};
int main()
{
    AVLTree someTree;
    int arr[] = {23, 44, 15, 22, 11, 9, 66, 18, 67, 21, 49, 55, 77, 10, 2, 65, 28, 99, 42, 36, 98, 32};
    int n = sizeof(arr)/sizeof(int);
    for (int i = 0; i < n; i++)
    {
      someTree.insert(arr[i]);
    }
    someTree.print();
    cout << endl;
    //11, 9, 23, 15, 22, 18, 67, 21, 49, 32
    someTree.deletee(11);
    someTree.deletee(9);
    someTree.deletee(23);
    someTree.deletee(15);
    someTree.deletee(22);
    someTree.deletee(18);
    someTree.deletee(67);
    someTree.deletee(21);
    someTree.deletee(49);
    someTree.deletee(32);
    someTree.print();
    return 0;
}