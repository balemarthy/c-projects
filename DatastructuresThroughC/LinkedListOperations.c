#include <stdio.h>
#include <stdlib.h>

/* structure containing a data part and link part */
struct node {
    struct node *link;
    int data;
};

void append(struct node **, int);
void addatbeg(struct node **, int);
void addafter(struct node *, int, int);
void display(struct node *);

void main(void) {
    struct node *p;
    
    p = NULL; /* empty linked list */
    
    append(&p, 14);
    append(&p, 30);
    append(&p, 25);
    
    addatbeg(&p, 10);
    
    display(p);   
    
    addafter(p, 7, 0);  
    
}

/* adds a node at the end of a linked list */
void append(struct node **q, int num) {
    struct node *temp, *r;
    
    if(*q == NULL) {
        temp = malloc(sizeof(struct node));
        temp->data = num;
        temp->link = NULL;
        *q = temp;
    } else {
        temp = *q;
        
        /* go to the last node */
        while(temp->link != NULL) {
            temp = temp->link;
        }
        
        /* add node at the end */
        r = malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}

/* adds a new node at the beginning of the linked list */
void addatbeg(struct node **q, int num) {
    struct node *temp;
    
    /* add new node */
    temp = malloc(sizeof(struct node));
    
    temp->data = num;
    temp->link = *q;
    *q = temp;
}

/* adds a new node after the specified number of nodes */
void addafter(struct node *q, int loc, int num) {
    struct node *temp, *r;
    int i;
    
    temp = q;
    /* skip to the desired position */
    for(i=0; i<loc; i++) {
        temp = temp->link;
        
        /* if end of linked list is encountered */
        if(NULL == temp) {
            printf("There are less than %d elements in the list", loc);
            return;
        }        
    }
    /* insert new node */
    r = malloc(sizeof(struct node));
    r->data = num;
    r->link = temp->link;
    temp->link = r;    
}

/* displays the contents of the linked list */
void display(struct node *q) {
    printf("\n");
    
    /* traverse the entire linked list */
    while(q != NULL) {
        printf("%d",q->data);
        q = q->link;
    }
}
