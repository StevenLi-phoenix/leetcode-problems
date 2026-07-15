-- @leetcode id=177 questionId=177 slug=nth-highest-salary lang=mysql site=leetcode.com title="Nth Highest Salary"
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  SET N = N - 1;
  RETURN (
      SELECT DISTINCT salary
      FROM Employee
      ORDER BY salary DESC
      LIMIT 1 OFFSET N
  );
END
