import pandas as pd

def fillMissingValues(products: pd.DataFrame) -> pd.DataFrame:
    products = products.assign(quantity=products['quantity'].fillna(0))
    return products