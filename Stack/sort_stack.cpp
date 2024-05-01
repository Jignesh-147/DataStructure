
void sorter(stack<int>& my_stack, int element){
    if(my_stack.empty() || (!my_stack.empty() && my_stack.top() < element)){
        my_stack.push(element);
        return ;
    }
    int n = my_stack.top();
    my_stack.pop();

    sorter(my_stack,element);

    //now inseting the n after inserting elemnt in its correct position
    my_stack.push(n);
}

void sort_stack(stack<int>& my_stack){
    if(my_stack.empty()){
        return ;
    }
    int element = my_stack.top();
    my_stack.pop();

    //recursion
    sort_stack(my_stack);

    //now sorting after poping every element
    sorter(my_stack, element);
}
