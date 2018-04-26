class Node:
    number = ''
    counter = 1
    left = None
    right = None

    def __init__(self, number):
        self.number = number

    def add_counter(self, count):
        self.counter += count

    def __str__(self):
        return '(Number: {} - Counter: {} - Left: {} - Right: {})'.format(self.number, self.counter, self.left, self.right)

    __repr__ = __str__


n = int(input().strip())
number = int(input().strip())

root = Node(number)


for i in range(n-1):
   number = int(input().strip())

   cur_node = root
   while cur_node is not None:
       previous_node = cur_node
       
       if number >= cur_node.number:
          dir = 'right'
       else:
          dir = 'left'
       
       cur_node.add_counter(1)
       cur_node = getattr(cur_node, dir)

   setattr(previous_node, dir, Node(number))
   
   print(root)
#    c = root
#    find = (i + 1) // 2
#    left = 0
   
#    while True:
#        l = c.get('l', {}).get('c', 0)
#        r = c.get('r', {}).get('c', 0)
#        print(c)
#        print(find, l, r)
#        if l >= find:
#            c = c.get('l')
#        elif r > find:
#            left += l
#            c = c.get('r')
       
#        if left == find - 1 or left == find:
#             break
            
#    print(find, left, c)

   
   #print('{:.1f}'.format(o_c.get('n')))

from heapq import heappush, heappop

n = int(input().strip())
heaps = [[] for _ in range(n)]

for i in range(n):
    number = int(input().strip())
    median = 0
    
    for j in range(i, n):
        heappush(heaps[j], number)
    
    if (i + 1) % 2:
        needed = (i + 1) // 2 + 1
        for j in range(needed):
            median = heappop(heaps[i])
   
    else:
        needed = (i + 1) // 2
        for j in range(needed):
            median = heappop(heaps[i])
        
        median += heappop(heaps[i])
        median /= 2

    print('{:.1f}'.format(median))
