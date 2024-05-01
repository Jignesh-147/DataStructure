

void insert_bottom(stack<int>& myStack,int x){

    if(myStack.empty()){
        myStack.push(x);
        return ;
    }
    int element = myStack.top();
    myStack.pop();
    insert_bottom(myStack,x);
    myStack.push(element);
}

stack<int> pushAtBottom(stack<int>& myStack, int x){

       insert_bottom(myStack,x);
       return myStack;
}


