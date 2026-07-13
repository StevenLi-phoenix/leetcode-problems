# @leetcode id=2886 questionId=3069 slug=change-data-type lang=pythondata site=leetcode.com title="Change Data Type"
import pandas as pd

def changeDatatype(students: pd.DataFrame) -> pd.DataFrame:
    students['grade'] = students['grade'].astype(int)
    return students
