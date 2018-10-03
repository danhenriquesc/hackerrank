def hourglassSum():

    arr = []

    for _ in range(6):
        arr.append(list(map(int, input().rstrip().split())))

    return arr

list = hourglassSum()

max = 0
i,j = 0,0
for i in range(len(list)):
    for j in range(len(list)):
        if(i <= len(list) - 3 and j <= len(list) - 3 ):
            score = list[i][j] + list[i][j+1] + list[i][j+2] + list[i+1][j+1] + list[i+2][j] + list[i+2][j+1] + list[i+2][j+2]
            if(i == 0 and j == 0):
                max = score
            if(score > max):
                max = score
print(max)