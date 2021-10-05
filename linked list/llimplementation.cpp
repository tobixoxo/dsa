#include <iostream>

class Node
{
    public:
    int data ;
    Node* next = NULL;
    Node(int data)          //constructor has no return type
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

Node* insertnode(Node* head, int index, int data)
{
    Node* newnode = new Node(data);         //newnode which is to be inserted
    if (index == 0)                         //insert at head
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    else 
    {
        Node* temp = head;
        int count = 0;
        while(count < index - 1 && temp -> next != 0)   //traversing to the one index before 'idx' 
        {
            temp = temp -> next;
            count++;
        }
        if (temp != NULL)                               //if the idx is not greater than size
        {                                               //insertion is done
            Node* a = temp->next;
            temp-> next = newnode;
            newnode->next = a;

        }
        else
        {
            std::cout << "index entered is not available in linked list\n";
        }
    }
    return NULL; // this is the line which causes the warning
}

Node* deletenode(Node* head, int index)
{
    if (index == 0)
    {
        head = head->next;
        return head;
    }
    Node* temp = head ;
    int i = 0;
    while ( i < index -1)
    {
        temp = temp -> next;
        i++;
    }
    //we need the ptr of idx+1 element
    Node* b = temp->next->next;
    temp->next= b;
    std::cout << "-----------------";
    return head;
}

int main()
{
    std::cout << "enter the elements, and terminate -1 \n";
    Node* head = takeinput();
    print(head);
    int data, index;
    std::cout << "enter the data and index to be inserted: ";
    std::cin >> data >> index;
    insertnode(head, index, data);
    print(head);
    std::cout << "enter index u want to delete: ";
    std::cin >> index;
    head = deletenode(head, index);
    std::cout << "-----------------";
    print(head);
    return 0;
}
