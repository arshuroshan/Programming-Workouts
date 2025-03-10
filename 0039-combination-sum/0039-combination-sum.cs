using System;
using System.Collections.Generic;

public class Solution {
    public IList<IList<int>> CombinationSum(int[] candidates, int target) {
        Array.Sort(candidates);
        IList<IList<int>> result = new List<IList<int>>();
        Stack<(int index, int remainingSum, List<int> currentCombination)> stack = new Stack<(int, int, List<int>)>();

        stack.Push((0, target, new List<int>()));

        while (stack.Count > 0) {
            var (index, remainingSum, currentCombination) = stack.Pop();

            if (remainingSum == 0) {
                result.Add(new List<int>(currentCombination));
                continue;
            }

            for (int i = index; i < candidates.Length; i++) {
                if (candidates[i] > remainingSum) {
                    break;
                }

                currentCombination.Add(candidates[i]);

                stack.Push((i, remainingSum - candidates[i], new List<int>(currentCombination)));

                currentCombination.RemoveAt(currentCombination.Count - 1);
            }
        }

        return result;
    }
}