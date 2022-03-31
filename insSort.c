/* Librerie:
 * stdlib.h per la funzione srand()
 * time.h per prendere il tempo di clock
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Algoritmo InsertionSort: passo per parametri puntatore Array e la sua lunghezza */
void InsertionSort(int *A, int len)
{
    int i, j, key;
    for (j = 0; j < len; j++)
    {
        key = A[j];
        i = j - 1;
        while ((i >= 0) && (A[i] > key))
        {
            A[i + 1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
    }
}

/* ESPERIMENTO SINGOLO */
float singoloEsperimento(int len, int maxInstance)
{
    float timeTot = 0;
    for (int i = 0; i < maxInstance; i++)
    {
        float timeStart, timeEnd, timeElapsed;
        int A[len];

        for (int j = 0; j < len; j++)    // Generatore Array di numeri Casuali:
        {                                // tramite il metodo rand()%N, genera un numero tra 0 e N-1
            A[j] = 1 + rand() % 1000000; // e metto il numero generato nell'array
        }

        printf("Non ordinato\n");
        for (int j = 0; j < len; j++)    
        {                                
            printf("%d\n", A[j]); 
        }

        timeStart = clock(); //inzio tempo
        InsertionSort(A, len);
        timeEnd = clock(); //fine tempo

        printf("ordinato\n");
        for (int j = 0; j < len; j++)    
        {                                
            printf("%d\n", A[j]); 
        }
        timeElapsed = timeEnd - timeStart; //tempo trascorso
        timeTot = timeTot + timeElapsed;
    }
    return timeTot / maxInstance;
}

/* ESPERIMENTO INSERTION SORT */
void esperimento(int minLen, int maxLen)
{
    int maxInstances = 2; // numero di istanze array per tentativo della lunghezza dell'array
    int STEP = 1;         // mi aumenta numero di elementi dell'array                        
    float time;

    for (int i = minLen; i < maxLen; i = i + STEP)
    {
        time = singoloEsperimento(i, maxInstances);
        printf("Tempo per %d elementi per array: %f\n", i, time);
        //printf("%.2f \n", time);
    }
}

/* Funzione Main */
int main(int argc, char *argv[])
{
    srand(50); // come parametro si mette un SEED che serve per il pseudo-RNG
    int minLength = 3;
    int maxLength = 10;
    esperimento(minLength, maxLength); // esperimento() mi da n.Tempi per tentativo
                                       // dove n = (maxLength - minLength) / Step

    return 0;
}
