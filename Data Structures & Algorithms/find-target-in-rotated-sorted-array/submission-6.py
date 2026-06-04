class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if target < min(nums) or target > max(nums):
            return -1
            
        l, r = 0, len(nums) - 1

        while l < r:
            mid = (l + r) // 2
            if nums[mid] > nums[r]:
                l = mid + 1
            else:
                r = mid

        pivot = l

        def binary_search(left: int, right: int) -> int:
            while left <= right:
                mid = (left + right) // 2
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    right = mid - 1
                else:
                    left = mid + 1

            return -1
        
        left_part = binary_search(0, pivot)
        right_part = binary_search(pivot, len(nums) - 1)

        return left_part if left_part != -1 else right_part
            