# @leetcode id=2878 questionId=3076 slug=get-the-size-of-a-dataframe lang=pythondata site=leetcode.com title="Get the Size of a DataFrame"
import pandas as pd

def getDataframeSize(players: pd.DataFrame) -> List[int]:
    return list(players.shape)
