//find the next smaller element for all the elements of a vector

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> stack;
    stack.push(-1);
    for(int i=n-1;i>=0;i--){
        int x = arr[i];
        if(x>stack.top()){
            arr[i] = stack.top();
            stack.push(x);
        }
        else{
            while(stack.top()>=x){
                stack.pop();
            }
            arr[i] = stack.top();
            stack.push(x);
        }
    }
    return arr;


}