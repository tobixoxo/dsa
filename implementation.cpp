#include <iostream>
#include <climits>
class stackusingarray
{
    int* data;          //dynamically created array ptr
    int nextindex;
    int capacity;

    public:
    stackusingarray(int size)
    {
        data = new int[10];
        nextindex = 0;
        capacity = size;
    }
    int size()
    {
        return nextindex;
    }

    int top()
    {
        return data[nextindex-1];
    }

    void push(int element)
    {
        if (capacity == nextindex) 
        {
            std::cout << "stack is full\n";
            return;
        }
        data[nextindex] = element;
        nextindex ++;
    }

    int pop()
    {
        if (empty()) 
        {
            std::cout << "stack is empty\n";
            return INT_MIN; 
        }
        nextindex --;
        return data[nextindex];
    }

    bool empty()
    {
        return nextindex == 0;
        /*
                OR
        if (nextindex == 0) return true;
        else return false;
        */
    }
    int deleteelement()
    {
        if (empty()) 
        {
            std::cout << "stack is empty\n";
            return INT_MIN; 
        }
        nextindex --;
    }
    
};

int main()
{
    stackusingarray stack(5);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    
    std::cout << stack.top() << std::endl;

    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;


    std::cout << stack.size() << std::endl;

    std::cout << stack.empty() << std::endl;
    
}