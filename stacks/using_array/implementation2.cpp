#include <iostream>
#include <climits>
class stackusingarray
{
    int* data;          //dynamically created array ptr
    int nextindex;
    int capacity;

    public:
    stackusingarray()
    {
        data = new int[5];
        nextindex = 0;
        capacity = 5;
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
            int* newarr;    
            newarr = new int[2*capacity];
            int i = 0;
            while(i < size())
            {
                newarr[i] = data[i];
                i++;
            }
            delete [] data;
            data = newarr;
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
    stackusingarray stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.push(70);
    
    std::cout << stack.top() << std::endl;

    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;


    std::cout << stack.size() << std::endl;

    std::cout << stack.empty() << std::endl;
    
}
