-- @leetcode id=1683 questionId=1827 slug=invalid-tweets lang=mysql site=leetcode.com title="Invalid Tweets"
# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE CHAR_LENGTH(content) > 15;
