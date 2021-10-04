#include <iostream>
class Node
{
    public:
    int data;
    Node* next = NULL;
    Node(int data)
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

Node* insertrec(Node* head, int data, int index)
{
    if (head == NULL && index == 0)         //insertion at the end
    {
        Node* newnode = new Node(data);

        return newnode;
    }
    else if (index == 0)                    //insertion at front
    {
        Node* newnode = new Node(data);
        newnode -> next = head;
        return newnode;
    }
    else                                    //base case
    {
        Node* x = insertrec(head -> next, data, index - 1);
        head->next = x;
    }
    return head;
}

Node* takeinput()
{
    int data;
    std::cin >> data;                       //take input for data
    Node* head = NULL;
    Node* tail = NULL;
    while( data != -1)                      //if the data is -1, we terminate
    {
        Node* newnode = new Node(data);     //Node is created by dma 
        if (head == NULL)                   
        {
            head = newnode;                 //head is now the ptr for the first node
            tail = newnode;
        }
        else            
        {
            tail -> next = newnode;         // we update the next of the node
            tail = newnode;
        }
        std::cin >> data ;                  //take the input for data to be added to next node
    }
    return head;
}

int main()
{
    Node* head;
    int data, index;
    std::cout << "enter the elements, and terminate -1 \n";
    head = takeinput();
    print(head);
    std::cout << "enter the data and index to be inserted: ";
    std::cin >> data >> index;
    head = insertrec(head, data, index);
    print(head);
    return 0;   
}
