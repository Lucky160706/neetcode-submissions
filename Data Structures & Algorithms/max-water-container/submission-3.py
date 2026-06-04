class Solution:
    def maxArea(self, heights: List[int]) -> int:
        n = len(heights) - 1
        l, r = 0, n
        lower_bound = heights[0]
        max_water = n * min(heights[0], heights[n])
        while l <= r:
            water = (r - l) * min(heights[l], heights[r])
            if heights[l] < heights[r]:
                l += 1
            else:
                r -= 1
            if water > max_water:
                max_water = water

        return max_water

                 
