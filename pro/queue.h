#include <iostream>
#include <string>

using namespace std;
namespace queue{

template <class T> class Node
{
public:
    T data;
    Node* next;
    Node()
    {
        next = NULL;
    }
};

template <class T> class queue
{
public:
    int len;
    Node<T>* node;
    Node<T>* head;
    Node<T>* last;

    queue()
    {
        node = NULL;
        head = NULL;
        last = NULL;
        len = 0;
    }
    ~queue()
    {
        Node<T>* temp = head;
        while(head)
        {
            temp = head;
            head = head->next;
            delete(temp);
        }
    }

    //压入节点
    void push(T t)
    {
        node = new Node<T>;
        node->data = t;
        node->next = NULL;

        if (len == 0) //加入第一个节点
        {
            head = node;
            last = node;
        } else
        {
            last->next = node;
            last = node;
        }

        ++ len;
    }


    T pop()
    {
        if (len == 0)
        {
            cout << "No data in Queue, Can't pop data! " << endl;
            exit(0);
        }
        len --;
        Node<T>* temp;
        T temp_data;
        temp = head;
        head = temp->next;
        temp_data = temp->data;

        delete(temp);
        return temp_data;
    }

    int size()
    {
        return len;
    }


};
}
