from typing import List

class Vertice:

    def __init__(self, num: int) -> None:
        self.num = num
        self.adj: List[Vertice] = []

    def __str__(self) -> str:
        return "Vertice(%d)" % (self.num,)

class Grafo:

    def __init__(self, n: int) -> None:
        self.vertices = [Vertice(i) for i in range(n)]
    
    def addAresta(self, u: int, v: int):
        self.vertices[u].adj.append(self.vertices[v])