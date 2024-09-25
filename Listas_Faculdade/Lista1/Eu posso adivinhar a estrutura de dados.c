while (não houver mais dados no arquivo) faça
    ler n (quantidade de operações)

    scanf("%d", &n);
    
    inicializar pilha, fila, filaDePrioridade como listas vazias
    marcarPilha, marcarFila, marcarFilaDePrioridade como verdadeiro
    
    para i de 1 até n faça
        ler comando
        se comando for "1 x" então
            ler x
            se marcarPilha for verdadeiro então
                empilhar x na pilha
            se marcarFila for verdadeiro então
                enfileirar x na fila
            se marcarFilaDePrioridade for verdadeiro então
                enfileirarPrioridade x na filaDePrioridade
        senão se comando for "2 x" então
            ler x
            se marcarPilha for verdadeiro então
                se pilha estiver vazia ou topo da pilha não for igual a x então
                    marcarPilha como falso
            se marcarFila for verdadeiro então
                se fila estiver vazia ou frente da fila não for igual a x então
                    marcarFila como falso
            se marcarFilaDePrioridade for verdadeiro então
                se filaDePrioridade estiver vazia ou maiorPrioridade da filaDePrioridade não for igual a x então
                    marcarFilaDePrioridade como falso
    
    se somente um dos tipos de estrutura for válido então
        if(marcarPilha == 1){printf("stack");}
        else if(marcarFila == 1){printf("queue");}
        else if(marcarFilaDePrioridade == 1){printf("priority queue");}

    senão se mais de uma estrutura for válida então
        printf("not sure");
    senão
        printf("impossible");
