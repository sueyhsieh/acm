//3n+1

#include <stdio.h>
#include <string.h>

int main() {
    int n1;
    int n2;
    int n;
    int i;
    int max_cycle;
    int cycle;
    int temp;
    int a, b;

    while (scanf("%d%d", &a, &b) == 2) {
        max_cycle = 0;

        n1 = a;
        n2 = b;

        if(n1 > n2) {
            temp = n1;
            n1 = n2;
            n2 = temp;
        }

        for(i = n1; i <= n2; i++) {
            cycle = 1;
            n = i;
            while(n > 1) {
                if(n == 1) {
                    break;
                }

                if((n & 1) == 1) {
                    n = 3 * n + 1;
                } else {
                    n = n / 2;
                }

                cycle++;
            }

            if(cycle > max_cycle) {
                max_cycle = cycle;
            }
        }

        printf("%d %d %d\n", a, b, max_cycle);
    }

    system("pause");

    return 0;
}
