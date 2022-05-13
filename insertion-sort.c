#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* InsertionSort Algorithm */
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

/* Singolo Experiment*/
float singoloEsperimento(int len, int maxInstance)
{
    float timeTot = 0;
    for (int i = 0; i < maxInstance; i++)
    {
        float timeStart, timeEnd, timeElapsed;
        int A[len];

        for (int j = 0; j < len; j++)    // Generator Array of casual numbers:
        {                                // through rand()%N, it generates a number between 0 e N-1
            A[j] = 1 + rand() % 1000000; // and i put this number into the array
        }

        printf("Non ordinato\n");
        for (int j = 0; j < len; j++)    
        {                                
            printf("%d\n", A[j]); 
        }

        timeStart = clock(); //start time
        InsertionSort(A, len);
        timeEnd = clock(); //end time

        printf("ordinato\n");
        for (int j = 0; j < len; j++)    
        {                                
            printf("%d\n", A[j]); 
        }
        timeElapsed = timeEnd - timeStart; //time passed
        timeTot = timeTot + timeElapsed;
    }
    return timeTot / maxInstance;
}

/* INSERTION SORT Experiment */
void esperimento(int minLen, int maxLen)
{
    int maxInstances = 2; // number of instance for each attempt 
    int STEP = 1;         // increments elements of array one-by-one                        
    float time;

    for (int i = minLen; i < maxLen; i = i + STEP)
    {
        time = singoloEsperimento(i, maxInstances);
        printf("Tempo per %d elementi per array: %f\n", i, time);
        //printf("%.2f \n", time);
    }
}

/* MAIN FUNCTION */
int main(int argc, char *argv[])
{
    // as seed i set 50
    srand(50);
    int minLength = 0;
    int maxLength = 1000;
    esperimento(minLength, maxLength); // esperimento() gives me n Time for attempt
                                       // where n = (maxLength - minLength) / Step

    return 0;
}
