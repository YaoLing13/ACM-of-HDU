/*
 * Prblem: Latin matrix
 * Discribe: n*n matrix, every row and every col have n numbers, and every row and every col don't have same number.
 * Author: Yao Ling
 * Time: 2018-07-27
 */

#include <iostream>

template <class T> class Node
{
public:
    T data;
    Node* next;
    Node()
    {
        next = NULL;    // init
    }
    ~Node(){}
};

int main(int argc, char ** argv)
{
    int n;
    std::cin >> n;

    Node<int> *head;
    head = NULL;
    Node<int> *node;
    node = NULL;
    Node<int> *temp;

    //init circle list
    for (int i = 1; i <= n; ++i) {
        temp = new Node<int>;
        temp->data = i;
        temp->next = head;
        if (i == 1) //first node
        {
            head = temp;
            node = temp;
            continue;
        }
        node->next = temp;
        node = node->next;
    }

    // print circle list
    node = head;
    for (int j = 1; j <= n; ++j) {
        for (int i = 1; i <= n; ++i) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
        node = node->next;
    }

    return 1;
}