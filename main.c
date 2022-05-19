#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

int x;
int buffer[10000];
int prod_quant, cons_quant, limit, buffer_tam;
int pos_cons, pos_ins; 

void produce(int);
void consume(int);
pthread_mutex_t mutex;

int main() {

    scanf("%d %d %d %d", &prod_quant, &cons_quant, &limit, &buffer_tam);
    pthread_t prod[prod_quant];
    pthread_t cons[cons_quant];
    
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
    return 0;
}

void consume(int id){
    
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

void produce(int id){
    
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
}


