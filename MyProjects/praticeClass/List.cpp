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
private:
    node* root;

};

List::List()
{
    this->root = NULL;
}

void insertAtFront(int x)
{
    node* i = new node;
    i->data = x;
    i->next = root;
    
}

List::List(const List &L)
{
    
}

int main()
{
    return 0;
}