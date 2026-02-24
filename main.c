#include<stdio.h>
#include<stdlib.h>


struct Node{
    char data;
    struct Node *addr;
};

struct Node *top = NULL;

void push(char val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    if(newNode==NULL){
        printf("Memory Allocation Failed");
        return;
    }
    newNode->data=val;
    newNode->addr=top;
    top=newNode;
}

char pop(){
    if(top==NULL)
        return '\0';

    struct Node *temp = top;
    char popped = temp->data;
    top = top->addr;
    free(temp);
    return popped;
}


int match(char open,char close){
    if(open=='(' && close==')')
        return 1;
    if(open=='[' && close==']')
        return 1;
    if(open=='{' && close=='}')
        return 1;
    return 0;
}

int isbalanced(char exp[]){
    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(top==NULL)
                return 0;
            char open = pop();

            if(!match(open,exp[i]))
                return 0;
        }
    }
    return top==NULL;
}

int main(){

    char exp[100];
    scanf("%s",exp);

    if(isbalanced(exp))
        printf("Balanced");
    else
        printf("Not Balanced");
    return 0;
}