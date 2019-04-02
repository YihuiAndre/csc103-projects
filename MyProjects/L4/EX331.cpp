/*
Write C++ functions for all of the following tasks and make sure you test them out.
Also make sure they don't fail on the empty list! (Sometimes a special case is required...)
(a)  Count the total number of elements in a list.
(b)  Append an item to the end of a list. The insert function above could be helpful, but perhaps try also to do it from scratch.
(c)  Deallocate an entire list (make the list empty, being sure to delete all the nodes).
(d)  Find the first occurrence of a value and remove it.
Hint:  either use two pointers(to keep track of the node before), or you'll have to look \ahead" to next->data.Extra  challenge:  do  it without  a  special  case  for  the   rst  node (maybe  using  a node** to go through the list).
(e)  Remove all nodes containing a particular value.  (
Note:  you  could  of  course  just call  the  above  over  and  over,  but  don't!   Doing  so  can  waste  time,  as  you  will repeatedly read through the beginning of the list. )
(f)  Insert an element before the first occurrence of a given value. The same hint given for (1d) applies here.  The same extra challenge also applies!
*/

#include<iostream>
#include<map>
using namespace std;

struct node{
	int data;
	node* next;
};

void printArr(node *&L); //print the array with node data type
void append(node*& L, int n); //append the number at the end of a list
void delArr(node*& L); //Delete entire array
void delFVal(node*& L, int x, bool stop = true); //Delete the first occurence value in the array
void delAVal(node*& L, int x); //Delete the specific value in the list
void appendTo(node *& L, int fVal, int sVal); 
//insert the value before the first occurence value 
//(note:FVal is the value that you append before that, SVal is 
//the value that you want to insert
bool detectCycle(node *& L);

int main()
{
	node* L = new node;
	L->data = 12;
	L->next = NULL;
	node * A = new node;
	A->data = 14;
	A->next = L;
	L->next = A;
	cout << detectCycle(A);
}

void printArr(node *&L)
{
	if (L == NULL) cout << "The list doesn't contain anything!" << endl;
	else{
		for (node* i = L; i != NULL; i = i->next)
		{
			cout << (*i).data << " ";
		}
		cout << endl;
	}
}

void append(node*& L, int n)
{

	node* temp = new node;
	temp->data = n;
	temp->next = NULL;
	if (L == NULL) L = temp;
	else
	{
		for (node* i = L; i != NULL; i = i->next)
		{
			if (i->next == NULL)
			{
				i->next = temp;
				break;
			}
		}
	}
}

void delArr(node*& L)
{
	if (L == NULL) return;
	node* n = new node;
	for (node* i = L; i != NULL; i = i->next)
	{
		n=i->next;
		delete L;
		L = n;
	}

}

void delFVal(node*& L, int x, bool stop)
{
	if (L == NULL) return;
	node* prev = new node;
	prev = NULL;
	for (node* i = L; i != NULL; i = i->next)
	{
		if (i->data == x)
		{
			if (i->next == NULL && prev == NULL) L=NULL;
			else if (prev ==NULL)
			{
				L = i->next;
			}
			else
			{
				prev->next=i->next;
			}
			delete i;
			if (stop) break;
		}
		prev = i;
	}

}

void delAVal(node*& L, int x)
{
	delFVal(L,x,false);
}
void appendTo(node *& L, int fVal, int sVal)
{
	if (L==NULL) return;
	node* temp = new node;
	temp->data=sVal;
	node* prev = new node;
	prev = NULL;
	for (node* i = L; i != NULL; i = i->next)
	{
		if (i->data == fVal)
		{
			if (prev == NULL)
			{
				temp->next=i;
				L = temp;
			}
			else
			{
				temp->next = i;
				prev->next = temp;
			}
			break;
		}
		prev = i;
	}
}

bool detectCycle(node *& L)
{
	map<node*,int> A;
	for (node* i = L; i != NULL; i++)
	{
		if (A[i->next]) return true; 
		else A[i->next]++;
	}
	return false;
}

