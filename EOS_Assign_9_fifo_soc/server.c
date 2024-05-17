
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fdr,fdw,a,b,sum;
	
	fdr = open("/tmp/parag_fifo", O_RDONLY);
    printf("waiting for data...\n");
	
    read(fdr, &a, sizeof(int));
    read(fdr, &b, sizeof(int));
    printf("reading data...\n\n");
    printf("A -> %d\t B -> %d\n",a,b);

    sum = a+b;

    fdw = open("/tmp/parag_fifo", O_WRONLY);
    printf("returning data...\n");

    write(fdw, &sum, sizeof(int));

	close(fdr);
    close(fdw);

	return 0;
}
