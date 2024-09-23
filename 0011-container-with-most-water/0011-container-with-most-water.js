/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function (height) {
    let ans = 0;
    const n = height.length;
    
    for (let i = 0, j = n - 1; i < j;) {
        const t = Math.min(height[i], height[j]) * (j - i);
        ans = Math.max(ans, t);
        
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    
    return ans;
};