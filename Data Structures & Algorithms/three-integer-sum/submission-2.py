class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ans = set()
        n = len(nums)
        nums = sorted(nums)

        for i in range(n):
            l, r = i + 1, n - 1
            target = -nums[i]
            while l < r:
                current_sum = nums[l] + nums[r]

                if current_sum == target:
                    ans.add((nums[i], nums[l], nums[r]))
                    l += 1
                    r -= 1
                elif current_sum < target:
                    l += 1
                else:
                    r -= 1
        return list(ans)
