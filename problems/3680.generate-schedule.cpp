// @leetcode id=3680 questionId=3991 slug=generate-schedule lang=cpp site=leetcode.com title="Generate Schedule"
class Solution {
public:
    // Generate round-robin rounds for n teams (n must be even)
    // Returns rounds where each round has n/2 matches
    vector<vector<pair<int,int>>> roundRobin(int n) {
        // n is even
        // Fix team 0, rotate teams 1..n-1
        vector<int> teams(n);
        iota(teams.begin(), teams.end(), 0);
        
        vector<vector<pair<int,int>>> rounds;
        vector<int> circle(teams.begin() + 1, teams.end());
        int half = n / 2;
        
        for (int r = 0; r < n - 1; r++) {
            vector<pair<int,int>> round;
            // Pair team 0 with circle[r % (n-1)]
            // Actually use standard construction
            vector<int> cur(n);
            cur[0] = 0;
            for (int i = 0; i < n - 1; i++) {
                cur[i + 1] = circle[(r + i) % (n - 1)];
            }
            for (int i = 0; i < half; i++) {
                round.push_back({cur[i], cur[n - 1 - i]});
            }
            rounds.push_back(round);
        }
        return rounds;
    }
    
    vector<vector<int>> generateSchedule(int n) {
        // n=3: impossible
        if (n == 3) return {};
        
        bool addedDummy = false;
        int N = n;
        if (n % 2 == 1) {
            N = n + 1;
            addedDummy = true;
        }
        
        // Get rounds for N teams (single round-robin)
        auto rounds = roundRobin(N);
        
        // Each round has N/2 matches. We need double round-robin.
        // rounds gives n-1 rounds each with N/2 matches.
        // For double: use rounds for home games, reversed for away games.
        // Total matches: 2 * (N-1) rounds * N/2 = N*(N-1) 
        // But we need n*(n-1) matches (excluding dummy team matches).
        
        // Build schedule: alternate rounds, interleaving home and away
        // For each round r: first do home order, then away (reversed teams) in round r
        
        // Strategy: schedule all matches round by round
        // Within each pair of rounds (r, r+N-1): 
        //   Day 1 of round r, Day 1 of round r (reversed), Day 2 of round r, ...
        // But we need to avoid consecutive same-team plays.
        
        // Simpler: generate double round-robin by using rounds + mirrored rounds
        // Then flatten the rounds by interleaving matches carefully
        
        // For each round in rounds, we have N/2 matches.
        // We can schedule them in a "snake" pattern across rounds.
        
        // Build all matches (home + away), grouped by rounds
        vector<vector<vector<int>>> allRounds;
        for (auto& round : rounds) {
            vector<vector<int>> r1, r2;
            for (auto& [a, b] : round) {
                if (a < N && b < N) { // skip dummy
                    if (!addedDummy || (a != n && b != n)) {
                        r1.push_back({a, b});
                        r2.push_back({b, a});
                    }
                }
            }
            if (!r1.empty()) {
                allRounds.push_back(r1);
                allRounds.push_back(r2);
            }
        }
        
        // Flatten allRounds into schedule, ensuring no consecutive team conflicts
        // Use a greedy within each "meta-round" pair
        vector<vector<int>> schedule;
        int lastA = -1, lastB = -1;
        
        for (auto& round : allRounds) {
            // Sort round to minimize conflicts with previous last teams
            // Simple: try all orderings via greedy
            vector<int> order(round.size());
            iota(order.begin(), order.end(), 0);
            sort(order.begin(), order.end(), [&](int x, int y) {
                // Prefer match not involving lastA or lastB first
                bool xConflict = (round[x][0] == lastA || round[x][0] == lastB ||
                                  round[x][1] == lastA || round[x][1] == lastB);
                bool yConflict = (round[y][0] == lastA || round[y][0] == lastB ||
                                  round[y][1] == lastA || round[y][1] == lastB);
                return !xConflict && yConflict;
            });
            
            // Schedule matches in this round greedily
            vector<bool> used(round.size(), false);
            int curA = lastA, curB = lastB;
            
            for (int i = 0; i < (int)round.size(); i++) {
                bool found = false;
                for (int j = 0; j < (int)round.size(); j++) {
                    if (used[j]) continue;
                    int h = round[j][0], a = round[j][1];
                    if (h != curA && h != curB && a != curA && a != curB) {
                        schedule.push_back({h, a});
                        used[j] = true;
                        curA = h; curB = a;
                        found = true;
                        break;
                    }
                }
                if (!found) return {}; // fallback
            }
            lastA = curA; lastB = curB;
        }
        
        return schedule;
    }
};
