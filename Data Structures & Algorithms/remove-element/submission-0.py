class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        k = 0
        n = len(nums)
        for i in range(n):
            if nums[i] == val:
                nums[i] = max(nums) + 1
            else:
                k += 1
        nums.sort()
        return k
