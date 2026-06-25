# @leetcode id=2890 questionId=3073 slug=reshape-data-melt lang=pythondata site=leetcode.com title="Reshape Data: Melt"
import pandas as pd

def meltTable(report: pd.DataFrame) -> pd.DataFrame:
    return report.melt(id_vars=['product'], var_name='quarter', value_name='sales')
