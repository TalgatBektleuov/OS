#include <stdio.h> 
#include <string.h>
int main(int argc, char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "Usage:./Exercise3_o n\n");
        return 1;
    }
    
    int n;
    sscanf(argv[1], "%d", &n);
    
    for (int i = 0; i < n; i++) {
      
        for (int j = 1; j <= 2 * n - 1; j++) {
           
            if (j >= n - i && j <= n + i) {
                printf("%c", '*');
            }
            else {
                printf("%s", " ");
            }

        }
        printf("\n");
    }
    return 0;
}