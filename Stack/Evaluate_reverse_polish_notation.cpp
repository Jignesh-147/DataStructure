class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        ios_base::sync_with_stdio(0);
        stack<int> stack;
        int n = tokens.size();
        for(int i=0;i<n;i++){
         if(tokens[i] == "+"){
              int a = stack.top();
              stack.pop();
              int b = stack.top();
              stack.pop();
              a = a+b;
              stack.push(a);
              continue;
         }
         else if(tokens[i] == "-"){
              int a = stack.top();
              stack.pop();
              int b = stack.top();
              stack.pop();
              a = b-a;
              stack.push(a);
              continue;
         }
         else if(tokens[i] == "/"){
              int a = stack.top();
              stack.pop();
              int b = stack.top();
              stack.pop();
              a = b/a;
              stack.push(a);
              continue;
         }
        else if(tokens[i] == "*"){
              int a = stack.top();
              stack.pop();
              int b = stack.top();
              stack.pop();
              a = a*b;
              stack.push(a);
              continue;
         }
         else{
            stack.push(stoi(tokens[i]));
            continue;
         }

        } //for here

        return stack.top();
        
    }
};