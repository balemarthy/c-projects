#include<stdio.h>
#include<stdlib.h>

struct node
{   
    int data;
    struct node *next;
};

struct node *head = NULL;

void addLast(int val)
{
    struct node *nnode = (struct node *)malloc(sizeof(struct node));
    nnode->data = val;
    nnode->next = NULL;
    
    if(NULL == head) {
        head = nnode;
    } else {
        struct node *temp = head;
        
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nnode;
    }
	
}


void printList()
{
    struct node *temp = head;

    while(temp != NULL)
    {
         printf("%d ", temp->data);
         temp = temp->next;
    }
}

int main()
{
     addLast(10);
     addLast(20);
     addLast(30);

     printList();

     return 0;
}
