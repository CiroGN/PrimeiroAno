import numpy as np

A = [[1,1,2],[2,4,-3],[3,6,-5]]
somaLinha = []

print(A)
print('O numero de linhas da matriz A é: ' + str(len(A)))
print('O numero de colunas da matriz A é: ' + str(len(A[0])))


for i in range (len(A)):
    somaLinhas = 0
    # print(i)
    for j in range (len(A[0])):
        # print(j)
        print('a[' + str(i+1) + ']' + '[' + str(j) + '] = ' + str(A[i][j]))
        somaLinhas += A[i][j]
    somaLinha.append(somaLinhas)
    print('A soma da linha é: ' + str(somaLinhas))    
    
    print('As somas das linhas são: ' + str(somaLinha))    
