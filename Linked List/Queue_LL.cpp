#include <iostream>
using namespace std;

class Node
{
    public:
    int key, data;
    Node* next;

    Node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }

    Node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};

class Queue
{
    public:
    Node*rear, *front;
    Queue()
    {
        rear = NULL;
        front = NULL;
    }

    bool isEmpty();
    void enqueue(Node* n);
    void dequeue();
    int count();
    void display();
    void change(int k, int d);
    bool is_Exist(Node*n);  
    bool is_Exist(int k);   
    Node* traverse(int k);
};

bool Queue::is_Exist(Node*n)
{
    Node*temp = front;
    bool check = false;
    while(temp!=NULL)
    {
        if(temp->key == n->key)
            {
                check = true;
                break;
            }
        temp = temp->next;
    }
    return check;
}

bool Queue::is_Exist(int k)
{
    Node*temp = front;
    bool check = false;
    while(temp!=NULL)
    {
        if(temp->key == k)
            {
                check = true;
                break;
            }
        temp = temp->next;
    }
    return check;
}

Node* Queue::traverse(int k)
{
    Node*temp = NULL;
    Node*ptr = front;
    while(ptr!=NULL)
    {
        if(ptr->key == k)
            temp = ptr;
        ptr = ptr->next;
    }
    return temp;
}
bool Queue::isEmpty()
{
    return(rear == NULL && front == NULL);
}
void Queue::enqueue(Node*n)
{
    if(isEmpty() == true)
    {
        rear = n;
        front = n;
        cout <<"Node is enqueued" << endl;
    }
    else if(is_Exist(n) == true)
    {
        cout <<"This node is already exist" << endl;
    }
    else
    {
        rear -> next = n;
        rear = n;
        cout <<"Node is enqueued" << endl;
    }
    
}
void Queue::dequeue()
{
    if(isEmpty() == true)
    {
        cout <<"Queue is empty" << endl;
    }
    else if(rear == front) //only 1 Node in queue
    {
        Node*temp = front;
        front = NULL;
        rear = NULL;
        delete temp;
    }
    else // dequeue 
    {
        Node*temp = front;
        front = front ->next;
        delete temp;
    }
    
}

void Queue::change(int k, int d)
{
    if(is_Exist(k) == false)
    {
        cout <<"There is no Node with key " << k <<" to change its data" << endl;
    }
    else
    {
        Node*temp = front;
        while(temp!=NULL)
        {
            if(temp->key == k)
            {
                temp->data = d;
                cout <<"Data of Node changed"<< endl;
            }
            temp = temp->next;
        }
    }
}

int Queue::count()
{
    int count = 0;
    Node* ptr = front;
    while(ptr!=NULL)
    {
        count ++;
        ptr= ptr->next;
    }
    return count;
}

void Queue::display()
{
    if (isEmpty()== true)
        cout <<"Queue is empty" << endl;
    else
    {
        Node*temp = front;
        while(temp!= NULL)
        {
            cout <<"("<<temp->key<<","<<temp->data<<")";
            temp = temp->next;
        }
    }
}
int main()
{
    Queue q;
    int _key, _data, option;

    do
    {
        cout <<"Choosing your operator: "<< endl;
        cout <<"1.enqueue()" << endl;
        cout <<"2.dequeue()"<< endl;
        cout <<"3.isEmpty()"<<endl;
        cout <<"4.count()"<< endl;
        cout <<"5.change()"<< endl;
        cout <<"6.display()"<< endl;
        cout <<"0.exist"<< endl;

        cin >> option;
        Node* new_node = new Node();

        switch(option)
        {
            case 0:
            {
                cout <<"System is exiting....." << endl;
                goto label;
                break;
            }
            case 1:
            {
                cout <<"You choose enqueue()....." << endl;
                cout <<"Input key: "; cin>> _key;
                cout <<"Input value:"; cin >> _data;
                new_node->data = _data;
                new_node->key = _key;
                q.enqueue(new_node);
                break;
            }
            case 2:
            {
                cout <<"You choose dequeue()....." << endl;
                q.dequeue();
                break;
            }
            case 3:
            {
                cout <<"You choose isEmpty()....." << endl;
                q.isEmpty();
                break;
            }
            case 4:
            {
                cout <<"You choose count()....." << endl;
                cout <<"Number of node in this queue: "<< q.count();
                break;
            }
            case 5:
            {
                cout <<"You choose change()....." << endl;
                cout <<"Input key: "; cin>> _key;
                cout <<"Input value:"; cin >> _data;
                q.change(_key,_data);
                break;
            }
            case 6:
            {
                cout <<"You choose display()....." << endl;
                q.display();
                break;
            }
        }

    } while (option!=0);
    label:    
    return 0;
}
