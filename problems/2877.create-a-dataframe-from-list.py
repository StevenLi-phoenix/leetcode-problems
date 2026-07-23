# @leetcode id=2877 questionId=3062 slug=create-a-dataframe-from-list lang=pythondata site=leetcode.com title="Create a DataFrame from List"
import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    return pd.DataFrame(student_data, columns=['student_id', 'age'])
