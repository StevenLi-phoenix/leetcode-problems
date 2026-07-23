# @leetcode id=2880 questionId=3074 slug=select-data lang=pythondata site=leetcode.com title="Select Data"
import pandas as pd

def selectData(students: pd.DataFrame) -> pd.DataFrame:
    return students[students['student_id'] == 101][['name', 'age']]
