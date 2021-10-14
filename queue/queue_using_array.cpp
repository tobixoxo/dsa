#include <iostream>
template <typename T>
class Queueusingarray
{
    T *data;
    int frontindex;         //where the front fo the queue is located
    int nextindex;          //where the el is to be inserted
    int capacity ;          //the real capacity of the data array
    int size;
    public:
    Queueusingarray(int x)
    {
        data = new T[x] ;
        frontindex = -1;        //there is no front when declared
        nextindex = 0;          //first el will be inserted to idx 0 ofc
        size = 0;
        capacity = x;
        
    }

    void enqueue(T element)
    {
        if(size== capacity)         //if the queue is full
        {
            std::cout << "queue is full!\n";
            return;
        }
        else if (size == 0)         //when the el is inserted for the first time
        {
            frontindex = 0;
        }

        data[nextindex] = element;
        nextindex = (nextindex+1) % capacity;
        size++;
        return;
    }

    T front()
    {
        if (size == 0 )
        {
            std::cout << "queue empty!\n";
        }
        return data[frontindex];
    }

    T deque()
    {
        if (size == 0 )
        {
            std::cout << "queue empty!\n";
            frontindex = -1;
            return 0;
        }
        T ans = data[frontindex];
        frontindex = (frontindex + 1) % capacity;
        size--;
        return ans;
    }

    int getsize()
    {
        return size;
    }
    bool ifempty()
    {
        return size == 0;
    }
};

int main()
{
    Queueusingarray <int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    std::cout << q.front() << std::endl;

    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;

    std::cout << q.getsize() << std::endl;
    std::cout << q.ifempty() << std::endl;
    return 0;

}
