class Solution {
public:
    vector<int> next_greater_element(vector<int>& temp){
        stack<int> stack;
        int n = temp.size();
        stack.push(n-1);
        vector<int> ans;
        ans.resize(n);
        ans[n-1] = 0;
        //code here
        for(int i=n-2;i>=0;i--){
          if(!stack.empty() && temp[stack.top()]>temp[i]){
             ans[i] = stack.top() - i;
             stack.push(i);
          }
          else{
                while(!stack.empty() && temp[stack.top()]<=temp[i]){
                    stack.pop();
                }
                if(!stack.empty()){
                    ans[i] = stack.top() - i;
                }
                else{
                    ans[i] = 0;
                }
                stack.push(i);
          }

        } //for here

        return ans;

    } //func ending
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        return next_greater_element(temperatures);
    }
};