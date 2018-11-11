def bubbleSort(arr):
    n = len(arr)
    counter = 0
    for i in range(n):

        for j in range(0, n - i - 1):

            if int(arr[j]) > int(arr[j + 1]):
                counter += 1
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return counter,arr
def countSwaps():
    n = int(input())
    return input()

a = countSwaps()
a = a.split()
counter, arr = (bubbleSort(a))
print("Array is sorted in "+ str(counter) +" swaps.")
print("First Element: " + str(arr[0]))
print("Last Element: " + str(arr[-1]))

