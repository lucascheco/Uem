#/////////////////////////////////////////////////////////////////////
# Author: Lucas Pacheco
# Date: 06/02/2021 23:07:22
# Description:  Função que detecta se dois ciclos são o mesmo.
#////////////////////////////////////////////////////////////////////

######################################################################
#>> ENTRADA1
#    <3,4,2,1,5,3>
#    <2,1,5,3,4,2>

#<< SAIDA1
#    True

#>> ENTRADA2
#    <1,2,5,1>
#    <2,1,5,2>

#<< SAIDA2
#    False
######################################################################

from typing import List

# ATENCAO: Os caminhos de entrada tem que formar um ciclo.

def is_not_a_Cycle(x: List[int]):
#{
    size = len(x)
    if size <= 1 or x[0] != x[size - 1]:
        return True
    else:
        return False
#}

def is_the_same_Cycle(First_List: List[int], Second_List: List[int]):
#{
# Se não for um ciclo retornará falso.
    if is_not_a_Cycle(First_List) or is_not_a_Cycle(Second_List):
        return False
    
    VL0 = Second_List[0]     # V'0 recebe o primeiro valor da segunda lista.
    K = len(First_List) - 1  # Número de vértices.
# Em seguida procuramos o possível J 
# Que eu acho que é o index do Valor V'0 na lista 1
    for x in range(0, K):
        if First_List[x] == VL0:
            J = x;
    
    for i in range(0, K):
        if 'J' not in locals() or Second_List[i] != First_List[(i + J) % K]:
            return False

    return True
#}


x0 = [3, 4, 2, 1, 5, 3]
y0 = [2, 1, 5, 3, 4, 2]

x1 = [1, 2, 5, 1]
y1 = [2, 1, 5, 2]

x2 = [1, 2, 5, 1]
y2 = [2, 5, 1, 2]

x3 = [1, 2, 1]
y3 = [2]

x4 = [1, 2, 1]
y4 = [3, 2, 3]

x5 = [1]
y5 = []

x6 = [2, 1, 3]
y6 = [1, 2, 3]

x7 = [2, 2]
y7 = [2, 2]

# TESTS
assert is_the_same_Cycle(x0, y0) == True
assert is_the_same_Cycle(x1, y1) == False
assert is_the_same_Cycle(x2, y2) == True
assert is_the_same_Cycle(x3, y3) == False
assert is_the_same_Cycle(x4, y4) == False
assert is_the_same_Cycle(x5, y5) == False
assert is_the_same_Cycle(x6, y6) == False
assert is_the_same_Cycle(x7, y7) == True
