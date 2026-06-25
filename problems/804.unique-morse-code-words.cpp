// @leetcode id=804 questionId=822 slug=unique-morse-code-words lang=cpp site=leetcode.com title="Unique Morse Code Words"
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        // Correct Morse code for a-z
        vector<string> morse = {
            ".-","-...","-.-.","-..",".",
            "..-.","--.","....","..",".---",
            "-.-",".-..","--","-.","---",
            ".--.","--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--",
            "--.."
        };
        
        unordered_set<string> uniqueTransforms;
        
        for (const string& word : words) {
            string transform = "";
            for (char c : word) {
                transform += morse[c - 'a'];
            }
            uniqueTransforms.insert(transform);
        }
        
        return uniqueTransforms.size();
    }
};
