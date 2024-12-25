import pandas as pd

def findHeavyAnimals(animals: pd.DataFrame) -> pd.DataFrame:
    heavy_animals = animals.query('weight > 100')
    return heavy_animals.nlargest(len(heavy_animals), 'weight')[['name']]