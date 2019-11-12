#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
int stack1[MAX_SIZE];
int minStack[MAX_SIZE];
int top1=-1;  // initial value
int top2=-1;
void push(int* stack, int* top, int x){
    stack[(*top) +1]=x;
    *top+=1;

    if(top2==-1){
        minStack[top2 +1]=x;
        top2+=1;
    } 
    else{
        if(minStack[top2]>x){
            minStack[top2 +1]=x;
            top2+=1;
        }
        else{
            minStack[top2 +1]=minStack[top2];
            top2+=1;
        }
    }
}
int pop(int* stack, int* top){
    int pop_elem;
    pop_elem = stack[*top];
    *top-=1;
    top2-=1;
    return pop_elem;    
}
int minStackVal(){
    pop(minStack, &top2);
}

void stackPrinter(int* stack, int* top){
    int idx;
    for(idx=*top;idx>=0;idx--){
        printf("%d\n",stack[idx]);
    }
}
void main(){
    int num;
    int popped;
    printf("Enter 5 numbers:\n");
    for(int kx=0;kx<5;kx++){
    scanf("%d", &num);
    push(stack1, &top1, num);
    }
    printf("\nPrinting stack1.\n");
    stackPrinter(stack1, &top1);
    printf("\nPrinting stack1 after popping a value.\n");
    popped = pop(stack1, &top1);
    stackPrinter(stack1, &top1);
    printf("\nPrinting minStack.\n");
    stackPrinter(minStack, &top2);
    int min_val;
    min_val = minStackVal();
    printf("\n%d\n", min_val);
}
