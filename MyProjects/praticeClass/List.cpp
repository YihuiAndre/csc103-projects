#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

class List{
public:
    List();
    List(const List &L);
    ~List();
    void insertAtFront(int x);
	void display();
	void insertAtBack(int x);
private:
    node* root;
};

List::List()
{
    this->root = NULL;
}

List::List(const List &L)
{
    node* copyL = L.root;
	node* i = new node;
	this->root = i;
	while (copyL)
	{
		i->data = copyL->data;
		i->next = copyL->next;
		copyL = copyL->next;
		i = i->next;
	}
}

List::~List()
{
	for (node* i = this->root; i != NULL; i = this->root)
	{
		(this->root) = (this->root)->next;
		delete i;
	}
}

void List::insertAtFront(int x)
{
	node* begin = new node;
	begin->data = x;
	begin->next = this->root;
	this->root = begin;
}

void List::insertAtBack(int x)
{
	node* back = new node;
	back->data = x;
	back->next = NULL;
	node* i = this->root;
	while (i!=NULL && i->next != NULL) i = i->next;
	if (i==NULL) this->root = back;
	else i->next = back;
}

void List::display()
{
	for (node* i = this->root; i != NULL; i=i->next)
	{
		cout << i->data << " ";
	}
	cout << "\n";
}

int main()
{
	List L;
	L.insertAtBack(1);
	L.insertAtBack(2);
	L.display();
	List A(L);
	A.display();
	A.insertAtFront(3);
    return 0;
}
