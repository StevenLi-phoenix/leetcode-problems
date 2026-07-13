# @leetcode id=2879 questionId=3065 slug=display-the-first-three-rows lang=pythondata site=leetcode.com title="Display the First Three Rows"
import pandas as pd

def selectFirstRows(employees: pd.DataFrame) -> pd.DataFrame:
    return employees.head(3)
