#include<iostream>
using std::cin;
using std::cout;

class vector2 {
	public:
		vector2 (size_t initCapacity = 16);
		vector2 (const vector2& V); //copy the vector
		size_t sizeOf() {return size;}
		vector2& operator=(vector2 V);
		bool operator==(vector2 V);
		void push_back (int a);
		void display();


	private:
		size_t size;
		size_t capacity;
		int *data;
};

vector2::vector2(size_t initCapacity)
{
	capacity = initCapacity;
	data = new int[initCapacity];
	size = 0;
}
vector2::vector2(const vector2& V)
{
	size = V.size;
	capacity = V.capacity;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = V.data[i];
	}
}
vector2& vector2::operator=(vector2 V)
{
	int *tmp = data;
	data = V.data;
	//V.data = tmp;
	size = V.size;
	capacity = V.capacity;
	return (*this);
}
void vector2::push_back(int a)
{
	if(size < capacity)
	{
		data[size] = a;
		size++;
	}
}
void vector2::display()
{
	for (int i = 0; i < size; i++)
	{
		cout << data[i];
	}
	cout << "\n";
}

int main()
{
	vector2 V;
	V.push_back(12);
	V.display();
	vector2 V2;
	V2.push_back(13);
	V2 = V;
	V2.display();
	V.display();
}

