# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param head ListNode类 
# @return ListNode类
# https://www.nowcoder.com/questionTerminal/75e878df47f24fdc9dc3e400ec6058ca
#
class Solution:
    def ReverseList(self , head: ListNode) -> ListNode:
        # write code here
        pre=None
        while(head!=None):
            tmp=head.next
            head.next=pre
            pre,head=head,tmp
        return pre
        
        
        