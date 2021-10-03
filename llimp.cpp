#include <iostream>

class Node
{
    public:
    int data ;
    Node* next = NULL;
    Node(int data) //constructor has no return type
    {
        this->data = data;
    }
};

void print(Node* head)
{
    while (head != NULL)                    
    {
        std::cout << head->data << " ";
        head = head -> next;
    }
    std::cout << "\n";
    return ;
}

Node* takeinput()
{
    int data;
    std::cin >> data; //take input for data
    Node* head = NULL;
    Node* tail = NULL; //tail keeps the track of last node
    while( data != -1) //if the data is -1, we terminate
    {
        Node* newnode = new Node(data); //Node is created by dma 
        if (head == NULL) 
        {
            head = newnode; //head is now the ptr for the first node
            tail = newnode;
        }
        else            
        {
            tail -> next = newnode; // we update the next of the node
            tail = newnode; //shift the last node
        }
        std::cin >> data; //take the input for data to be added to next node
    }
    return head;
}

int main()
{
    Node* head = takeinput();
    print(head);
    return 0;
}
