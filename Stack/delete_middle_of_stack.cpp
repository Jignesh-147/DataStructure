void deleter(stack<int>& input_stack, int n, int count){
    if(count == n/2){
    input_stack.pop();
      return ;
    }
    int element = input_stack.top();
    input_stack.pop();

    deleter(input_stack, n , --count);
    input_stack.push(element);
    
}

void delete_middle(stack<int>& input_stack, int n){
    int count = n;
    deleter(input_stack, n+1, count);
    

}