from collections import defaultdict

class Graph():
    def __init__(self,n,nodes):
        self.nV = n
        self.neighbourhood = [[] for i in range(n+1)]
        self.getNodes(nodes)
        self.isVisited = []
        self.graphNode = [[] for i in range(n+1)]
        self.addedNodes = [[] for i in range(n+1)]
        self.isVisited2 = []
    def getNodes(self,nodes):
        for x,y in nodes:
            self.getLink(x,y)
        
    def getLink(self,x,y):
        self.neighbourhood[x].append(y)
        self.neighbourhood[y].append(x)
    
    def BFS(self,node,i):
        queue = []
        self.isVisited.append(node)
        queue.append(node)
        while queue:
            s= queue.pop(0)
            for node in self.neighbourhood[s]:
                if node not in self.isVisited:
                    self.isVisited.append(node)
                    queue.append(node)
            self.addedNodes[i].append(s)
    def sortNodes(self):
        for i in range(n+1):
            self.addedNodes[i].sort()

    def doQST(self):
        for i in range(n+1):
            if (i>0)and (i not in self.isVisited2):
                for x in self.addedNodes[i]:
                    print(x,end=" ")
                    self.isVisited2.append(x)
                    
                print("\n")


n=input("dl n")

nodes = [(2,9),(3,8),(5,7),(6,9),(8,10)]
graph = Graph(n,nodes)
for i in range (n+1):
    graph.BFS(i,i)
graph.sortNodes()
graph.doQST()
