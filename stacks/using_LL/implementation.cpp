#include <iostream>
template <typename T>       //defining variable data type
class Node
{
    public:
    T data;
    Node <T> *next;
    Node(T element)
    {
        data = element;
    }

};

template <typename T>
class StackusingLL
{
    Node <T> *head;             //this will represent top of the stack
    int size;                   //contain the size of the stack
    public:
    StackusingLL()
    {
        size = 0;
        head = NULL;
    }

    void push(T element)
    {
        Node <T> *newnode = new  Node<T> (element);     //element is pushed to the idx 0 of the LL so we create a newnode
        if (head == NULL)             
        {
            head = newnode;
            size++;
        }
        else{
            newnode->next = head;
            head = newnode;
            size++;
        }
        
    }

    T pop()                                             //we shift head forward by one
    {
        T ans;
        ans = head -> data;
        head = head->next;
        size--;
        return ans;

    }

    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        return size == 0;  
    }

    T top()
    {
        return head->data;
    }
};

int main()
{
    StackusingLL <char> stack;
    std::cout << stack.getsize() << std::endl;
    
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.push('e');
    stack.push('f');
    stack.push('g');
    
    std::cout << stack.top() << std::endl;

    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;
    std::cout << stack.pop() << std::endl;


    std::cout << stack.getsize() << std::endl;

    std::cout << stack.isempty() << std::endl;
}
