class Solution {
public:
       int minSubArrayLen(int s, vector<int>& A) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        int i = 0, n = A.size(), res = n + 1;
        for (int j = 0; j < n; ++j) {
            s -= A[j];
            while (s <= 0) {
                res = min(res, j - i + 1);
                s += A[i++];
            }
        }
        return res % (n + 1);
    }
};