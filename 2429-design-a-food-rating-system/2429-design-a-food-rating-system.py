from collections import defaultdict
from sortedcontainers import SortedList

class FoodRatings:
    def __init__(self, foods: List[str], cuisines: List[str], ratings: List[int]):
        self.a = defaultdict(SortedList)
        self.b = {}
        for f, c, r in zip(foods, cuisines, ratings):
            self.a[c].add((-r, f))
            self.b[f] = (r, c)

    def changeRating(self, food: str, newRating: int) -> None:
        r, c = self.b[food]
        self.b[food] = (newRating, c)
        self.a[c].remove((-r, food))
        self.a[c].add((-newRating, food))

    def highestRated(self, cuisine: str) -> str:
        return self.a[cuisine][0][1]
