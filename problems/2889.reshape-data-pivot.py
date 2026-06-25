# @leetcode id=2889 questionId=3072 slug=reshape-data-pivot lang=pythondata site=leetcode.com title="Reshape Data: Pivot"
import pandas as pd

def pivotTable(weather: pd.DataFrame) -> pd.DataFrame:
    return weather.pivot(index='month', columns='city', values='temperature')
