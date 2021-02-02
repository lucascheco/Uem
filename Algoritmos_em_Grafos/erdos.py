from typing import List, Tuple, Dict

# In C 
#int f(float x)
#{
#
#}

#In Python
#def f(x: float) -> int

# Encontra o número de erdos para cada pessoa no grafo de relções.
# A entrada é uma lista de pares representando cada relação e
# a saída é uma lista com pares(nome, número-de-erdos)

def erdos(relacoes: List[Tuple[str, str]]) -> Dict[str, int]:
    r = {"erdos": 0}
    num = 1
    atual = ["erdos"]
    atribuidos = []
    while atual != []:
        for (nome1, nome2) in relacoes:
            if nome1 in atual and nome2 not in r:
                r[nome2] = num
                atribuidos.append(nome2)
            if nome2 in atual and nome1 not in r: 
               r[nome1] = num
               atribuidos.append(nome1)
        atual = atribuidos
        atribuidos = []
        num = num + 1
    return r

ex = [
    ("erdos", "hell"),
    ("hell", "chvatal"),
    ("erdos", "chvtal"),
]

ex2 = [
    ("babai", "imrich"),
    ("babai", "lovasz"),
    ("bondy", "murty"),
    ("chvatal", "bondy"),   
    ("chvatal", "hell"),
    ("deng", "papadimitriou"),
    ("erdos", "babai"),
    ("erdos", "chvatal"),
    ("erdos", "harary"),
    ("erdos", "hell"),
    ("erdos", "lovaz"),
    ("harary", "hell"),
    ("harary", "white"),
    ("hell", "bondy"),   
    ("hell", "deng"),
    ("hell", "watkins"),
    ("imrich", "watkins"),
    ("papadimitriou", "gates"),
    ("white", "bondy"),
 ]

saida = [3, 1, 3, 1]
saida = [("erdos", 0), ("hell", 1)]

r = erdos(ex2)
for nome in r:
    print(nome + " ", r[nome])
