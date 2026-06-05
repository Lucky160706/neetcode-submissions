class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        n = len(nums)
        for i in range(n):
            ans = ans ^ nums[i]
        return ans