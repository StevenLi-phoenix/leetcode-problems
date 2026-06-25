// @leetcode id=3485 questionId=3784 slug=longest-common-prefix-of-k-strings-after-removal lang=cpp site=leetcode.com title="Longest Common Prefix of K Strings After Removal"
class Solution {
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k) {
        int n = words.size();
        vector<int> ans(n, 0);
        
        if (n - 1 < k) return ans;
        
        // Build trie
        vector<array<int,26>> ch;
        vector<int> cnt;
        ch.push_back({});
        ch[0].fill(-1);
        cnt.push_back(0);
        
        auto newNode = [&]() -> int {
            ch.push_back({});
            ch.back().fill(-1);
            cnt.push_back(0);
            return (int)ch.size() - 1;
        };
        
        auto insert = [&](const string& w) -> vector<int> {
            vector<int> path;
            int cur = 0;
            for (char c : w) {
                int idx = c - 'a';
                if (ch[cur][idx] == -1) ch[cur][idx] = newNode();
                cur = ch[cur][idx];
                cnt[cur]++;
                path.push_back(cur);
            }
            return path;
        };
        
        vector<vector<int>> paths(n);
        for (int i = 0; i < n; i++) paths[i] = insert(words[i]);
        
        int numNodes = ch.size();
        vector<int> depth_of(numNodes, -1);
        depth_of[0] = 0;
        
        int maxDepth = 0;
        vector<int> valid_cnt;
        vector<int> sole_node;
        valid_cnt.push_back(0);
        sole_node.push_back(-1);
        
        // BFS
        vector<int> bfsq;
        bfsq.push_back(0);
        for (int qi = 0; qi < (int)bfsq.size(); qi++) {
            int v = bfsq[qi];
            int d = depth_of[v];
            if (d > 0 && cnt[v] >= k) {
                if (d >= (int)valid_cnt.size()) {
                    valid_cnt.resize(d + 1, 0);
                    sole_node.resize(d + 1, -1);
                }
                valid_cnt[d]++;
                if (valid_cnt[d] == 1) sole_node[d] = v;
                else sole_node[d] = -2;
                maxDepth = max(maxDepth, d);
            }
            for (int c = 0; c < 26; c++) {
                if (ch[v][c] != -1) {
                    depth_of[ch[v][c]] = d + 1;
                    bfsq.push_back(ch[v][c]);
                }
            }
        }
        
        if (maxDepth == 0) return ans;
        
        valid_cnt.resize(maxDepth + 1, 0);
        sole_node.resize(maxDepth + 1, -1);
        
        // Precompute A = max d with valid_cnt[d] >= 2
        int A = 0;
        for (int d = 1; d <= maxDepth; d++) {
            if (valid_cnt[d] >= 2) A = max(A, d);
        }
        
        // Precompute suffix_sole_max[d] = max d' >= d with valid_cnt[d'] == 1
        // FIX: Use max(d, suffix_sole_max[d+1]) when valid_cnt[d]==1
        vector<int> suffix_sole_max(maxDepth + 2, 0);
        for (int d = maxDepth; d >= 1; d--) {
            suffix_sole_max[d] = max(suffix_sole_max[d + 1], (valid_cnt[d] == 1) ? d : 0);
        }
        
        for (int i = 0; i < n; i++) {
            int len = words[i].size();
            
            // B[i] = max d in paths[i] with cnt > k (non-increasing, stop at first cnt <= k)
            int B = 0;
            for (int j = 0; j < len; j++) {
                if (cnt[paths[i][j]] > k) B = j + 1;
                else break;
            }
            
            int best = max(A, B);
            
            // Option C Part 1: depths > len_i (cannot be on word i's path)
            if (len + 1 <= maxDepth) {
                best = max(best, suffix_sole_max[len + 1]);
            }
            
            // Option C Part 2: depths d in (best, len] with valid_cnt[d]==1 AND sole_node[d] != paths[i][d-1]
            for (int d = min(maxDepth, len); d > best; d--) {
                if (valid_cnt[d] == 1 && sole_node[d] != paths[i][d - 1]) {
                    best = d;
                    break;
                }
            }
            
            ans[i] = best;
        }
        
        return ans;
    }
};
