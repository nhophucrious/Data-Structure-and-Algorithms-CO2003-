#include <iostream>
using namespace std;

class Node
{
  public:
  int data;
  Node*left;
  Node*right;

  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class BSTree
{
  public:
  Node*root;
  BSTree()
  {
    root = NULL;
  }
  BSTree(Node* n)
  {
    root = n;
  }
  void Insert(int value)
  {
    root = insertBST(root,value);
  }
  void Search(int value)
  {
    Node*temp = searchBST(root,value);
    if(temp!=NULL)
      cout << "value is: "<< temp->data << endl;
    else
      cout <<"Not found"<< endl;
  }
  void Delete(int value)
  {
    root = deleteBST(root,value);
  }
  //helper function
  Node* insertBST(Node*&r, int value)
  {
    if(r == NULL)
    {
      Node*new_node = new Node(value);
      r = new_node;
    }
    else
    {
      if(value < r->data)
        r->left = insertBST(r->left,value);
      else
        r->right = insertBST(r->right,value);
    }
    return r;
  }
  Node* searchBST(Node*&r,int value)
  {
      if(r == NULL || r->data == value)
        return r;
      else if(value < r->data)
        return  searchBST(r->left,value);
      else 
        return  searchBST(r->right,value);
  }
  Node* deleteBST(Node*&r, int value)
  {
    if(r==NULL)
      return r;
    else if(value < r->data)
    {
      r->left = deleteBST(r->left,value);
    }
    else if(value >r->data)
    {
      r->right = deleteBST(r->right,value);
    }
    else
    {
      if(r->left == NULL && r->right == NULL)
      {
        delete r;
        return NULL;
      }
      else if(r->left == NULL)
      {
        Node* temp = r->right;
        delete r;
        return temp;
      }
      else if(r->right == NULL)
      {
        Node* temp = r->left;
        delete r;
        return temp;
      }
      else
      {
        Node*temp = findMax(r->left);
        r->data = temp->data;
        r->left = deleteBST(r->left,temp->data);
      }
    }
    return r;
  }
  Node *findMax(Node*r)
  {
    while(r->right!=NULL)
      r = r->right;
    return r;
  }
  void print()
  {
    print(root);
  }
  void print(Node*r)
  {
    if(r!=NULL)
    {
      cout << r->data <<" ";
      print(r->left);
      print(r->right);
    }
  }
};

int main()
{
  BSTree someTree;
  someTree.Insert(17);
  someTree.Insert(20);
  someTree.Insert(14);
  someTree.Insert(5);
  someTree.Insert(10);
  someTree.Insert(25);
  someTree.Insert(33);
  someTree.Insert(11);
  someTree.Insert(15);
  someTree.Insert(22);
  someTree.Insert(12);
  someTree.Insert(7);
  someTree.Insert(8);
  someTree.print();
  cout << endl;
  someTree.Search(17);
  someTree.Search(22);
  someTree.Search(33);
  someTree.Search(13);
  cout << endl;
  someTree.Delete(15);
  someTree.Delete(20);
  someTree.Delete(17);
  someTree.print();
  return 0;
}
