# @leetcode id=1528 questionId=1651 slug=shuffle-string lang=python3 site=leetcode.com title="Shuffle String"
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        shuffled_string = [None] * len(s)
        for i in range(len(s)):
            shuffled_string[indices[i]] = s[i]
        return "".join(shuffled_string)
