class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        sett = set(nums)
        unique_num = sorted(list(set(nums)))
        max_k, k = 1, 1
        for i in range(len(unique_num) - 1):
            if unique_num[i + 1] == 1 + unique_num[i]:
                k += 1
            else:
                if max_k < k:
                    max_k = k
                k = 1
        return max(max_k, k)
            