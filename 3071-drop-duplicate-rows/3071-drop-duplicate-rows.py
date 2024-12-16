import pandas as pd

def dropDuplicateEmails(customers: pd.DataFrame) -> pd.DataFrame:
    seen = set()
    unique_customers = []
    
    for _, row in customers.iterrows():
        if row['email'] not in seen:
            seen.add(row['email'])
            unique_customers.append(row)
    
    return pd.DataFrame(unique_customers).reset_index(drop=True)