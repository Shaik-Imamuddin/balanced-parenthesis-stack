class Node:
    def __init__(self,val):
        self.data=val
        self.addr=None

class Stack:
    def __init__(self):
        self.top=None
    
    def push(self,val):
        newNode = Node(val)

        newNode.addr = self.top
        self.top = newNode
    
    def pop(self):
        if self.top is None:
            return
        
        temp = self.top
        popped = temp.data
        self.top=self.top.addr
        return popped
    
    def match(self,open,close):
        if open=='(' and close==')':
            return True
        if open=='{' and close=='}':
            return True
        if open=='[' and close==']':
            return True
        return False
    
    def isBalanced(self,exp):
        for i in range(len(exp)):
            if exp[i]=='(' or exp[i]=='{' or exp[i]=='[':
                self.push(exp[i])
            elif(exp[i]==')' or exp[i]==']' or exp[i]=='}'):
                if self.top is None:
                    return False
                
                open = self.pop()

                if(not self.match(open,exp[i])):
                   return False
        
        return self.top is None
    

s=Stack()
exp=input()

if(s.isBalanced(exp)):
    print("Balanced")
else:
    print("Not Balanced")