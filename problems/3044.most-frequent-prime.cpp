// @leetcode id=3044 questionId=3314 slug=most-frequent-prime lang=cpp site=leetcode.com title="Most Frequent Prime"
class Solution {
public:
    bool isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 3; (long long)i * i <= n; i += 2)
            if (n % i == 0) return false;
        return true;
    }
    
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int dirs[8][2] = {{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0},{-1,1}};
        unordered_map<int,int> freq;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (auto& d : dirs) {
                    int r = i + d[0], c = j + d[1];
                    int num = mat[i][j];
                    while (r >= 0 && r < m && c >= 0 && c < n) {
                        num = num * 10 + mat[r][c];
                        if (num > 10 && isPrime(num)) {
                            freq[num]++;
                        }
                        r += d[0];
                        c += d[1];
                    }
                }
            }
        }
        
        int ans = -1, maxFreq = 0;
        for (auto& [num, cnt] : freq) {
            if (cnt > maxFreq || (cnt == maxFreq && num > ans)) {
                maxFreq = cnt;
                ans = num;
            }
        }
        return ans;
    }
};
