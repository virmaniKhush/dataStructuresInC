#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert_at_end(struct Node* head_node, int val){
    struct Node* temp;
    temp = head_node;
    struct Node* temp_node;
    temp_node = (struct Node*)malloc(1*sizeof(struct Node));
    temp_node->data = val;
    temp_node->next = NULL;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp_node->prev = temp;
    temp->next=temp_node;
}

void print_dll(struct Node* head_node){
    struct Node* tmp;    
    tmp = head_node;
    while(tmp!=NULL){
        printf("%d\t%p\t%p\t%p\n", tmp->data, tmp->prev, tmp, tmp->next);
        tmp = tmp->next;
    }
}

void main(){
    struct Node* head1;
    head1 = (struct Node*)malloc(1* sizeof(struct Node));
    head1->prev=NULL;
    head1->data=1;
    head1->next = NULL;
    int x=2;
    int y=3, a=4, z=5;
    insert_at_end(head1, x);
    insert_at_end(head1, y);
    insert_at_end(head1, z);
    insert_at_end(head1, a);
    print_dll(head1);
}
