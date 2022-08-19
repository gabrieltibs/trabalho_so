//Aluno Gabriel Tiberius Maya Quintanilha Martins
#include <stdio.h>
#define N 5
typedef int semaphore;
semaphore mutex = 1;  //controla o acesso a regi�o cr�tica
semaphore empty = N;  //indica quantos slots vazios est�o no buffer (inicializa com N)
semaphore full = 0;   //indica quantos slots est�o cheios no buffer (incializa com 0)

void producer (void)
{
    int item;
    while (TRUE) {
        item = produce_item();
        down(&empty);
        down(&mutex);
        insert_item(item);
        up(&mutex);
        up(&full);
    }
}

void consumer (void)
{
    int item;
    while (TRUE){
        down (&full);
        down (&mutex);
        item = remove_item();
        up (&mutex);
        up (&empty);
        consume_item (item);
    }
}
