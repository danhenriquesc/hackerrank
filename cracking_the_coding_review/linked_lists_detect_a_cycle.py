def has_cycle(head):
    nodes = []
    while head is not None:
        if head.data in nodes:
            return True

        nodes.append(head.data)

        head = head.next

    return False
