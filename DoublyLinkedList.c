#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL, *tail = NULL;

struct Node *createNode(int val)
{

    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->data = val;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void insertBegin(int val)
{
    struct Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}
void insertEnd(int val)
{
    struct Node *newNode = createNode(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

int countNodes()
{
    struct Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void display()
{
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("%d \n",temp->data);
}

void insertPos(int val, int pos)
{
    if(pos=0){
        insertBegin(val);
        return;
        
    }
    if(pos==countNodes()+1){
        insertEnd(val);
        return;
        
    }
    pos = pos % (countNodes());
    struct Node *temp = head;
    while ((pos - 2) > 0)
    {
        temp = temp->next;
        pos--;
    }
    struct Node *newNode = createNode(val);
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteBegin(){
    if(countNodes()==0) return;
    struct Node *temp = head;
    head=head->next;
    head->prev=NULL;
    free(temp);
}
void deleteEnd(){
    if(countNodes()==0) return;
    struct Node *temp = tail;
    tail=tail->prev;
    tail->next = NULL;
    free(temp);
}
void deletePos(int pos){
    if(countNodes()==0) return;
    pos=pos%countNodes();
     if(pos==1){
        deleteBegin();
        return;
        
    }
    if(pos==countNodes()){
        deleteEnd();
        return;
        
    }
    
     struct Node *temp = head;
    while ((pos-1) > 0)
    {
        temp = temp->next;
        pos--;
    }
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp);
}

int main()
{
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertBegin(0);
    display();
    deleteBegin();
    deleteEnd();
    display();
    insertPos(5,2);
    display();
    deletePos(4);
    display();
}