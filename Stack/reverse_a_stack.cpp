
void insert_at_bottom(stack<int>& my_stack,int x){
    if(my_stack.empty()){
        my_stack.push(x);
        return ;
    }
    int num = my_stack.top();
    my_stack.pop();

    insert_at_bottom(my_stack,x);

    my_stack.push(num);
}

void reverse_stack(stack<int>& my_stack){
    if(my_stack.empty()){
        return ;
    }
    //storing top element and then removing it
    int element = my_stack.top();
    my_stack.pop();

    //recalling reverse_stack
    reverse_stack(my_stack);

    //insert the element at bottom
     insert_at_bottom(my_stack,element);

}