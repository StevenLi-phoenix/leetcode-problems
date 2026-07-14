# @leetcode id=2891 questionId=3063 slug=method-chaining lang=pythondata site=leetcode.com title="Method Chaining"
import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    return animals[animals['weight'] > 100].sort_values('weight', ascending=False)[['name']]
