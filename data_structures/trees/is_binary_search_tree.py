#!/bin/python3


class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def in_order_array(root, arr):
    if root.left is not None:
        in_order_array(root.left, arr)
    arr.append(root.data)
    if root.right is not None:
        in_order_array(root.right, arr)

    return arr


def checkBST(root):
    array = in_order_array(root, [])
    size = len(array)
    for i in range(size - 1):
        if array[i + 1] <= array[i]:
            return False

    return True
