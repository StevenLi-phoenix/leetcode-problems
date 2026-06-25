// @leetcode id=3714 questionId=4056 slug=longest-balanced-substring-ii lang=cpp site=leetcode.com title="Longest Balanced Substring II"
class Solution {
public:
int longestBalanced(string s) {
int n = s.size();
int ans = 1; // at least 1 char is always balanced

// Case 1: exactly 1 distinct char - longest run
for (int i = 0; i < n; ) {
int j = i;
while (j < n && s[j] == s[i]) j++;
ans = max(ans, j - i);
i = j;
}

// Case 2: exactly 2 distinct chars with equal counts
// For each pair (c1, c2), find segments without the third char
// and within each segment find longest with equal counts of c1 and c2
string chars = "abc";
for (int p = 0; p < 3; p++) {
char c1 = chars[p], c2 = chars[(p+1)%3], c3 = chars[(p+2)%3];
// Split by c3, find longest in each segment with count(c1) == count(c2)
int start = 0;
while (start < n) {
if (s[start] == c3) { start++; continue; }
int end = start;
while (end < n && s[end] != c3) end++;
// Segment [start, end-1] has no c3
// Find longest substring with count(c1) == count(c2)
// Use prefix difference: diff = count(c1) - count(c2)
// First occurrence of each diff value
unordered_map<int, int> first;
int diff = 0;
first[0] = start; // before start, diff is 0
for (int i = start; i < end; i++) {
if (s[i] == c1) diff++;
else if (s[i] == c2) diff--;
// both c1 and c2 must be present for "exactly 2 distinct"
// but substring with only c1 is handled in case 1
if (first.count(diff)) {
int len = i + 1 - first[diff];
// check if both c1 and c2 are present in [first[diff], i]
// this is guaranteed if count(c1) > 0 and count(c2) > 0
// since diff same means count(c1)==count(c2), 
// if len > 0 and diff was 0 at both ends, counts are equal
// but they could both be 0 if substring has neither c1 nor c2
// In this segment, we only have c1 and c2, so any non-empty substring has at least one
ans = max(ans, len);
} else {
first[diff] = i + 1;
}
}
start = end;
}
}

// Case 3: all 3 distinct chars with equal counts
// Use prefix: (count_a - count_b, count_b - count_c)
// When these are the same at two positions, the substring between them has equal counts
map<pair<int,int>, int> firstOcc;
int ca = 0, cb = 0, cc = 0;
firstOcc[{0, 0}] = 0;
for (int i = 0; i < n; i++) {
if (s[i] == 'a') ca++;
else if (s[i] == 'b') cb++;
else cc++;
auto key = make_pair(ca - cb, cb - cc);
if (firstOcc.count(key)) {
int len = i + 1 - firstOcc[key];
ans = max(ans, len);
} else {
firstOcc[key] = i + 1;
}
}

return ans;
}
};
