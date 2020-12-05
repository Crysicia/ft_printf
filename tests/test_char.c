#include <stdio.h>
#include <stdlib.h>

void test_printf(int n)
{
    printf(" - Return: %d\n", n);
}

int main(int argc, char **argv)
{

    int value;
    
    value = (argc < 2) ? 'L' : *argv[argc - 1];

    test_printf(printf("c     |%c|", value));
    test_printf(printf("1c    |%1c|", value));
    test_printf(printf("5c    |%5c|", value));
    test_printf(printf("-1c   |%-1c|", value));
    test_printf(printf("-5c   |%-5c|", value));
    test_printf(printf("01c   |%01c|", value));
    test_printf(printf("05c   |%05c|", value));
    test_printf(printf(".c    |%.c|", value));
    test_printf(printf(".1c   |%.1c|", value));
    test_printf(printf(".5c   |%.5c|", value));
    test_printf(printf("0.c   |%0.c|", value));
    test_printf(printf("-.c   |%-.c|", value));
    test_printf(printf("1.c   |%1.c|", value));
    test_printf(printf("5.c   |%5.c|", value));
    test_printf(printf("1.1c  |%1.1c|", value));
    test_printf(printf("1.5c  |%1.5c|", value));
    test_printf(printf("5.1c  |%5.1c|", value));
    test_printf(printf("5.5c  |%5.5c|", value));
    test_printf(printf("5.4c  |%5.4c|", value));
    test_printf(printf("4.5c  |%4.5c|", value));
    test_printf(printf("05.1c |%05.1c|", value));
    test_printf(printf("05.5c |%05.5c|", value));
    test_printf(printf("05.4c |%05.4c|", value));
    test_printf(printf("04.5c |%04.5c|", value));
    test_printf(printf("-5.1c |%-5.1c|", value));
    test_printf(printf("-5.5c |%-5.5c|", value));
    test_printf(printf("-5.4c |%-5.4c|", value));
    test_printf(printf("-4.5c |%-4.5c|", value));

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = *argv[3];
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        printf("\n\n--- Star args ---\n");
        test_printf(printf("%dd    |%*c|", arg1, arg1, value));
        test_printf(printf("-%dd   |%-*c|", arg1, arg1, value));
        test_printf(printf("0%dd   |%0*c|", arg1, arg1, value));
        test_printf(printf(".%dd   |%.*c|", arg2, arg2, value));
        test_printf(printf("%d.d   |%*.c|", arg1, arg1, value));
        test_printf(printf("%d.%dd  |%*.*c|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("0%d.%dd |%0*.*c|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("-%d.%dd |%-*.*c|", arg1, arg2, arg1, arg2, value));
    }
    return 0;
}
