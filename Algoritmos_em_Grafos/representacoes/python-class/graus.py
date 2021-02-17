from typing import List
from grafo import *

def graus_de_saida(g: Grafo):
    for v in g.vertices:
        v.grauSaida = 0

    for u in g.vertices:
        for v in u.adj:
            u.grauSaida += 1

def main():
    g = Grafo(6)
    g.addAresta(0, 1)
    g.addAresta(0, 3)
    g.addAresta(1, 4)
    g.addAresta(2, 4)
    g.addAresta(2, 5)
    g.addAresta(3, 1)
    g.addAresta(4, 3)
    g.addAresta(5, 5)

    graus_de_saida(g)

    assert g.vertices[0].graus_de_saida == 2
    assert g.vertices[1].graus_de_saida == 1
    assert g.vertices[2].graus_de_saida == 2
    assert g.vertices[3].graus_de_saida == 1
    assert g.vertices[4].graus_de_saida == 1
    assert g.vertices[5].graus_de_saida == 1
