-- @leetcode id=3570 questionId=3910 slug=find-books-with-no-available-copies lang=mysql site=leetcode.com title="Find Books with No Available Copies"
# Write your MySQL query statement below
SELECT
    lb.book_id,
    lb.title,
    lb.author,
    lb.genre,
    lb.publication_year,
    COUNT(br.record_id) AS current_borrowers
FROM library_books lb
JOIN borrowing_records br ON br.book_id = lb.book_id AND br.return_date IS NULL
GROUP BY lb.book_id, lb.title, lb.author, lb.genre, lb.publication_year, lb.total_copies
HAVING lb.total_copies - COUNT(br.record_id) = 0
ORDER BY current_borrowers DESC, lb.title ASC;
