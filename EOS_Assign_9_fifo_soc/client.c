
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// client
int main() {
	int fdw,fdr,a,b,sum;
	
	fdw = open("/tmp/parag_fifo", O_WRONLY);
	
		printf("Enter numbers for addition\n");
		printf("A -> ");
        scanf("%d",&a);
        printf("B -> ");
        scanf("%d",&b);

		write(fdw, &a, sizeof(int));//write a to server process

		write(fdw, &b, sizeof(int));//write b to server process

	fdr= open("/tmp/parag_fifo", O_RDONLY);
		printf("waiting for data...\n");

		read(fdr,&sum, sizeof(int));//read the result from server process
		printf("SUM -> %d\n", sum);

	

	close(fdw);
	close(fdr);
	return 0;
}
