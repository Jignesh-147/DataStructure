 class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& a) {
        ios_base::sync_with_stdio(false);
        int n = a.size();
        vector<int>v(n,-1);

        stack<int>st;
        //in first cycle we get max element of the vector at the bottom of stack
        //in second cycle main operation begins
        for(int i = 2*n - 1; i >= 0; i--)
        {
            // we pop out all elements smaller than current element
            while(!st.empty() && (a[i%n] >= st.top()))
            {
                st.pop();
            }

            // if stack is empty means no greater element is there
            // if not empty we make answer at that index equal to top element
            if(!st.empty() && (i < n))
            {
                v[i] = st.top();
            }

            st.push(a[i%n]);
        }

        return v;
    }
};