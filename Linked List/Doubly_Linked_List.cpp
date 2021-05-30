#include <iostream>
using namespace std;

class Node
{
    public:
    int key, data;
    Node* next, *previous;

    Node()
    {
        key = 0;
        data =0;
        next = NULL;
        previous = NULL;
    }

    Node(int k,int d)
    {
        key = k;
        data = d; 
    }
};

class DoublyLinkedList
{
    public:
    Node*head;
    DoublyLinkedList()
    {
        head = NULL;
    }
    DoublyLinkedList(Node *n)
    {
        head = n;
    }
    Node* CheckExist(int k);
    void PrependNode(Node *n);
    void AppendNode(Node* n);
    void InsertNode(int k, Node* n);
    void DeleteNode(int k);
    void UpdateNode(int k, int d);
    void PrintList();
    Node* Inverse();
};

Node* DoublyLinkedList::CheckExist(int k)
{
    Node*temp = NULL;
    Node*ptr = head;
    while(ptr!=NULL)
    {
        if(ptr->key == k)
            temp = ptr;
        ptr = ptr ->next;
    }
    return temp;
}

void DoublyLinkedList:: PrependNode(Node*n)
{
    if(CheckExist(n->key)!=NULL)
    {
        cout <<"Can't prepend because node is already exist" << endl;
    }
    else
    {
        if(head == NULL)
        {
            head = n;
            cout <<"Node Prepended"<< endl;
        }
        else
        {
            Node*ptr = head;
            n->next = ptr;
            ptr->previous = n;
            head = n;
            cout <<"Node Prepended " << endl;
        }
    }
}

void DoublyLinkedList:: AppendNode(Node*n)
{
    if(CheckExist(n->key) != NULL)
    {
        cout <<"Can't Append because node is already exist" << endl;
    }
    else
    {
        if(head == NULL)
        {
            head = n;
            cout <<"Node Appended" << endl;
        }
        else
        {
            Node* ptr = head;
            while(ptr->next!=NULL)
            {
                ptr = ptr->next;
            }
            ptr->next =n;
            n->previous = ptr;
            cout <<"Node Appended" << endl;
        }
    }
}

void DoublyLinkedList:: UpdateNode(int k, int d)
{
    Node* ptr = CheckExist(k);
    if(ptr == NULL)
    {
        cout <<"Can't Update because there is no node have key " << k << endl;
    }
    else
    {
        ptr->data = d;
        cout <<"Node Updated" << endl;
    }
    
}

void DoublyLinkedList:: PrintList()
{
    if(head == NULL)
    {
        cout <<"List is empty" << endl;
    }
    else
    {
        Node *ptr = head;
        while(ptr!=NULL)
        {
            cout <<"(" << ptr->key <<"," <<ptr->data<<") "; 
            ptr=ptr->next;
        }
    }
}

Node* DoublyLinkedList:: Inverse()
{
    Node*p,*c,*n;
    p = NULL;
    c = head;
    while(c!=NULL)
    {
        n = c->next;
        c->next = p;
        p = c;
        c = n;
    }
    head = p;
    return head;
}

void DoublyLinkedList:: InsertNode(int k, Node *n)
{
    Node *ptr = CheckExist(k);
    if(ptr==NULL)
    {
        cout <<"Can't insert because the node of key " << k << " is exist" << endl;
    }
    else
    {
        if(CheckExist(n->key) != NULL)
        {
            cout <<"This node is already exist \n please insert another node" << endl;
        }
        else
        {
            Node* next_node = ptr->next;
            if(next_node == NULL)
            {
                ptr->next = n;
                n->previous = ptr;
                cout <<"Node Inserted" << endl;
            }
            else
            {
                n->next = next_node;
                next_node->previous = n;
                ptr->next = n;
                n->previous = ptr;
                cout <<"Node Inserted" << endl;
            }
        }
    }
}
void DoublyLinkedList:: DeleteNode(int k)
{
    Node* ptr = CheckExist(k);
    if(head == NULL)
    {
        cout <<"Can't Delete because list is empty" << endl;
    }
    else
    {
        if(head->key == k)
        {
            head = head->next;
            cout <<"Unlink with head node" << endl;
        }
        else
        {
            Node* next_node = ptr->next;
            Node* prev_node = ptr->previous;
            if(next_node == NULL)
            {
                ptr->previous = NULL;
                cout <<"Node Deleted " << endl;
            }
            else
            {
                prev_node->next = next_node;
                next_node->previous = prev_node;
                cout <<"Node Deleted" << endl;
            }
        } 
    }
}

int main()
{
    DoublyLinkedList obj;
    int _data, _key, pos, option;

    do
    {
        cout <<"Choose Operator to do \nchoose 0 to Exit" << endl;
        cout <<"1. Prepend Node" << endl;
        cout <<"2. Append Node" << endl;
        cout <<"3. Insert Node" << endl;
        cout <<"4. Delete Node" << endl;
        cout <<"5. Update Node" << endl;
        cout <<"6. Print List" << endl;
        cout << "7. Inverse Node" << endl;

        cin >> option;

        Node *node = new Node();
        switch(option)
        {
            case 0:
            {
                cout <<"Exiting...." << endl;
                goto label;
            }
            case 1:
            {
                cout <<"You choose PrependNode() \nPlease input Key and value ";
                cin >> _key;
                cin >> _data;
                node->key = _key;
                node->data = _data;
                obj.PrependNode(node);
                break;
            }
            case 2:
            {
                cout <<"You choose AppendNode() \nPlease input Key and value ";
                cin >> _key;
                cin >> _data;
                node->key = _key;
                node->data = _data;
                obj.AppendNode(node);
                break;
            }
            case 3:
            {
                cout <<"You choose InsertNode() \n Please input Position, key and value ";
                cin >> pos;
                cin >> _key;
                cin >> _data;
                node->key=_key;
                node->data=_data;
                obj.InsertNode(pos,node);
                break;
            }
            case 4:
            {
                cout <<"You choose DeleteNode() \n Please input the Node that you want to delete " << endl;
                cin >> pos;
                obj.DeleteNode(pos);
                break;
            }
            case 5:
            {
                cout <<"You choose UpdateNode() \n Please input the key new value of the Node " << endl;
                cin >>_key;
                cin >>_data;
                obj.UpdateNode(_key,_data);
                break;
            }
            case 6:
            {
                cout <<"The Doubly Linked List: ";
                obj.PrintList();
                cout << "List Printed "<< endl;
                break;
            }
            case 7:
            {
                cout <<"You choose Inverse Linked List" << endl;
                obj.Inverse();
                break; 
            }
        }
    } while (option != 0);
    label:
    return 0;
}