def CountingSort(array):
    maxNum = max(array)
    
    arrayCount = [0] * (maxNum + 1) 
    
    for num in array:
        arrayCount[num] += 1
    
    index = 0
    for i, count in enumerate(arrayCount):
        while count > 0:  
            array[index] = i
            index += 1
            count -= 1
    
    return array

arrayExemplo = [1, 4, 2, 6, 0, 2, 7, 1]
CountingSort(arrayExemplo)
print(arrayExemplo)
