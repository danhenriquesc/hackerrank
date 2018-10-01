#File name: filaprioritaria.py

#Author: Luis Carlos <luiscarlos.sf@outlook.com>

class PriorityQueue:

    def __init__(self):
        self.fila = [(0,0)]
        self.tamanho = 0

    def getTamanho(self):
        return self.tamanho

    def find_min(self):
        if self.tamanho != 0:
            return self.fila[1]

    def remove_min(self):
        minimo = self.find_min()
        self.fila[1] = self.fila[self.tamanho]
        self.tamanho = self.tamanho-1
        self.fila.pop()
        self.fix_down(1)
        return minimo

    def insert(self, elemento):
        self.fila.append(elemento)
        self.tamanho = self.tamanho+1
        self.fix_up(self.tamanho)

    def increase_key(self, node, valor):
        cont=0
        for i in self.fila:
            if node == i[1] :
                self.fila[cont] = (valor, node)
                self.fix_up(cont)
                break
            cont+=1

    #def decrease_key(self, node, valor):
    #    self.fila[node]['distance'] = valor
    #    self.fix_down(node)

    def __contains__(self, elemento):
        for pair in self.fila:
            if pair == elemento:
                return True
        return False

   #Heap Algorithms

    def fix_down(self, i):

        while 2*i <= self.tamanho:
            f = 2*i
            if f < self.tamanho and self.fila[f][0] > self.fila[f+1][0]:
                f = f+1
            if self.fila[i][0] <= self.fila[f][0]:
                i = self.tamanho
            else:
                aux = self.fila[f]
                self.fila[f] = self.fila[i]
                self.fila[i] = aux
                i = f

    def build_min_heap(self, lista):
        self.fila = [(0,0)]
        self.tamanho = len(lista)
        for i in lista:
            self.fila.append(i)
        i = len(lista)//2
        while i >= 1:
            self.fix_down(i)
            i -= 1

    def fix_up(self, i):
        while i >= 2 and self.fila[i//2][0] > self.fila[i][0]:
            aux = self.fila[i//2]
            self.fila[i//2] = self.fila[i]
            self.fila[i] = aux
            i = i//2
