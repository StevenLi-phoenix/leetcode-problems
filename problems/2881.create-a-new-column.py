# @leetcode id=2881 questionId=3066 slug=create-a-new-column lang=pythondata site=leetcode.com title="Create a New Column"
import pandas as pd

def createBonusColumn(employees: pd.DataFrame) -> pd.DataFrame:
    employees['bonus'] = employees['salary'] * 2
    return employees
