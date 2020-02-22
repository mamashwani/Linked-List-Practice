#include <iostream>
#include <string>

using namespace std;

template<typename ST>
struct node 
{
	ST data;
	node<ST>* next;
};

template<typename T>
class list 
{
private:
	node<T>* head;
	node<T>* tail;
	int count = 0;
public:
	list()
	{
		head = nullptr;
		tail = nullptr;
	}

	
	void add_at_end(T value) 
	{
		
		node<T>* temp = new node<T>;
		temp->data = value;
		temp->next = nullptr;
		node<T>* curr = nullptr;
		curr = head;
		if (head == nullptr) 
		{
			head = temp;
			tail = temp;
			temp = nullptr;
		}
		else 
		{
			while (curr->next != nullptr)
			{
				curr = curr->next;
			}
			curr->next = temp;
			temp->next = nullptr;
		}
		count++;
	}

	void add_at_beg(T value) 
	{
		node<T>* temp = new node<T>;
		temp->data = value;
		temp->next = head;
		head = temp;
		count++;
	}

	void add_at_index(T value, int pos) 
	{
		node<T>* temp = new node<T>;
		temp->data = value;
		node<T>* curr = nullptr;
		node<T>* pre = nullptr;
		curr = head;
		if (pos <= 0) 
		{
			cout << "negative or zero index is not valid" << endl;
			return;
		}
		if(pos > count)
		{
			pos = ++count; //adds at end
		}
		for (int i = 1; i < pos; i++) 
		{
			pre = curr;
			curr = curr->next;
		}
		pre->next = temp;
		temp->next = curr;
		count++;
	}

	void delete_at_beg() 
	{
		if (head == nullptr) 
		{
			cout << "Cant delete from empty link list" << endl;
			return;
		}
		node<T>* curr = nullptr;
		curr = head;
		head = head->next;
		delete curr;
		count--;
	}

	void delete_at_end() 
	{
		if (head == nullptr) 
		{
			cout << "cant delete from empty link list" << endl;
		}
		node<T>* pre = nullptr;
		node<T>* curr = nullptr;
		curr = head;
		while (curr->next != nullptr) 
		{
			pre = curr;
			curr = curr->next;
		}
		tail = pre;
		pre->next = nullptr;
		delete curr;
		count--;
	}

	void delete_at_index(int pos) 
	{
		if (pos <= 0) 
		{
			cout << "index entered is 0 or negative, not valid index" << endl;
		}
		if (pos > count) 
		{
			cout << "invalid position" << endl;
		}
		node<T>* curr = nullptr;
		node<T>* pre = nullptr;
		curr = head;
		for (int i = 1; i < pos; i++) 
		{
			pre = curr;
			curr = curr->next;
		}
		pre->next = curr->next;
		curr->next = nullptr;
		delete curr;
		count--;
	}

	void display()
	{
		node<T>* temp = new node<T>;
		temp = head;
		while (temp != nullptr)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl; //everytime display is called a line i will be skipped always
	}
};

int main()
{
	list<int> link_list;
	list<string> linked_list;

	link_list.add_at_end(1);
	link_list.add_at_end(2);
	link_list.add_at_end(3);
	link_list.add_at_end(4);
	link_list.add_at_index(10, 3);
	link_list.display();
	

	linked_list.add_at_beg("he");
	linked_list.add_at_beg("hel");
	linked_list.add_at_beg("hell");
	linked_list.add_at_beg("hello");
	linked_list.add_at_beg("helloo");
	linked_list.add_at_index("index!", 4);
	linked_list.display();
	

	link_list.add_at_beg(1);
	link_list.add_at_beg(2);
	link_list.add_at_beg(3);
	link_list.add_at_beg(4);
	link_list.display();

	link_list.delete_at_beg();
	link_list.delete_at_end();
	link_list.display();

	link_list.delete_at_index(5);
	link_list.display();
	system("pause");
	return 0;
}
