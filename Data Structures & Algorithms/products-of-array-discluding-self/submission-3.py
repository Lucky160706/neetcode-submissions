class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        total_product = 1
        ans = []
        k = 0
        for num in nums:
            if num != 0:
                total_product *= num
            else:
                k += 1

        for num in nums:
            if num != 0:
                if k > 0:
                    ans.append(0)
                else:
                    ans.append(total_product // num)
            elif num == 0 and k > 1:
                ans.append(0)
            else:
                ans.append(total_product)
        return ans


