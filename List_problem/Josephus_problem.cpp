/*
* Josephus problem
* delete mTh element in list one by one, than start with (m+1)Th, circle until no element in list
* circle list
* By C++
*/

//#include <iostream>
//
////Node of list
//template <class T> class Node
//{
//public:
//	T data;
//	Node* next;
//	Node()
//	{
//		next = NULL;
//	}
//	~Node()
//	{
//
//	}
//
//private:
//
//};
//
//int main(int argc, char ** argv)
//{
//	int n; // n people
//	int s; // sTh people start
//	int m;// gap number
//
//	std::cin >> n >> s >> m;
//
//	//circleList
//	Node<int> *head, *last, *current, *pre;
//	head = NULL;
//	last = NULL;
//	pre = NULL;
//
//	//give value to circle list
//	for (int i = 1; i <= n; i++)
//	{
//		current = new Node<int>;
//		current->data = i;
//		current->next = head;	// circle list
//
//		if (i == 1)	//first elem
//		{
//			head = current;
//			last = current;
//		}
//		else // others elem
//		{
//			last->next = current;
//			last = last->next;
//		}
//	}
//
//	current = head;
//	do
//	{
//		std::cout << current->data << " ";
//		current = current->next;
//	} while (current != head);
//
//	std::cout << std::endl;
//
//	current = head;
//	for (int i = 1; i < s; i++) // current at sTh position
//	{
//		current = current->next;
//	}
//
//	// delete m by order, until no value in list
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 1; j < m; j++)
//		{
//			pre = current;
//			current = current->next;
//		}
//		std::cout << current->data << " ";
//		pre->next = current->next;
//		delete current;
//		current = pre->next;
//	}
//	std::cout << std::endl;
//
//	return 0;
//}


// Discribe: Josephus problem
// Author: Yaoling
// Time: 2018-07-26
#include <iostream>
template <class T> class Node
{
public:
	T data;
	Node* next;
	Node()
	{
		next = NULL;
	}
	~Node()
	{

	}
};
int main(int argc, char** argv)
{
	int n;	// sum of number
	int s;	// start number
	int m;	// gap number

	Node<int> *head;
	Node<int> *last;
	Node<int> *node;
	head = NULL;
	last = NULL;

	std::cin >> n >> s >> m;

	// init circle list
	for (int i = 1; i <= n; ++i) {
		node = new Node<int>;
		node->data = i;
		node->next = head;	//circle list
		if (i == 1)	//first node
		{
			head = node;
			last = node;
		}
		else
		{
			last->next = node;
			last = last->next;
		}
	}

	//print original list
	node = head;
	for (int l = 1; l <= n; ++l) {
		std::cout << node->data << " ";
		node = node->next;
	}
	std::cout << std::endl;

	//from sTh node start
	node = head;	//from head count
	for (int j = 1; j < s; ++j) {
		node = node->next;
	}

	// delete node , one by one
	Node<int> *temp;
	temp = NULL;
	for (int k = 1; k <=n ; ++k) {	// delete n nodes
		for (int i = 1; i < m; ++i) {	//delete one node by one time
			temp = node;
			node = node->next;
		}
		std::cout << node->data << " ";
		temp->next = node->next;
		delete node;
		node = temp->next;
	}
	std::cout << std::endl;

	return 0;
}