
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000 

int verificaParent(char expr[]){
    char pilha[MAX];
    int topo = -1;
    
    for (int i = 0; expr[i] != '\0'; i++){
        if(expr[i] == '('){
            pilha[++topo] = '(';
        } else if(expr[i] == ')'){
            if(topo<0){
                return 0;
            }
            topo--;
        }
    }
    
    if (topo == -1) return 1;
    return 0;
    
}

int main()
{
    char expr[MAX];
    
    while(fgets(expr, sizeof(expr), stdin)){
        expr[strcspn(expr, "\n")] = '\0';
        
        if(verificaParent(expr)){
            printf("correct\n");
        } else{
            printf("incorrect\n");
        }
    }
    
    return 0;
}
