class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        unique = set()
        while l <= r:
            if nums[l] not in unique:
                unique.add(nums[l])
                l += 1
            else: 
                nums.pop(l)
                r -= 1
        return len(unique)
