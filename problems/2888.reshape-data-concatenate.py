# @leetcode id=2888 questionId=3064 slug=reshape-data-concatenate lang=pythondata site=leetcode.com title="Reshape Data: Concatenate"
import pandas as pd

def concatenateTables(df1: pd.DataFrame, df2: pd.DataFrame) -> pd.DataFrame:
    return pd.concat([df1, df2], ignore_index=True)
