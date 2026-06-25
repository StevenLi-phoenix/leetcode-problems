# @leetcode id=1456 questionId=1567 slug=maximum-number-of-vowels-in-a-substring-of-given-length lang=python3 site=leetcode.com title="Maximum Number of Vowels in a Substring of Given Length"
class Solution:
    def maxVowels(self, s: str, k: int) -> int:
        vowels = "aeiou"
        max_vowels = 0
        vowels_count = 0
        for i in range(len(s)):
            if s[i] in vowels:
                vowels_count += 1
            if i >= k and s[i - k] in vowels:
                vowels_count -= 1
            max_vowels = max(max_vowels, vowels_count)
        return max_vowels
