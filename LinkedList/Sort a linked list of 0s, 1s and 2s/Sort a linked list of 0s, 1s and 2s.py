# problem link: https://bit.ly/3Ceotvr

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Solution:
    #Function to sort a linked list of 0s, 1s and 2s.
    def segregate(self, head):
        zeroHead, zero, oneHead, one, twoHead, two = None, None, None, None, None, None
        
        while head:
            if head.data == 0:
                if zeroHead == None:
                    zeroHead = head
                    zero = head
                else:
                    zero.next = head
                    zero = zero.next
            elif head.data == 1:
                if oneHead == None:
                    oneHead = head
                    one = head
                else:
                    one.next = head
                    one = one.next
            else:
                if twoHead == None:
                    twoHead = head
                    two = head
                else:
                    two.next = head
                    two = two.next
            head = head.next
        
        if zero is not None:
            zero.next = None
        if one is not None:
            one.next = None
        if two is not None:
            two.next = None
            
            
        if zeroHead is not None:
            if oneHead is not None:
                zero.next = oneHead
                if twoHead is not None:
                    one.next = twoHead
            elif twoHead is not None:
                zero.next = twoHead
                
            return zeroHead
        elif oneHead is not None:
            one.next = twoHead
            return oneHead
        else:
            return twoHead