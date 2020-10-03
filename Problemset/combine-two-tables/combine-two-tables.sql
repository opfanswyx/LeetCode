
-- @Title: 组合两个表 (Combine Two Tables)
-- @Author: opfanswyx@outlook.com
-- @Date: 2018-10-12 10:19:42
-- @Runtime: 207 ms
-- @Memory: N/A

# Write your MySQL query statement below
SELECT p.FirstName, p.LastName, a.City, a.State
FROM Person p LEFT OUTER JOIN Address a ON p.PersonID = a.PersonID;
