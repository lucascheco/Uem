from typing import List

def insertionSort(A: List[int]):
    j = 1 
    for j in range(len(A)):
        chave = A[j]
        i = j - 1
        while (i > -1 and A[i] > chave):
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = chave


X=[2, 1, 5, 7, 4, 3, 9, 14, 6]
print(X)
insertionSort(X)
print(X)

