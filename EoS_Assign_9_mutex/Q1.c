#include <stdio.h>
#include <pthread.h>

void* ap_sum(void* arg) {
    int *array = (int*)arg;  // Cast the void pointer back to the array type
    int i,j;
    
    // Calculate the sum of the array elements
    
    for(i=0; i<6; i++)
    {
        for(j=i+1; j<6; j++) { if(arg[i]>arg[j])
            {
                temp = arg[i];
                arg[i] = arg[j];
                arg[j] = temp;
            }
        }
    }
     printf("\nAfter Sorting ");
    for(i=0; i<6; i++)
    {
        printf("%d ",arg[i]);
    }
    
    //pthread_exit(NULL);
	}

int main() {
    pthread_t t1;
    int ap1[] = {1, 9, 3, 8, 5};  // Example array

    // Create the thread and pass the array as an argument
    pthread_create(&t1, NULL, ap_sum, (void*)ap1);

    // Wait for the thread to finish
   // pthread_join(t1, NULL);

    return 0;
}
