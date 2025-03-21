from collections import defaultdict, deque
from typing import List

class Solution:
    def findAllRecipes(
        self, recipes: List[str], ingredients: List[List[str]], supplies: List[str]
    ) -> List[str]:
        graph = defaultdict(list)
        in_degree = defaultdict(int)
        
        for recipe, ingredient_list in zip(recipes, ingredients):
            for ingredient in ingredient_list:
                graph[ingredient].append(recipe)
            in_degree[recipe] = len(ingredient_list)
        queue = deque(supplies)

        result = []
        while queue:
            current = queue.popleft()
            for neighbor in graph[current]:
                in_degree[neighbor] -= 1 
                if in_degree[neighbor] == 0:
                    result.append(neighbor)
                    queue.append(neighbor)
        
        return result