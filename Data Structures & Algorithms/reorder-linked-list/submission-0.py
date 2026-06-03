# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        list_pointers = [head]
        pointer = head
        while pointer.next:
            pointer = pointer.next
            list_pointers.append(pointer)
        
        n = len(list_pointers) - 1  # n = 6
        m = math.floor(len(list_pointers) / 2)  # m = 3
        

        for i in range(m):
            temp = list_pointers[i + 1]
            list_pointers[i].next = list_pointers[n - i]
            list_pointers[n - i].next = list_pointers[i + 1]

        list_pointers[m].next = None
        
        head = list_pointers[0]
        