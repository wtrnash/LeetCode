# Write your MySQL query statement below
Select Score, (select count(distinct Score) from Scores where Score >= s.Score) as Rank from Scores s order by Score DESC; 