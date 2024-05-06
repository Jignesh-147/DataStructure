class Solution {
public:
    int calPoints(vector<string>& operations) {
       
        stack<int> stack;
        int ans = 0;
        for(int i=0;i<operations.size();i++){
            string s = operations[i];
            if(s == "+"){
                int prev = stack.top();
                int sum = stack.top();
                stack.pop();
                sum += stack.top();
                stack.push(prev);
                stack.push(sum);
                ans+=sum;
            }
            else if(s == "D"){
                stack.push(2*stack.top());
                ans+=stack.top();
            }
            else if(s == "C"){
                ans-=stack.top();
                stack.pop();
            }
            else{
                int k = stoi(s);
                stack.push(k);
                ans+=k;
            }
        }
        return ans;
    }
};