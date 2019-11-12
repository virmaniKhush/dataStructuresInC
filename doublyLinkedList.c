#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

void insert_at_end(struct Node* head_node, int val){
    if(head_node->data==0){
        head_node->data = val;
    }
    else{
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
}
void delete__node(struct Node* head_node, int position, int data_val){

}

void sort_dll(struct Node* head_node){

}

void print_dll(struct Node* head_node){
    struct Node* tmp;    
    tmp = head_node;
    while(tmp!=NULL){
        printf("%d\t%p\t%p\t%p\n", tmp->data, tmp->prev, tmp,  tmp->next);
        tmp = tmp->next;
    }
}

void main(){
    struct Node* head1;
    head1 = (struct Node*)malloc(1* sizeof(struct Node));
    head1->prev=NULL;
    head1->data= 0;       // for initializing !
    head1->next = NULL;
    int ix, n, num_nodes;
    printf("Enter number of nodes to be added : ");
    scanf("%d", &num_nodes);
    for(ix=0; ix<num_nodes; ix++){
        printf("\nEnter value : ");
        scanf("%d", &n);
        insert_at_end(head1, n);
    }
    print_dll(head1);
}
