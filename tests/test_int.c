#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{

    int value;
    
    value = (argc < 2) ? 42 : atoi(argv[argc - 1]);

    printf("d     |%d|\n", value);
    printf("1d    |%1d|\n", value);
    printf("5d    |%5d|\n", value);
    printf("-1d   |%-1d|\n", value);
    printf("-5d   |%-5d|\n", value);
    printf("01d   |%01d|\n", value);
    printf("05d   |%05d|\n", value);
    printf(".d    |%.d|\n", value);
    printf(".1d   |%.1d|\n", value);
    printf(".5d   |%.5d|\n", value);
    printf("0.d   |%0.d|\n", value);
    printf("-.d   |%-.d|\n", value);
    printf("1.d   |%1.d|\n", value);
    printf("5.d   |%5.d|\n", value);
    printf("1.1d  |%1.1d|\n", value);
    printf("1.5d  |%1.5d|\n", value);
    printf("5.1d  |%5.1d|\n", value);
    printf("5.5d  |%5.5d|\n", value);
    printf("5.4d  |%5.4d|\n", value);
    printf("4.5d  |%4.5d|\n", value);
    printf("05.1d |%05.1d|\n", value);
    printf("05.5d |%05.5d|\n", value);
    printf("05.4d |%05.4d|\n", value);
    printf("04.5d |%04.5d|\n", value);
    printf("-5.1d |%-5.1d|\n", value);
    printf("-5.5d |%-5.5d|\n", value);
    printf("-5.4d |%-5.4d|\n", value);
    printf("-4.5d |%-4.5d|\n", value);

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = atoi(argv[3]);
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        printf("\n\n--- Star args ---\n");
        printf("%dd    |%*d|\n", arg1, arg1, value);
        printf("-%dd   |%-*d|\n", arg1, arg1, value);
        printf("0%dd   |%0*d|\n", arg1, arg1, value);
        printf(".%dd   |%.*d|\n", arg2, arg2, value);
        printf("%d.d   |%*.d|\n", arg1, arg1, value);
        printf("%d.%dd  |%*.*d|\n", arg1, arg2, arg1, arg2, value);
        printf("0%d.%dd |%0*.*d|\n", arg1, arg2, arg1, arg2, value);
        printf("-%d.%dd |%-*.*d|\n", arg1, arg2, arg1, arg2, value);
    }
    return 0;
}
