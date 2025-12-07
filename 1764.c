#include <stdio.h>
#include <stdlib.h>

typedef struct { int x,y,z; } aresta;

int *pai;

int achar(int x) {
    if (pai[x]==x) return x;
    return pai[x] = achar(pai[x]);
}

void unir(int a,int b){
    a = achar(a);
    b = achar(b);
    if (a!=b) pai[b]=a;
}

int cmp(const void *a,const void *b){
    const aresta *p = a, *q = b;
    if (p->z < q->z) return -1;
    if (p->z > q->z) return 1;
    return 0;
}

int main(){
    int m,n;
    while (scanf("%d %d",&m,&n)==2 && (m||n)) {
        aresta *v = malloc(n * sizeof(aresta));
        pai = malloc(m * sizeof(int));
        for (int i=0;i<m;i++) pai[i]=i;

        long long soma = 0, mst = 0;
        for (int i=0;i<n;i++){
            scanf("%d %d %d",&v[i].x,&v[i].y,&v[i].z);
            soma += v[i].z;
        }

        qsort(v, n, sizeof(aresta), cmp);

        for (int i=0;i<n;i++){
            if (achar(v[i].x) != achar(v[i].y)){
                unir(v[i].x, v[i].y);
                mst += v[i].z;
            }
        }

        printf("%lld\n", mst);

        free(v);
        free(pai);
    }
    return 0;
}
