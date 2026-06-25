// @leetcode id=2019 questionId=2147 slug=the-score-of-students-solving-math-expression lang=cpp site=leetcode.com title="The Score of Students Solving Math Expression"
class Solution {
public:
    int scoreOfStudents(string s, vector<int>& answers) {
        // Extract numbers and operators
        vector<int> nums;
        vector<char> ops;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) nums.push_back(s[i] - '0');
            else ops.push_back(s[i]);
        }
        
        int n = nums.size(); // n numbers, n-1 operators
        
        // Compute correct answer using proper precedence (mult first, then add)
        // Use a stack approach
        vector<int> stk;
        stk.push_back(nums[0]);
        for (int i = 0; i < (int)ops.size(); i++) {
            if (ops[i] == '*') {
                stk.back() *= nums[i + 1];
            } else {
                stk.push_back(nums[i + 1]);
            }
        }
        int correct = 0;
        for (int x : stk) correct += x;
        
        // Interval DP: dp[i][j] = set of all possible values computing nums[i..j] with ops[i..j-1]
        // Values capped at 1001 since answers are in [0, 1000]
        const int MAXVAL = 1001;
        vector<vector<unordered_set<int>>> dp(n, vector<unordered_set<int>>(n));
        for (int i = 0; i < n; i++) dp[i][i].insert(nums[i]);
        
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                // Try splitting at each operator position k (between nums[k] and nums[k+1])
                for (int k = i; k < j; k++) {
                    for (int a : dp[i][k]) {
                        for (int b : dp[k+1][j]) {
                            int val;
                            if (ops[k] == '+') val = a + b;
                            else val = a * b;
                            if (val <= MAXVAL) dp[i][j].insert(val);
                        }
                    }
                }
            }
        }
        
        // Grade students
        int total = 0;
        for (int ans : answers) {
            if (ans == correct) {
                total += 5;
            } else if (dp[0][n-1].count(ans)) {
                total += 2;
            }
        }
        
        return total;
    }
};
