#Description: Function will search through input (input_list) for an integer (item)
def binary_search(input_list, item):
    if len(input_list) == 0:    #if list is empty, return False
        return False
    else:                               #list is not empty, so determine the middle of list
        midpoint = len(input_list)//2

        if(input_list[midpoint] == item):       #if number is found, return true
            return True
        else:
            if(item < input_list[midpoint]):
                return binary_search(input_list[:midpoint], item)
            else:
                return binary_search(input_list[midpoint + 1:], item)






def main():

    test_list = [1, 2, 3, 4, 5, 6, 7, 8, 9]         #test list of intergers

    found_item = binary_search(test_list, 9)

    print(found_item)



main()
