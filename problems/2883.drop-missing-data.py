# @leetcode id=2883 questionId=3075 slug=drop-missing-data lang=pythondata site=leetcode.com title="Drop Missing Data"
import pandas as pd

def dropMissingData(students: pd.DataFrame) -> pd.DataFrame:
    return students.dropna(subset=['name'])
