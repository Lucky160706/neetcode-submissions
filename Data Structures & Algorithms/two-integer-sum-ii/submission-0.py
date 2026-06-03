class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        n = len(numbers)
        for i in range(n):
            l, r = i + 1, n - 1
            temp = target - numbers[i]
            while l <= r:
                mid = (l + r) // 2
                if numbers[mid] > temp:
                    r = mid - 1
                elif numbers[mid] < temp:
                    l = mid + 1
                else:
                    return [i + 1, mid + 1]