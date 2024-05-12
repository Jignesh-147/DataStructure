

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
       stack<int> stack;
       //pushing all the elements in the stack;
       for(int i=0;i<n;i++){
           stack.push(i);
       }
       
       while(!stack.empty()){
           int a = stack.top();
           stack.pop();
           if(stack.empty()){
               stack.push(a);
               break;
           }
           int b = stack.top();
           stack.pop();
           if(M[a][b] == 1){
               stack.push(b);
           }
           else if(M[b][a] == 1){
               stack.push(a);
           }
         
           
       } //while here
       int cel = stack.top();
       bool flag = true;
       for(int i =0;i<n;i++){
           if(cel == i){
               continue;
           }
           if(M[i][cel] == 0){
               flag = false;
               break;
           }
           if(M[cel][i] == 1){
               flag = false;
               break;
           }
           
       }  //for here
       if(flag == true){
           return cel;
       }
       return -1;
    }
};
