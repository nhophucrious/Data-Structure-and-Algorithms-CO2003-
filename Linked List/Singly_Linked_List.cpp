#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	int key;
	Node* next;

	Node()
	{
		data = 0;
		key = 0;
		next = NULL;
	}
	Node(int d, int k)
	{
		data = d;
		key = k;
		next = NULL;
	}
};
	class SinglyLinkedList
	{
	public:
		Node* head;
		SinglyLinkedList()
		{
			head = NULL;
		}
		SinglyLinkedList(Node* n)
		{
			head = n;
		}
		void AppendNode(Node* n);
		void PrependNode(Node* n);
		void InsertNode(int key, Node* n);
		void DeleteNode(int k);
		void UpdateNode(int k, int d);
		void PrintList();
		Node* InverseList();
		Node* NodeExists(int k);
	};

	Node* SinglyLinkedList::NodeExists(int k)
	{
		Node* temp = NULL;
		Node* ptr = head;
		while (ptr != NULL)
		{
			if (ptr->key == k)
				temp = ptr;
			ptr = ptr->next;
		}
		return temp;
	}

	void SinglyLinkedList::AppendNode(Node* n)
	{
		if (NodeExists(n->key) != NULL)
		{
			cout << "Node Exists, plese input another Node" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node Appended" << endl;
			}
			else
			{
				Node* ptr = head;
				while (ptr != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = n;
				cout << "Node Appended" << endl;
			}
		}
	}
	
	void SinglyLinkedList::PrependNode(Node* n)
	{
		if (NodeExists(n->key) != NULL)
		{
			cout << "Can't Prepend, plese input another Node" << endl;
		}
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "Node Prepended" << endl;
			}
			else
			{
				n->next = head;
				head = n;
				cout << "Node Prepended" << endl;
			}
		}
	}
	void SinglyLinkedList::InsertNode(int k, Node* n)
	{
		Node* ptr = NodeExists(k);
		if (ptr == NULL)
		{
			cout << "No Node Exist with key value" <<k << endl;
		}
		else
		{
			if (NodeExists(n->key) != NULL)
			{
				cout << "Already exists Node with key value: " << n->key << endl;
			}
			else
			{
				n->next = ptr->next;
				ptr->next= n;
				cout << "Node Inserted" << endl;
			}
		}
	}
	
	void SinglyLinkedList::DeleteNode(int k)
	{
		if (head == NULL)
		{
			cout << "Can't delete because there is no Node in the List" << endl;
		}
		else if (head != NULL)
		{
			if (head->key == k)
			{
				head = head->next;
				cout << "Unlinked Node with key value: " << k << endl;
			}
			else
			{
				Node* temp = NULL;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while (currentptr != NULL)
				{
					if (currentptr->key == k)
					{
						temp = currentptr;
						currentptr = NULL;
					}
					else
					{
						prevptr = prevptr->next;
						currentptr = currentptr->next;
					}
				}
				if (temp != NULL)
				{
					prevptr->next = temp->next;
					cout << "Node Deleted" << endl;
				}
				else
				{
					cout << "No Node with key value " << k << " to delete" << endl;
				}
			}
		}
	}

	void SinglyLinkedList::UpdateNode(int k, int d)
	{
		Node* ptr = NodeExists(k);
		if (ptr != NULL)
		{
			ptr->data = d;
			cout << "Node Updated" << endl;
		}
		else
		{
			cout << "Can not update Node with key " << k << endl;
		}
	}
	void SinglyLinkedList::PrintList()
	{
		Node* ptr = head;
		if (ptr == NULL)
		{
			cout << "There is no Node in List" << endl;
		}
		else
		{
			while (ptr != NULL)
			{
				cout << "(" << ptr->key << " , " << ptr->data << ")";
				ptr = ptr->next;
			}
		}
	}

	Node* SinglyLinkedList::InverseList()
	{
		Node* p, * c, * n;
		p = NULL;
		c = head;
		while (c != NULL)
		{
			n = c->next;
			c->next = p;
			p = c;
			c = n;
		}
		head = p;
		return head;
	}
	int main()
	{
		SinglyLinkedList s;
		int option, key1, k1, data1;
		do
		{
			cout << "Choose your operation to perform" << endl;
			cout << "1. PrependNode()" << endl;
			cout << "2. AppendNode()" << endl;
			cout << "3. InsertNode()" << endl;
			cout << "4. DeleteNode()" << endl;
			cout << "5. UpdateNode()" << endl;
			cout << "6. PrintList()" << endl;
			cout << "7. Clear Screen" << endl;
			cout << "8. InverseList()" << endl;
			cout << "0. Exit" << endl;

			Node* node = new Node();
			cin >> option;
			switch (option)
			{
				case 0:
				{
					cout << "Existing....." << endl;
					break;
				}
				case 1:
				{
					cout << "You choose PrependNode" << endl;
					cout << "Input Key and value of Node: " << endl;
					cin >> key1;
					cin >> data1;
					node->key = key1;
					node->data = data1;
					s.PrependNode(node);
					break;
				}
				case 2:
				{
					cout << "You choose AppendNode" << endl;
					cout << "Input Key and value of Node: " << endl;
					cin >> key1;
					cin >> data1;
					node->key = key1;
					node->data = data1;
					s.AppendNode(node);
					break;
				}
				case 3:
				{
					cout << "You choose InsertNode" << endl;
					cout << "Input key: "; cin >> key1;
					cout << "Input data "; cin >> data1;
					cout << "input position"; cin >> k1;
					node->key = key1;
					node->data = data1;
					s.InsertNode(k1, node);
					break;
				}
				case 4:
				{
					cout << "You choose DeleteNode" << endl;
					cout << "Input Key: " << endl;
					cin >> k1;
					s.DeleteNode(k1);
					break;
				}
				case 5:
				{
					cout << "You choose UpdateNode" << endl;
					cout << "Input data "; cin >> data1;
					cout << "input position"; cin >> k1;
					s.UpdateNode(k1, data1);
					break;
				}
				case 6:
				{
					cout << "The Linked List is:" << endl;
					s.PrintList();
					cout << endl;
					break;
				}
				case 8:
				{
					s.InverseList();
					cout << "Node Inverse " << endl;
					break;
				}
			}
		} while (option != 0);
		return 0;
	}