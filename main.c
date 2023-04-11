#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct grafo{
    int**   nodes;
    int*    grau;
    int     nVertices;
} Grafo;

Grafo* makeGraph (int n){
    Grafo *gr=(Grafo*)malloc(sizeof(struct grafo));
    if (gr != NULL){
        gr->nVertices = n;
        gr->grau = (int*)calloc(n,sizeof(int));
        gr->nodes =(int**)malloc(n*sizeof(int));
        for (int x=0;x<=n;x++){
            gr->nodes[x]=(int*)malloc(n*sizeof(int));
        }
    }
    return gr;
}
int insertNode(Grafo *gr,int x,int y){
    if (gr==NULL)
        return 0;
    gr->nodes[x][gr->grau[x]] = y;
    gr->nodes[y][gr->grau[y]] = x;
    printf("Aresta(%d,%d) adicionada ao Grafo.\n",x,y);
    return 1;
}
void doBFS(Grafo *gr,int x,int *visitados){
    int i,vert,nv;
    int firstQ = 0;
    int lastQ = 0;
    int contador = 1;
    int *queue;
    for (int z=0;z<=gr->nVertices;z++){
        visitados[z]= 0;
    }
    nv = gr->nVertices;
    queue = (int*) malloc (nv*sizeof(int));
    lastQ ++;
    queue[lastQ] = x;
    visitados[x] = contador;
    while (firstQ != lastQ){
        firstQ = (firstQ + 1 )%nv;
        vert = queue[firstQ];
        contador++;
    }
}

void freeGraph (Grafo* gr){
    if (gr !=NULL){
        int x;
        for (x =0;x<=gr->nVertices;x++)
            free(gr->nodes[x]);
        free(gr->nodes);
    }
}

int main(int narg,char *argv[]){
    if (narg < 2){
        printf("Nenhum arquivo foi chamado.");
        return EXIT_SUCCESS;
    }
    else{
        int n;
        int aux1,aux2;
        FILE *file;
        file = fopen(argv[1],"r");
        if (fscanf(file,"dl\n")==EOF){
            
            return EXIT_SUCCESS;
        };

        if (fscanf(file,"format=edgelist1\n")==EOF){
            return EXIT_SUCCESS;
        };

        if (fscanf(file,"n=%d\n",&n)==EOF){
            
            return EXIT_SUCCESS;
        };

        if (fscanf(file,"data:")==EOF){
            return EXIT_SUCCESS;
        }
        Grafo *graphQST = makeGraph(n);
        while (fscanf(file,"%i %i",&aux1,&aux2)!=EOF){
            insertNode(graphQST,aux1,aux2);
        }
        int visitados[n+1];

        fclose(file);
    }

    
}
