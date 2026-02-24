#include<iostream>
using namespace std;

class Node{
public:
    char data;
    Node *addr;

    Node(char val){
        data=val;
        addr=nullptr;
    }
};

class Stack{
private:
    Node *top;
public:
    Stack(){
        top=nullptr;
    }

    void push(char val){
        Node *newNode = new Node(val);

        newNode->addr = top;
        top = newNode;
    }

    char pop(){
        if(top==nullptr){
            return '\0';
        }

        Node *temp = top;
        char popped = temp->data;
        top=top->addr;
        delete temp;
        return popped;
    }

    bool match(char open,char close){
        if(open=='(' && close==')')
            return true;
        if(open=='[' && close==']')
            return true;
        if(open=='{' && close=='}')
            return true;
        return false;
    } 

    bool isBalanced(string exp){
        for(int i=0;i<exp.length();i++){
            
            if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
                push(exp[i]);
        
            else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
                if(top==nullptr)
                    return false;
                
                char open = pop();

                if(!match(open,exp[i]))
                    return false;
            }
        }
        return top==nullptr;
    }
};



int main(){
  
    Stack s;

    string exp;
    cin>>exp;

    if(s.isBalanced(exp))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";

    return 0;
}