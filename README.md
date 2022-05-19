# AtividadeInfraSoftware6

## Proposito do código

>O codigo tem como objetivo implementar o problema do produto consumidor usando threads

## Funções mínimas do makefile

> Tem 3 funções essenciais pedidas nessa tarefa, o make que compila o código e gera o binário, o make run pra compilar o código e o make clear para apagar o binário gerado.

## Thread

```c
  // criando as threads
    for (int i = 0; i <= prod_quant; i++){
        pthread_create(&prod[i], NULL, produce, i);
    }
    
    for (int i = 0; i <= cons_quant; i++){
        pthread_create(&cons[i], NULL, consume, i);
    }

    for (int i = 0; i <= prod_quant; i++){
        pthread_join(prod[i], NULL);
    }
    
    for (int i = 0; i <= cons_quant; i++){
        pthread_join(cons[i], NULL);
    }

```

## Função Consumir

```c
int x;
while(1){
    pthread_mutex_lock(&mutex);
    x = buffer[pos_cons];
    if (x != 0){ // não sabia fazer o semaforo
        printf("Consumidor %d consumindo %d na posição %d\n", id, x, pos_cons % buffer_tam);
    }
    pos_cons ++ ;
    pthread_mutex_unlock(&mutex);
    sleep(1);
    }
}
```

## Função Produzir
```c
    int i = 0;
    while(1) {
        if (i == limit) {
            i = 0;
        }
        x = (2 * i) + 1;
        
        pthread_mutex_lock(&mutex);
        buffer[pos_ins] = x;
        if (x != 0) { // não sabia fazer o semaforo
            printf("Produtor %d produzindo %d na posição %d\n", id, buffer[pos_ins], pos_ins  % buffer_tam);
        }
        pos_ins ++;
        pthread_mutex_unlock(&mutex);
        i++;
        sleep(1);
    }
```
