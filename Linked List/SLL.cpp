#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    void reverse();
    void swapBetween(int index1, int index2);
    void swapBetweenByValue(T val1, T val2);
    void bubbleSort();
    string toString();

    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator(SLinkedList<T> *pList = NULL, bool begin = true)
        {
            this->pList = pList;
            if (begin == true)
            {
                if (this->pList != NULL)
                {
                    index = 0;
                    this->current = pList->head;
                }
                else
                {
                    index = -1;
                    this->current = NULL;
                }
            }
            else
            {
                if (this->pList != NULL)
                {
                    index = this->pList->size();
                    this->current = NULL;
                }
                else
                {
                    index = 0;
                    this->current = NULL;
                }
            }
        }
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        void remove();
        bool operator!=(const Iterator &iterator);

        // Prefix ++ overload
        Iterator &operator++();

        // Postfix ++ overload
        Iterator operator++(int);
    };
};
/////////////////////////////////////////////////////////////////////////
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator=(const Iterator &iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */

    if (current == NULL)
        throw std::out_of_range("Segmentation fault!");

    if (this->pList->head == current)
    {
        this->current = NULL;
        this->index = -1;
        return;
    }

    Node *curr = this->pList->head->next;
    Node *prev = this->pList->head;
    while (curr != NULL)
    {
        if (curr == this->current)
        {
            //Connect the next Node of Curr;
            prev->next = curr->next;
            //if curr is the last Node => re assign tail
            if (pList->tail == curr)
                pList->tail = prev;
            curr->next = NULL;
            this->index = -1;
            delete curr;
            this->current = prev;
            this->pList->count--;
            return;
        }
        curr = curr->next;
        prev = prev->next;
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T &e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");
    else
        this->current->data = e;
}

template <class T>
T &SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (current == NULL)
        throw std::out_of_range("Segmentation fault!");
    return current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator &iterator)
{
    /*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
    if ((this->current != iterator.current) && (this->index != iterator.index))
        return true;
    else
        return false;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator &SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (this->current->next == this->pList->head)
        this->current = this->pList->head;

    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");

    current = current->next;
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */

    if (this->current->next == this->pList->head)
        this->current = this->pList->head;

    if (this->current == NULL)
        throw std::out_of_range("Segmentation fault!");

    Iterator iterator = *this;
    ++*this;
    return iterator;
}
////////////////////////////////////////////////////////////////////////

template <class T>
T SLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    if (empty() == true || index < 0 || index > count - 1)
    {
        throw out_of_range("The index is out of range!");
    }
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return (temp->data);
}

template <class T>
void SLinkedList<T>::set(int index, const T &e)
{
    /* Assign new value for element at given index in the list */
    if (empty() == true || index > count)
        return;
    Node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    temp->data = e;
}

template <class T>
bool SLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    return (count == 0);
}

template <class T>
int SLinkedList<T>::indexOf(const T &item)
{
    /* Return the first index wheter item appears in list, otherwise return -1 */
    if (empty() == true)
        return -1;
    if (head->data == item)
        return 0;
    Node *temp = head;
    int pos = 0;
    while (temp != NULL)
    {
        if (temp->data == item)
        {
            return pos;
        }
        pos++;
        temp = temp->next;
    }
    return -1;
}

template <class T>
bool SLinkedList<T>::contains(const T &item)
{
    if (empty() == true)
        return false;
    Node *ptr = head;
    if (ptr->data == item)
        return true;
    while (ptr != nullptr)
    {
        if (ptr->data == item)
            return true;
        ptr = ptr->next;
    }
    return false;
}

template <class T>
void SLinkedList<T>::add(const T &e)
{
    /* Insert an element into the end of the list. */
    Node *newNode = new Node(e, NULL);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = new Node(e, NULL);
        tail = tail->next;
    }
    count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T &e)
{
    /* Insert an element into the list at given index. */
    if (index == count || count == 0)
    {
        add(e);
    }
    else if (index == 0)
    {
        if (head == NULL)
        {
            head = new Node(e, NULL);
            tail = head;
        }
        else
        {
            Node *newNode = new Node(e, NULL);
            newNode->next = head;
            head = newNode;
        }
        count++;
    }
    else
    {
        Node *newNode = new Node(e, NULL);
        Node *ptr = head;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
        }
        if (ptr->next == NULL)
        {
            ptr->next = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        count++;
    }
}

template <class T>
int SLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return count;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    T answer;
    /* Remove element at index and return removed value */
    if (empty() == true || index < 0 || index > count)
        throw out_of_range("The index is out of range!");
    if (index == 0)
    {
        Node *temp = head;
        answer = temp->data;
        head = head->next;
        delete temp;
    }
    else if (index == count - 1)
    {
        Node *ptr = head;
        while (ptr->next != tail)
            ptr = ptr->next;
        Node *temp = tail;
        answer = temp->data;
        tail = ptr;
        delete temp;
    }
    else
    {
        Node *prev = head;
        Node *curr = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = curr->next;
        answer = curr->data;
        delete curr;
    }
    count--;
    return answer;
}

template <class T>
bool SLinkedList<T>::removeItem(const T &item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (empty() == true)
        return false;
    if (head->data == item && count == 1)
    {
        delete head;
        head = tail = NULL;
        count--;
        return true;
    }
    else if (head->data == item)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        count--;
        return true;
    }
    else
    {
        Node *prev = head;
        Node *curr = head->next;
        while (curr != NULL)
        {
            if (curr->data == item)
            {
                break;
            }
            prev = prev->next;
            curr = curr->next;
        }
        if (curr == NULL)
            return NULL;
        prev->next = curr->next;
        tail = prev;
        delete curr;
        count--;
        return true;
    }
    return false;
}

