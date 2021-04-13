#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char name[100];
} element;

typedef struct ListNode{  // 노드 타입 
    element data;
    struct Listnode *link;
} ListNode;

void error(char *message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value)
{
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head)
{
    for (ListNode *p = head; p != NULL; p = p->link)
    {
        printf("%s->", p->data.name);
    }
    printf("NULL \n");
}

int main(void)
{
    ListNode *head = NULL;
    element data;
    
    strcpy(data.name, "Apple");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "Kiwi");
    head = insert_first(head, data);
    print_list(head);

    strcpy(data.name, "Banana");
    head = insert_first(head, data);
    print_list(head);
}