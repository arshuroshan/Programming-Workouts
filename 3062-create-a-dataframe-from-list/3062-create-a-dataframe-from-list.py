import pandas as pd

def createDataframe(student_data: List[List[int]]) -> pd.DataFrame:
    data_dict = {'student_id': [row[0] for row in student_data],
                 'age': [row[1] for row in student_data]}
    return pd.DataFrame(data_dict)