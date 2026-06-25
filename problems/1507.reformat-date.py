# @leetcode id=1507 questionId=1283 slug=reformat-date lang=python3 site=leetcode.com title="Reformat Date"
"""
1507. Reformat Date
"""


class Solution:
    def reformatDate(self, date: str) -> str:
        month_dict = {"Jan": "01", "Feb": "02", "Mar": "03", "Apr": "04",
                      "May": "05", "Jun": "06", "Jul": "07", "Aug": "08",
                      "Sep": "09", "Oct": "10", "Nov": "11", "Dec": "12"}
        date_list = date.split()
        return date_list[2] + "-" + month_dict[date_list[1]] + "-" + (("0" if len(date_list[0]) == 3 else "") + date_list[0][:-2])
