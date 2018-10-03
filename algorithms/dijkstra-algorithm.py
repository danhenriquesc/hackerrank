#File name: dijkstra-algorithm.py
#Author: Luis Carlos <luiscarlos.sf@outlook.com>

import networkx as nx
from filaprioritaria import PriorityQueue
import sys
from matplotlib import pyplot as plt

"""
O algoritmo de Dijkstra tem como objetivo encontrar o menor caminho entre quaisquer
dois vérticas do grafo, quando todos os arcos tem comprimento não-negativos.

O algoritmo utiliza um procedimento iterativo, determinando, na iteração 1, o vértice mais
próximo de 1, na segunda iteração, o segundo vértice mais próximo do vértice 1, e assim sucessivamente,
até que em alguma iteração o vértice N seja atingido.
"""

def dijkstra(grafo, fonte):
    #Passo 1
    r_dist = list()
    for node in grafo:
        grafo.nodes[node]['distance'] = sys.maxsize
        grafo.nodes[node]['rotulado'] = False #Indica se o grafo foi rotulado ou não
    grafo.nodes[fonte]['distance']= 0
    
    #Inicio
    nr = PriorityQueue() #Fila de prioriadade vazia dos nós não rotulados.
    caminho_minimo=[(grafo.nodes[node]['distance'], node) for node in list(grafo)] #Lista de tuplas ({'distance': value}, node)
    nr.build_min_heap(caminho_minimo) #Dando heap na lista recem criada

    while nr.getTamanho()!=0:
        #Passo 2.1
        u = nr.remove_min()
        k = u[1]
        #Passo 2.2
        grafo.nodes[k]['rotulado']=True
        r_dist.append(u)
        #Passo 2.3
        for j in list(grafo.successors(k)):
            if not grafo.nodes[j]['rotulado']:
                novo_custo = grafo.nodes[k]['distance']+grafo.edges[k, j]['weight']
                if novo_custo < grafo.nodes[j]['distance']:
                    grafo.nodes[j]['distance'] = novo_custo
                    grafo.nodes[j]['precedente'] = k
                    nr.increase_key(j, novo_custo)

    #Definindo Caminho Mínimo
    caminho_minimo=list()
    cont=0
    z=0
    for w in grafo:
        cont+=1
        z= grafo.nodes[w]['distance']
        if cont == grafo.order():
            i=w
            while cont != 0:
                try:
                    caminho_minimo.append(i)
                    i=grafo.nodes[i]['precedente']
                except:
                    cont=0
            break



    print("Caminho Minimo: ", caminho_minimo[::-1],"Z=", z)
    return r_dist

class Teste():

    def main(self):
        grafo = nx.DiGraph()
        grafo.add_nodes_from(range(1, 10))
        grafo.add_edges_from([(1,2,{'weight':11}),(1,3,{'weight':9}),(2,4,{'weight':4}),\
                            (2,5,{'weight':8}), (3,4,{'weight':8}), (3,5,{'weight':6}), \
                            (4,6,{'weight':6}),(4,7,{'weight':5}), (5,7,{'weight':6}),\
                            (5,8,{'weight':4}), (6,9,{'weight':6}),(7,9,{'weight':4}), (8,9,{'weight':6})])

        print("Nodes\n", grafo.nodes())
        print("Edges\n", grafo.edges(data=True))

        fonte = input("Digite o vértice fonte: ")
        try:
            fonte = int(fonte)
        except():
            pass

        if fonte in grafo:
            print(fonte)
            custos = dijkstra(grafo, fonte)
            print("Distâncias do ",fonte,"para todos os outros vértices: (distãncia, destino)\n",custos)
        else:
            print("Não existe nenhum vértice com essa definição")


if __name__=="__main__":
    Teste().main()

