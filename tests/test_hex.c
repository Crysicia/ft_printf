#include <stdio.h>
#include <stdlib.h>

void test_printf(int n)
{
    printf(" - Return: %d\n", n);
}

int main(int argc, char **argv)
{

    int value;
    
    value = (argc < 2) ? 42 : atoi(argv[argc - 1]);

    test_printf(printf("x     |%x|", value));
    test_printf(printf("1x    |%1x|", value));
    test_printf(printf("5x    |%5x|", value));
    test_printf(printf("-1x   |%-1x|", value));
    test_printf(printf("-5x   |%-5x|", value));
    test_printf(printf("01x   |%01x|", value));
    test_printf(printf("05x   |%05x|", value));
    test_printf(printf(".x    |%.x|", value));
    test_printf(printf(".1x   |%.1x|", value));
    test_printf(printf(".5x   |%.5x|", value));
    test_printf(printf("0.x   |%0.x|", value));
    test_printf(printf("-.x   |%-.x|", value));
    test_printf(printf("1.x   |%1.x|", value));
    test_printf(printf("5.x   |%5.x|", value));
    test_printf(printf("1.1x  |%1.1x|", value));
    test_printf(printf("1.5x  |%1.5x|", value));
    test_printf(printf("5.1x  |%5.1x|", value));
    test_printf(printf("5.5x  |%5.5x|", value));
    test_printf(printf("5.4x  |%5.4x|", value));
    test_printf(printf("4.5x  |%4.5x|", value));
    test_printf(printf("05.1x |%05.1x|", value));
    test_printf(printf("05.5x |%05.5x|", value));
    test_printf(printf("05.4x |%05.4x|", value));
    test_printf(printf("04.5x |%04.5x|", value));
    test_printf(printf("-5.1x |%-5.1x|", value));
    test_printf(printf("-5.5x |%-5.5x|", value));
    test_printf(printf("-5.4x |%-5.4x|", value));
    test_printf(printf("-4.5x |%-4.5x|", value));

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = atoi(argv[3]);
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        printf("\n\n--- Star args ---\n");
        test_printf(printf("%dx   |%*x|", arg1, arg1, value));
        test_printf(printf("-%dx  |%-*x|", arg1, arg1, value));
        test_printf(printf("0%dx  |%0*x|", arg1, arg1, value));
        test_printf(printf(".%dx  |%.*x|", arg2, arg2, value));
        test_printf(printf("%d.x  |%*.x|", arg1, arg1, value));
        test_printf(printf("%d.%dx |%*.*x|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("0%d.%dx|%0*.*x|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("-%d.%dx|%-*.*x|", arg1, arg2, arg1, arg2, value));
    }
    return 0;
}
