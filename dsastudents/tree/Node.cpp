#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node(T data = 0, Node<T> *next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

void create_list(Node<int> *&head, Node<int> *&tail, int *list)
{

    head = new Node<int>();
    tail = new Node<int>();
    head->next = tail;
    tail->next = head;

    Node<int> *cursor = head;
    for (int i = 0; i < 10; i++)
    {
        cursor->next = new Node<int> (list[i], cursor->next);
        cursor = cursor->next;
    }
    tail->next = cursor;
}
string toString(Node<int> *head, Node<int> *tail)
{
    if (head == NULL)
        return "[]";
    Node<int> *temp = head->next;
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

void remove(Node<int> *&head, Node<int> *&tail)
{
    Node<int> *temp = head->next;
    Node<int> *del;
    while (temp != tail)
    {
        del = temp;
        temp = temp->next;
        delete del;
    }
    delete head;
    delete tail;
    head = NULL;
    tail = NULL;
}

void print(Node<int> *head, Node<int> *tail)
{
    cout << toString(head, tail) << endl;
}

int main()
{
    int arr[10] = {5, 7, 2, 1, 3, 8, 9, 0, 3, 11};
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    create_list(head, tail, arr);
    print(head, tail);
    remove(head, tail);
    print(head, tail);
    return 0;
}