template <class T>
void SLinkedList<T>::clear()
{
    /* Remove all elements in list */
    if (empty() == true)
        return;
    else
    {

        while (head->next != tail)
        {
            Node *temp = head->next;
            head = head->next;
            delete temp;
            count--;
        }
        tail->next = head;
    }
}
template <class T>
string SLinkedList<T>::toString()
{
    stringstream ss;
    ss << "[";
    Node *ptr = head;

    if (count == 0)
        ss << "]";
    else
    {
        ss << ptr->data;

        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
            ss << ", " << ptr->data;
        }

        ss << "]";
    }

    return ss.str();
}

template <typename T>
void SLinkedList<T>::reverse()
{
    Node *prev, *curr, *next;
    prev = next = NULL;
    curr = head;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
template <typename T>
void SLinkedList<T>::swapBetween(int index1, int index2)
{

    if(index1 == index2)
        return;

    // get index
    Node *prev1 = NULL;
    Node *prev2 = NULL;
    Node *idx1 = head;
    Node *idx2 = head;
    for (int i = 0; i < index1; i++)
    {
        prev1 = idx1;
        idx1 = idx1->next;
    }
    for (int i = 0; i < index2; i++)
    {
        prev2 = idx2;
        idx2 = idx2->next;
    }

    if(prev1!=NULL)
        prev1->next = idx2;
    else
        head = idx2;

    if(prev2!=NULL)
        prev2->next = idx1;
    else
        head = idx1;

    //get Next Node
    Node *next1 = idx1->next;
    Node *next2 = idx2->next;
    idx1->next = next2;
    idx2->next = next1;
}
template<typename T>
void SLinkedList<T>::swapBetweenByValue(T val1, T val2)
{

    if(val1 == val2)
        return;

    // get index
    Node *prev1 = NULL;
    Node *prev2 = NULL;
    Node *idx1 = head;
    Node *idx2 = head;
    while (idx1 && idx1->data!=val1)
    {
        prev1 = idx1;
        idx1 = idx1->next;
    }
    while (idx2 && idx2->data!=val2)
    {
        prev2 = idx2;
        idx2 = idx2->next;
    }
    if(idx1 == NULL || idx2 == NULL)
        return;

    if(prev1!=NULL)
        prev1->next = idx2;
    else
        head = idx2;

    if(prev2!=NULL)
        prev2->next = idx1;
    else
        head = idx1;

    //get Next Node
    Node *next1 = idx1->next;
    Node *next2 = idx2->next;
    idx1->next = next2;
    idx2->next = next1;
}
template<typename T>
void SLinkedList<T>::bubbleSort()
{

    for(int i = 0; i < size();i++)
        for (int j = i + 1; j < size();j++)
        {
            if(get(j) < get(i))
            {
                swapBetween(i, j);
            }
        }

}

///////////////////////////////////////////////////////////////////////////////////
class Polynomial;
class Term
{
private:
    double coeff;
    int exp;
    friend class Polynomial;

public:
    Term(double coeff = 0.0, int exp = 0)
    {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term &rhs) const
    {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream &operator<<(ostream &os, const Term &term)
    {
        cout << endl;
        cout << "Term: "
             << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial
{
private:
    SLinkedList<Term> *terms;

public:
    Polynomial()
    {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial()
    {
        this->terms->clear();
    }
    void insertTerm(const Term &term);
    void insertTerm(double coeff, int exp);
    void print()
    {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++)
        {
            cout << (*it);
        }
        cout << endl
             << "]";
    }
};
///////////////////////////////////////////////////////////////////////////////////
void Polynomial::insertTerm(const Term &term)
{
    int size = terms->size();
    if (term.coeff == 0)
        return;
    else if (terms->empty() == true)
    {
        terms->add(term);
    }
    else if (term.exp == 0 && terms->empty() == false)
    {
        terms->add(term);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (term.exp > terms->get(i).exp)
            {
                terms->add(i, term);
                break;
            }

            if (term.exp == terms->get(i).exp)
            {
                Term newTerm(term.exp, term.coeff + terms->get(i).coeff);
                terms->set(i, newTerm);
                if (terms->get(i).coeff == 0)
                {
                    terms->removeAt(i);
                }
                break;
            }
        }
    }
}
void Polynomial::insertTerm(double coeff, int exp)
{
    int size = terms->size();
    Term term(coeff, exp);

    if (coeff == 0)
        return;
    else if (terms->empty() == true)
    {
        terms->add(term);
    }
    else if (exp == 0 && terms->empty() == false)
    {
        terms->add(term);
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (exp > terms->get(i).exp)
            {
                terms->add(i, term);
                break;
            }

            if (exp == terms->get(i).exp)
            {
                Term newTerm(coeff + terms->get(i).coeff, exp);
                terms->set(i, newTerm);
                if (terms->get(i).coeff == 0)
                {
                    terms->removeAt(i);
                }
                break;
            }
        }
    }
}
int main()
{
    SLinkedList<int> list;
    list.add(5);
    list.add(19);
    list.add(7);
    list.add(9);
    list.add(23);
    list.add(2);
    cout << list.toString() << endl;
    list.bubbleSort();
    cout << list.toString() << endl;
    return 0;
}
