#include <bits/stdc++.h>
using namespace std;
class Node
{
	public:
	int data;
	Node *next;
};


void deleteNode(Node** head_ref, int key)
{
     
    Node* temp = *head_ref;
    Node* prev = NULL;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; 
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
 
    if (temp == NULL)
        return;

    prev->next = temp->next;

    delete temp;
    }
}

void append(Node** head_ref, int new_data)
{

	Node* new_node = new Node();
	Node *last = *head_ref;

	new_node->data = new_data;
	new_node->next = NULL;

	
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	
	while (last->next != NULL)
	{
		last = last->next;
	}

	
	last->next = new_node;
	return;
}





void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
}

/* Driver code*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;
	
	append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
	append(&head, 5);
    append(&head, 6);
	deleteNode(&head, 1);
	
	cout<<"Created Linked list is: ";
	printList(head);
	
	return 0;
}


