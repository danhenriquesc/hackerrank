#Python3 solution for HackerRank problem - Grading Students

def gradingStudents(grades):   
    length = len(grades)
    result = []
    
    for i in range(length):
        if grades[i]>37:
            if grades[i]%5 >= 3:
                grades[i] += (5 - grades[i]%5)
                
        result.append(grades[i])
    
    return result

if __name__ == '__main__':
    
    n = int(input())   
    grades = []

    for _ in range(n):
        grades_item = int(input())
        grades.append(grades_item)

    result = gradingStudents(grades)

    for _ in range(n):
        print(result[_])