#include <iostream>
using namespace std;

class Node
{
  public:
  int value;
  Node*left;
  Node*right;
  Node*parent;
  Node(int v)
  {
    value = v;
    left = right = parent = NULL;
  }
  
};
class SplayTree
{
  public:
  Node*root;
  SplayTree()
  {
    root = NULL;
  }
  void insert(int value)
  {
    root = SplayInsert(root,value);
  }
  void search(int value)
  {
    Node* find = SplaySearch(root,value);
    if(find == NULL)
      cout <<"Not Found"<< endl;
    else
      cout <<"Found"<< endl;
  }
  void Delete(int value)
  {
    Node*new_tree = SplayDelete(root,value);
    if(new_tree == NULL)
      cout <<"Not Found to delete"<< endl;
    else
      root = new_tree;
  }
  void zig(Node*&r, Node*gp)
  {
    Node*p = gp->left;
    gp->left = p->right;
    if(p->right != NULL)
      p->right->parent = gp;
    p->parent = gp->parent;
    if(gp->parent == NULL)
      r = p;
    else if(gp == gp->parent->right)
      gp->parent->right = p;
    else if(gp==gp->parent->left)
      gp->parent->left = p;
    p->right = gp;
    gp->parent = p;
  }
  void zag(Node*&r, Node*gp)
  {
    Node*p = gp->right;
    gp->right = p->left;
    if(p->left!=NULL)
      p->left->parent = gp;
    p->parent = gp->parent;
    if(gp->parent == NULL)
      r = p;
    else if(gp == gp->parent->right)
      gp->parent->right = p;
    else
      gp->parent->left = p;
    p->left = gp;
    gp->parent = p;
  }
  void Splay(Node*&r,Node*n)
  {
    while(n->parent!=NULL)
    {
      if(n->parent == r)
      {
        if(r->left == n)
          zig(r,r);
        else
          zag(r,r);
      }
      else
      {
        Node*p = n->parent;
        Node*gp =  p->parent;
        if(n == p->left && p == gp->left)
        {
          zig(r,gp);
          zig(r,p);
        }
        else if(n == p->right && p == gp->right)
        {
          zag(r,gp);
          zag(r,p);
        }
        else if(n == p->left && p == gp->right)
        {
          zig(r,p);
          zag(r,gp);
        }
        else
        {
          zag(r,p);
          zig(r,gp);
        }
      }
    }
  }
  Node* SplayInsert(Node*r,int value)
  {
    Node*new_node = new Node(value);
    Node*currParent = NULL;
    Node*TreeNode = r;
    while(TreeNode!=NULL)
    {
      currParent = TreeNode;
      if(value< TreeNode->value)
        TreeNode = TreeNode->left;
      else
        TreeNode = TreeNode->right;
    }
    new_node->parent = currParent;
    if(currParent == NULL)
      r = new_node;
    else if(value < currParent->value)
      currParent->left = new_node;
    else if(value > currParent->value)
      currParent->right = new_node;
    else
      cout << "Duplicate Node" << endl;
    Splay(r,new_node);
    return r;
  }
  Node*SplaySearch(Node*&r, int value)
  {
    Node* treeNode = r;
    while(treeNode!=NULL && value != treeNode->value)
    {
      if(value < treeNode->value)
        treeNode = treeNode->left;
      else
        treeNode = treeNode->right;
    }
    if(treeNode == NULL)
      return treeNode;
    else
    {
      Splay(r,treeNode);
      return r;
    }
  }
  Node*traverse(Node*r,int value)
  {
    if(r == NULL)
      return r;
    else
    {
      while(r!=NULL && value != r->value)
      {
        if(value < r->value)
          r = r->left;
        else
          r = r->right;
      }
    }
    return r;
  }
  Node* SplayDelete(Node* r, int value)
        {
            if (r == NULL) // root = NULL 
                return r; // return root
            Node* find = traverse(r, value); //find node have key
            if (find == NULL) // if there is no node has key key
                return find;
            else
                Splay(r, find); // if there is a node has key key, then splay it to the root
            Node* leftTree = r->left;
            Node* rightTree = r->right;
            if (leftTree == NULL)
            {
                Node* temp = r;
                rightTree->parent = temp->parent;
                r = rightTree;
                delete temp;
            }
            else if (rightTree == NULL)
            {
                Node* temp = r;
                leftTree->parent = temp->parent;
                r = leftTree;
                delete temp;
            }
            else
            {
                Node* temp = r;
                leftTree->parent = temp->parent;
                Node* max = findMax(leftTree);
                Splay(leftTree, max);
                leftTree->right = rightTree;
                rightTree->parent = leftTree;
                r = leftTree;
                delete temp;
            }
            return r;
        }

  Node*findMax(Node*r)
  {
    while(r->right!=NULL)
      r = r->right;
    return r;
  }
  void print(Node*r)
  {
    if(r!=NULL)
    {
      cout << r->value << " ";
      print(r->left);
      print(r->right);
    }
  }
  void print()
  {
    print(root);
  }
};



int main()
{
  SplayTree someTree;
  int arr[] = {23, 44, 15, 22, 11, 9, 66, 18, 67};
  int size = sizeof(arr)/sizeof(int);
  for(int i = 0; i < size;i ++)
  {
    someTree.insert(arr[i]);
  }
  someTree.print();
  cout << endl;
  someTree.search(44);
  someTree.print();
  cout << endl;
  someTree.Delete(18);
  someTree.Delete(44);
  someTree.Delete(15);
  someTree.print();
  return 0;
}