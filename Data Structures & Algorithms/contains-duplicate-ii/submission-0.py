class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        hashmap = {}
        n = len(nums)
        for i in range(n):
            if nums[i] in hashmap:
                if abs(hashmap[nums[i]] - i) <= k:
                    return True
            hashmap[nums[i]] = i
        return False

