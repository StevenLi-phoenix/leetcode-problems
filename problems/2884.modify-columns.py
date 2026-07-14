# @leetcode id=2884 questionId=3067 slug=modify-columns lang=pythondata site=leetcode.com title="Modify Columns"
import pandas as pd

def modifySalaryColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['salary'] = employees['salary'] * 2
    return employees
