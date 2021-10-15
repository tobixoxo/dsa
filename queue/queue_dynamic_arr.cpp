//dynamic queue

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
            T* newdata = new T[2*capacity];  //we create a new array, when data is full
            int i = frontindex;
            int j = 0;
            while(i < capacity)             //from FI till end
            {
                newdata[j] = data[i];
                i++;
                j++;
            }
            i= 0;
            while(i < frontindex)           //then from 0 till FI
            {
                newdata[j] = data[i];
            }
            frontindex = 0;
            nextindex = capacity;
            delete [] data;
            data = newdata;
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
    Queueusingarray <char> q(5);
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');
    q.enqueue('d');
    q.enqueue('e');
    q.enqueue('f');

    std::cout << q.front() << std::endl;

    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;
    std::cout << q.deque() << std::endl;

    std::cout << q.getsize() << std::endl;
    std::cout << q.ifempty() << std::endl;
    return 0;

}
