# @leetcode id=2887 questionId=3070 slug=fill-missing-data lang=pythondata site=leetcode.com title="Fill Missing Data"
import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products['quantity'] = products['quantity'].fillna(0)
    return products
