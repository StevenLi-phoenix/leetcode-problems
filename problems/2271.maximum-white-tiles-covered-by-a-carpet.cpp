// @leetcode id=2271 questionId=2359 slug=maximum-white-tiles-covered-by-a-carpet lang=cpp site=leetcode.com title="Maximum White Tiles Covered by a Carpet"
class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int n = tiles.size();
        
        // Prefix sum of white tiles
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (tiles[i][1] - tiles[i][0] + 1);
        }
        
        // For each starting tile i, carpet covers [l_i, l_i + carpetLen - 1]
        // Binary search to find the last tile fully or partially covered
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            long long carpetEnd = (long long)tiles[i][0] + carpetLen - 1;
            
            // Find last tile j where tiles[j][0] <= carpetEnd
            int lo = i, hi = n - 1, j = i - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (tiles[mid][0] <= carpetEnd) {
                    j = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            
            if (j < i) {
                ans = max(ans, 0);
                continue;
            }
            
            // Tiles i..j-1 are fully covered, tile j might be partially covered
            long long covered = prefix[j] - prefix[i]; // tiles i to j-1
            
            if (tiles[j][1] <= carpetEnd) {
                // Tile j is fully covered
                covered += tiles[j][1] - tiles[j][0] + 1;
            } else {
                // Tile j is partially covered
                covered += carpetEnd - tiles[j][0] + 1;
            }
            
            ans = max(ans, (int)covered);
        }
        
        return ans;
    }
};
