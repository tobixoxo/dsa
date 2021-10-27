#include <iostream>
using namespace std;



//          __ __ __ __ __  


template <typename T>
class Deque
{
    int capacity = 5;
    T data[5];
    int front, rear;
    int size = 0;

    public:

    deque()
    {
        front = -1;
        rear = 0;
        size;
    }

    bool empty()
    {
        return (size == 0) ;
    }

    bool full()
    {

        if (size == capacity ) return true;
        
        else 
        {
            return false;
        }
    }

    void insertFront(T element)     //pushing element at the top
    {
        if (!full()) 
        {
            if (empty())
            {
                front = 0 ;
                rear = 0;
                data[front] = 0;
                size++;
                return;
            }
            if (front = 0)
            {
                front = capacity - 1;
                data[front] = element;
                size++;
                return;
            }
            data[front] = element;
            front --;
            size ++;
            return;
        }
        else cout << "deque is full!\n" ;
        
    }

    void insertRear(T element)
    {
        
        if (!full())
        {
            if (empty())
            {
                //cout << "hi!";
                front = 0 ;
                rear = 0;
                data[rear] = 0;
                size++;
                return;
            }
            if ( rear == capacity -1)
            {
                rear = 0;
                data[rear] = element;
                size++;
                return;
            }
            rear++;
            data[rear] = capacity;
            size++;
            return;
        }

    }

    void deleteRear()
    {
        if (!empty())
        {
            if (size == 1)
            {
                front = -1;
                rear = -1;
                size --;
                return;
            }
            if (rear == 0)
            {
                rear = capacity -1;
                size --;
                return;
            }
            rear --;
            size --;
            return;
        }
        return;
    }

    void deleteFront()
    {
        if (!empty())
        {
            if (size == 1)
            {
                front = -1;
                rear = -1;
                size --;
                return;
            }
            if(front == capacity - 1)
            {
                front = 0;
                size --;
                return;
            }

            front++;
            size--;
            return;
        }
        
    }

    T getFront()
    {
        if(!empty())
        {
            return data[front];
        }
        else return 0;
    }

    T getRear()
    {
        if (!empty())
        {
            return data[rear];
        }
        else return 0;
    }

    int length()
    {
        return size;
    }
};

int main()
{
    class Deque<int> dq;
    //cout << "size is : " << dq.length();
    cout << "Insert element at rear end  : 5 \n";
    dq.insertRear(5);
    
  
    cout << "insert element at rear end : 10 \n";
    dq.insertRear(10);
  
    cout << "get rear element " << " "
         << dq.getRear() << endl;
  
    dq.deleteRear();
    cout << "After delete rear element new rear"
         << " become " << dq.getRear() << endl;
  
    cout << "inserting element at front end \n";
    dq.insertFront(15);
  
    cout << "get front element " << " "
         << dq.getFront() << endl;
  
    dq.deleteFront();
  
    cout << "After delete front element new "
       << "front become " << dq.getFront() << endl;
    return 0;
}