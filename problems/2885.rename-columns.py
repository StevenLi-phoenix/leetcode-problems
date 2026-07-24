# @leetcode id=2885 questionId=3068 slug=rename-columns lang=pythondata site=leetcode.com title="Rename Columns"
import pandas as pd

def renameColumns(students: pd.DataFrame) -> pd.DataFrame:
    return students.rename(columns={
        "id": "student_id",
        "first": "first_name",
        "last": "last_name",
        "age": "age_in_years",
    })
