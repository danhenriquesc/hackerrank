"""
 Print elements of a linked list on console
 head input could be None as well for empty list
 Node is defined as
 
 class Node(object):
 
   def __init__(self, data=None, next_node=None):
       self.data = data
       self.next = next_node
 
 
"""
def print_list(head):
    currentnode=head
    while currentnode!=None:
        print (currentnode.data)
        currentnode=currentnode.next
