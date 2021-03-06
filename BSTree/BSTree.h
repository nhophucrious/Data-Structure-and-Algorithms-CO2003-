#include "Dictionary.h"
#include "BSTNode.h"
#include "BinNode.h"

// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
class BST : public Dictionary<Key, E>
{
private:
    BSTNode<Key, E> *root; // Root of the BST int nodecount;
    // Number of nodes in the BST
    // Private "helper" functions
    void clearhelp(BSTNode<Key, E> *);
    BSTNode<Key, E> *inserthelp(BSTNode<Key, E> *, const Key &, const E &);
    BSTNode<Key, E> *deletemin(BSTNode<Key, E> *);
    BSTNode<Key, E> *getmin(BSTNode<Key, E> *);
    BSTNode<Key, E> *removehelp(BSTNode<Key, E> *, const Key &);
    E findhelp(BSTNode<Key, E> *, const Key &) const;
    void printhelp(BSTNode<Key, E> *, int) const;

public:
    BST()
    {
        root = NULL;
        nodecount = 0; // Constructor
    }
    ˜BST()
    {
        clearhelp(root); // Destructor
    }
    void clear() // Reinitialize tree
    {
        clearhelp(root);
        root = NULL;
        nodecount = 0;
    }
    // Insert a record into the tree.
    // k Key value of the record.
    // e The record to insert.
    void insert(const Key &k, const E &e)
    {
        root = inserthelp(root, k, e);
        nodecount++;
    }
    // Remove a record from the tree.
    // k Key value of record to remove.
    // Return: The record removed, or NULL if there is none.
    E remove(const Key &k)
    {
        E temp = findhelp(root, k);
        // First find it
        if (temp != NULL)
        {
            root = removehelp(root, k);
            nodecount--;
        }
        return temp;
    }
    // Remove and return the root node from the dictionary. // Return: The record removed, null if tree is empty.
    E removeAny()
    { // Delete min value
        if (root != NULL)
        {
            E temp = root->element();
            root = removehelp(root, root->key());
            nodecount--;
            return temp;
        }
        else
            return NULL;
    }
    // Return Record with key value k, NULL if none exist.
    // k: The key value to find. */
    // Return some record matching "k".
    // Return true if such exists, false otherwise. If
    // multiple records match "k", return an arbitrary one. E
    find(const Key &k) const
    {
        return findhelp(root, k);
    }
    // Return the number of records in the dictionary.
    int size()
    {
        return nodecount;
    }
    void print() const
    {
        // Print the contents of the BST
        if (root == NULL)
            cout << "The BST is empty.\n";
        else
            printhelp(root, 0);
    }
};

template <typename Key, typename E>
E BST<Key, E>::findhelp(BSTNode<Key, E> *, const Key &) const
{
    if (root == NULL)
        return NULL; // Empty tree
    if (k < root->key())
        return findhelp(root->left(), k); // Check left
    else if (k > root->key())
        return findhelp(root->right(), k); // Check right
    else
        return root->element(); // Found it
}

// Remove a node with key value k
// Return: The tree with the node removed
template <typename Key, typename E>
BSTNode<Key, E> *BST<Key, E>::removehelp(BSTNode<Key, E> *rt, const Key &k)
{
    if (rt == NULL)
        return NULL; // k is not in tree else if (k < rt->key())
    rt->setLeft(removehelp(rt->left(), k));
    else if (k > rt->key())
        rt->setRight(removehelp(rt->right(), k));
    else
    {
        BSTNode<Key, E> *temp = rt;
        if (rt->left() == NULL)
        {
            rt = rt->right();
            delete temp;
        }
        else if (rt->right() == NULL)
        { // Only a left child rt = rt->left(); delete temp;
            // so point to left } else { // Both children are non-empty
            BSTNode<Key, E> *temp = getmin(rt->right());
            rt->setElement(temp->element());
            rt->setKey(temp->key());
            rt->setRight(deletemin(rt->right()));
            delete temp;
        }
    }
    return rt;
}

template <typename Key, typename E>
void BST<Key, E>::clearhelp(BSTNode<Key, E> *root)
{
    if (root == NULL)
        return;
    clearhelp(root->left());
    clearhelp(root->right());
    delete root;
}

template <typename Key, typename E>
void BST<Key, E>::printhelp(BSTNode<Key, E> *root, int level) const
{
    if (root == NULL)
        return;
    // Empty tree
    printhelp(root->left(), level + 1); // Do left subtree
    for (int i = 0; i < level; i++)     // Indent to level
        cout << " ";
    cout << root->key() << "\n"; // Print node value
    printhelp(root->right(), level + 1);// Do right subtree
}