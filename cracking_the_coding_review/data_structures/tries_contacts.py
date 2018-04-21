n = int(input().strip())

contacts = {}

for a0 in range(n):
    op, contact = input().strip().split(' ')

    if op == 'add':
        for i in range(len(contact) + 1):
            suffix = contact[:i]
            if suffix in contacts:
                contacts[suffix] += 1
            else:
                contacts[suffix] = 1
    else:
        print(contacts.get(contact, 0))
