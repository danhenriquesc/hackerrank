def is_matched(expression):
    ok = ['()', '[]', '{}']

    for i in range(75):
        for item in ok:
            expression = expression.replace(item, '')

    return len(expression) == 0


t = int(input().strip())
for a0 in range(t):
    expression = str(input())
    if is_matched(expression) is True:
        print("YES")
    else:
        print("NO")

#################################################################################################
#  A correct stack approach would be the below, but, that approach have a problem with timeout  #
#################################################################################################

# MAPPER = {
#     '}': '{',
#     ']': '[',
#     ')': '(',
# }

# OPENING_BRACKETS = MAPPER.values()
# CLOSING_BRACKETS = MAPPER.keys()


# def is_matched(expression):
#     if len(expression) % 2:
#         return False

#     stack = []
#     for bracket in expression:
#         if bracket in OPENING_BRACKETS:
#             stack.append(bracket)
#         else:
#             last_item = stack.pop()

#             if last_item != MAPPER[bracket]:
#                 return False

#     return len(stack) == 0


# t = int(input().strip())
# for a0 in range(t):
#     expression = input().strip()
#     if is_matched(expression) is True:
#         print("YES")
#     else:
#         print("NO")
