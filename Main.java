import java.util.Scanner;

class Node{
    char data;
    Node addr;

    Node(char val){
        data=val;
        addr=null;
    }
}

class Stack{
    Node top;

    Stack(){
        top=null;
    }

    void push(char val){
        Node newNode = new Node(val);

        newNode.addr=top;
        top=newNode;
    }

    char pop(){
        if(top==null)
            return '\0';

        Node temp = top;
        char popped = temp.data;
        top=top.addr;
        return popped;
    }

    boolean match(char open,char close){
        if(open=='(' && close==')')
            return true;
        if(open=='[' && close==']')
            return true;
        if(open=='{' && close=='}')
            return true;
        return false;
    }

    boolean isBalanced(String exp){
        for(int i=0;i<exp.length();i++){
            char ch = exp.charAt(i);
            if(ch=='(' || ch=='[' || ch=='{'){
                push(ch);
            }
            else if(ch==')' || ch==']' || ch=='}'){
                if(top==null)
                    return false;

                char open = pop();
                if(!match(open,ch))
                    return false;
            }
        }
        return top==null;
    }
}


public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String exp = sc.nextLine(); 
        Stack s = new Stack();

        if(s.isBalanced(exp))
            System.out.println("Balanced");
        else
            System.out.println("Not Balanced");
    }
}