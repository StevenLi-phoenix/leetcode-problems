// @leetcode id=67 questionId=67 slug=add-binary lang=cpp site=leetcode.com title="Add Binary"
class Solution {
public:
string addBinary(string a, string b) {
string result;
int carry = 0;
int i = a.size() - 1, j = b.size() - 1;
while (i >= 0 || j >= 0 || carry) {
int sum = carry;
if (i >= 0) sum += a[i--] - '0';
if (j >= 0) sum += b[j--] - '0';
result += (char)('0' + sum % 2);
carry = sum / 2;
}
reverse(result.begin(), result.end());
return result;
}
};
