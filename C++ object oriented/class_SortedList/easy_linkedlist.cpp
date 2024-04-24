
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next; 
};

void print_that(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head = head->next;
    }
}

int main()
{
    Node* head = new Node();
    head->data = 0;
    head->next = nullptr;
    Node* current = head;

    for(int i=1; i<10; i++)
    {
        Node *tmp = new Node;
        tmp->data = i;
        tmp->next = nullptr;
        current->next = tmp;
        current = tmp;
    }

    print_that(head);
}
