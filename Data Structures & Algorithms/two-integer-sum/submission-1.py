class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashmap = {}
        i, j = -1, -1
        for index in range(len(nums)):
            if target - nums[index] in hashmap:
                i = hashmap[target - nums[index]]
                j = index
            hashmap[nums[index]] = index
        return [i, j]
        