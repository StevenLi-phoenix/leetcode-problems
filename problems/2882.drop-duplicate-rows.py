# @leetcode id=2882 questionId=3071 slug=drop-duplicate-rows lang=pythondata site=leetcode.com title="Drop Duplicate Rows"
import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    return customers.drop_duplicates(subset='email', keep='first')
