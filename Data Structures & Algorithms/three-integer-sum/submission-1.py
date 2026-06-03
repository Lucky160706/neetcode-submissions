class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        hashmap = {}
        ans = set()
        n = len(nums)

        for num in nums:
            hashmap[num] = 0 - num

        nums = sorted(nums)

        for i in range(n):
            l, r = i + 1, n - 1
            if nums[i] in hashmap:
                temp = hashmap[nums[i]]
                while l < r:
                    if nums[l] + nums[r] == temp:
                        # print(1)
                        # print(nums[l], " ", nums[r], temp)
                        ans.add((nums[i], nums[l], nums[r]))
                        l += 1
                        r -= 1
                    elif nums[l] + nums[r] < temp:
                        # print(2)
                        l += 1
                    else:
                        # print(3)
                        r -= 1
                hashmap.pop(nums[i])
        return list(ans)
