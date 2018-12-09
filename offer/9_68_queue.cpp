#include <iostream>
#include <stack>
#include <queue>
#include <exception>
#include <stdexcept>

template <class T> class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);

    void appendTail(const T& node)
    {
        stack1.push(node);
    }

    T deleteHead()
    {
        if(stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty())
        {
            std::logic_error ex("Queue is empty!");
            throw std::exception(ex);
        }

        T head;
        head = stack2.top();
        stack2.pop();
        return head;
    }

private:
    std::stack<T> stack1;
    std::stack<T> stack2;
};


template <class T> class CStack
{
public:
    CStack(void);
    ~CStack(void);

    void appendHead(const T& node)
    {
        queue1.push(node);
    }
    T deleteTail()
    {
        if(queue2.empty())
        {
            while (!queue1.empty())
            {
                queue2.push(queue1.front());
                queue1.pop();
            }
        }
        if(queue2.empty())
        {
            std::logic_error ex("Stack is empty!");
            throw std::exception(ex);
        }

        T tail = queue2.front();
        queue2.pop();
        return tail;
    }


private:
    std::queue<T> queue1;
    std::queue<T> queue2;
};


int main(void)
{
    return 0;
}