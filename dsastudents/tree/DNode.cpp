#include <iostream>
#include <sstream>
#include <string>
using namespace std;

template<class T>
struct DNode
{
    T data;
    DNode<T> *next, *prev;

    DNode(T value, DNode<T> *prev = NULL, DNode<T> *next = NULL)
    {
        this->data = value;
        this->prev = prev;
        this->next = next;
    }
};

template <class T>
void create_list(DNode<T>*&head, DNode<T>*&tail, T*arr)
{
    head = tail = new DNode<T>(0);
    head->next = tail;
    tail->prev = head;

    DNode<int> *temp = head;
    for (int i = 0; i < 10; i++)
    {
        temp->next = new DNode<int>(arr[i], temp, temp->next);
        temp = temp->next;
    }
    tail->prev = temp;
}

template<class T>
void remove(DNode<T>*&head, DNode<T>*&tail)
{
    DNode<T> *ptr = head->next;
    DNode<T> *temp;
    while (ptr!=tail)
    {
        temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
    delete head;
    head = NULL;
    tail = NULL;
}

template<class T>
string toString(DNode<T>*&head, DNode<T>*&tail)
{
    if(head == NULL)
        return "[]";
    DNode<T> *temp = head->next;
    stringstream os;
    while(temp!=tail)
    {
        os << temp->data << ", ";
        temp = temp->next;
    }
    string result = os.str();
    result = result.substr(0, result.rfind(","));
    return "[" + result + "]";
}

template<class T>
void print(DNode<T>*head, DNode<T>* tail)
{
    cout << toString(head, tail) << endl;
}

int main()
{
    int arr[10] = {5, 7, 2, 1, 3, 8, 9, 0, 3, 11};
    DNode<int> *head = NULL;
    DNode<int> *tail = NULL;
    create_list(head, tail, arr);
    print(head, tail);
    remove(head, tail);
    print(head, tail);
    
    return 0;
}
