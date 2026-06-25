// @leetcode id=3629 questionId=3933 slug=minimum-jumps-to-reach-end-via-prime-teleportation lang=cpp site=leetcode.com title="Minimum Jumps to Reach End via Prime Teleportation"
class Solution {
public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        
        // Find max element for sieve
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Sieve of Eratosthenes
        vector<bool> isPrime(maxVal + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; (long long)i * i <= maxVal; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= maxVal; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        // Build map: prime -> list of indices where nums[i] % prime == 0
        unordered_map<int, vector<int>> primeToIndices;
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            // Find all prime factors of val
            for (int p = 2; (long long)p * p <= val; p++) {
                if (isPrime[p] && val % p == 0) {
                    primeToIndices[p].push_back(i);
                    while (val % p == 0) val /= p;
                }
            }
            if (val > 1) {
                primeToIndices[val].push_back(i);
            }
        }
        
        // BFS
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        
        while (!q.empty()) {
            int sz = q.size();
            steps++;
            while (sz--) {
                int i = q.front();
                q.pop();
                
                // Adjacent steps
                auto tryVisit = [&](int j) {
                    if (j >= 0 && j < n && !visited[j]) {
                        if (j == n - 1) return true;
                        visited[j] = true;
                        q.push(j);
                    }
                    return false;
                };
                
                if (i + 1 < n) {
                    if (!visited[i + 1]) {
                        if (i + 1 == n - 1) return steps;
                        visited[i + 1] = true;
                        q.push(i + 1);
                    }
                }
                if (i - 1 >= 0) {
                    if (!visited[i - 1]) {
                        if (i - 1 == n - 1) return steps;
                        visited[i - 1] = true;
                        q.push(i - 1);
                    }
                }
                
                // Prime teleportation: if nums[i] is prime, teleport to all indices j with nums[j] % nums[i] == 0
                if (isPrime[nums[i]]) {
                    int p = nums[i];
                    if (primeToIndices.count(p)) {
                        for (int j : primeToIndices[p]) {
                            if (!visited[j]) {
                                if (j == n - 1) return steps;
                                visited[j] = true;
                                q.push(j);
                            }
                        }
                        primeToIndices.erase(p);
                    }
                }
            }
        }
        
        return -1;
    }
};
