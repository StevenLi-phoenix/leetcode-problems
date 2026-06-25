// @leetcode id=3377 questionId=3655 slug=digit-operations-to-make-two-integers-equal lang=cpp site=leetcode.com title="Digit Operations to Make Two Integers Equal"
class Solution {
public:
    // Sieve of Eratosthenes
    vector<bool> sieve;
    
    void buildSieve(int limit) {
        sieve.assign(limit + 1, true);
        sieve[0] = sieve[1] = false;
        for (int i = 2; i * i <= limit; i++) {
            if (sieve[i]) {
                for (int j = i * i; j <= limit; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }
    
    int minOperations(int n, int m) {
        buildSieve(10000);
        
        // If n is prime initially, impossible
        if (sieve[n]) return -1;
        // If m is prime, impossible
        if (sieve[m]) return -1;
        
        // Dijkstra
        // dist[v] = min cost to reach v
        vector<long long> dist(10001, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        
        dist[n] = n;
        pq.push({n, n});
        
        while (!pq.empty()) {
            auto [d, cur] = pq.top();
            pq.pop();
            
            if (cur == m) return (int)d;
            if (d > dist[cur]) continue;
            
            // Get digits of cur
            string s = to_string(cur);
            int len = s.size();
            
            for (int i = 0; i < len; i++) {
                // Increase digit
                if (s[i] != '9') {
                    s[i]++;
                    int next = stoi(s);
                    if (!sieve[next] && dist[cur] + next < dist[next]) {
                        dist[next] = dist[cur] + next;
                        pq.push({dist[next], next});
                    }
                    s[i]--;
                }
                // Decrease digit
                if (s[i] != '0') {
                    // Can't make leading zeros
                    if (i == 0 && s[i] == '1') {
                        // Would create leading zero, skip
                    } else {
                        s[i]--;
                        int next = stoi(s);
                        if (!sieve[next] && dist[cur] + next < dist[next]) {
                            dist[next] = dist[cur] + next;
                            pq.push({dist[next], next});
                        }
                        s[i]++;
                    }
                }
            }
        }
        
        return dist[m] == LLONG_MAX ? -1 : (int)dist[m];
    }
};
