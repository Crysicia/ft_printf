#include <stdio.h>
#include <stdlib.h>

void test_printf(int n)
{
    printf(" - Return: %d\n", n);
}

int main(int argc, char **argv)
{

    char *value;
    
    value = (argc < 2) ? "Bonjour tout le monde" : argv[argc - 1];

    test_printf(printf("s     |%s|", value));
    test_printf(printf("1s    |%1s|", value));
    test_printf(printf("5s    |%5s|", value));
    test_printf(printf("-1s   |%-1s|", value));
    test_printf(printf("-5s   |%-5s|", value));
    test_printf(printf("01s   |%01s|", value));
    test_printf(printf("05s   |%05s|", value));
    test_printf(printf(".s    |%.s|", value));
    test_printf(printf(".1s   |%.1s|", value));
    test_printf(printf(".5s   |%.5s|", value));
    test_printf(printf("0.s   |%0.s|", value));
    test_printf(printf("-.s   |%-.s|", value));
    test_printf(printf("1.s   |%1.s|", value));
    test_printf(printf("5.s   |%5.s|", value));
    test_printf(printf("1.1s  |%1.1s|", value));
    test_printf(printf("1.5s  |%1.5s|", value));
    test_printf(printf("5.1s  |%5.1s|", value));
    test_printf(printf("5.5s  |%5.5s|", value));
    test_printf(printf("5.4s  |%5.4s|", value));
    test_printf(printf("4.5s  |%4.5s|", value));
    test_printf(printf("05.1s |%05.1s|", value));
    test_printf(printf("05.5s |%05.5s|", value));
    test_printf(printf("05.4s |%05.4s|", value));
    test_printf(printf("04.5s |%04.5s|", value));
    test_printf(printf("-5.1s |%-5.1s|", value));
    test_printf(printf("-5.5s |%-5.5s|", value));
    test_printf(printf("-5.4s |%-5.4s|", value));
    test_printf(printf("-4.5s |%-4.5s|", value));

    printf("\n\n--- NULL value ---\n");
    test_printf(printf("s     |%s|", NULL));
    test_printf(printf("1s    |%1s|", NULL));
    test_printf(printf("5s    |%5s|", NULL));
    test_printf(printf("-1s   |%-1s|", NULL));
    test_printf(printf("-5s   |%-5s|", NULL));
    test_printf(printf("01s   |%01s|", NULL));
    test_printf(printf("05s   |%05s|", NULL));
    test_printf(printf(".s    |%.s|", NULL));
    test_printf(printf(".1s   |%.1s|", NULL));
    test_printf(printf(".5s   |%.5s|", NULL));
    test_printf(printf("0.s   |%0.s|", NULL));
    test_printf(printf("-.s   |%-.s|", NULL));
    test_printf(printf("1.s   |%1.s|", NULL));
    test_printf(printf("5.s   |%5.s|", NULL));
    test_printf(printf("1.1s  |%1.1s|", NULL));
    test_printf(printf("1.5s  |%1.5s|", NULL));
    test_printf(printf("5.1s  |%5.1s|", NULL));
    test_printf(printf("5.5s  |%5.5s|", NULL));
    test_printf(printf("5.4s  |%5.4s|", NULL));
    test_printf(printf("4.5s  |%4.5s|", NULL));
    test_printf(printf("05.1s |%05.1s|", NULL));
    test_printf(printf("05.5s |%05.5s|", NULL));
    test_printf(printf("05.4s |%05.4s|", NULL));
    test_printf(printf("04.5s |%04.5s|", NULL));
    test_printf(printf("-5.1s |%-5.1s|", NULL));
    test_printf(printf("-5.5s |%-5.5s|", NULL));
    test_printf(printf("-5.4s |%-5.4s|", NULL));
    test_printf(printf("-4.5s |%-4.5s|", NULL));

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = argv[3];
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        printf("\n\n--- Star args ---\n");
        test_printf(printf("%dd    |%*s|", arg1, arg1, value));
        test_printf(printf("-%dd   |%-*s|", arg1, arg1, value));
        test_printf(printf("0%dd   |%0*s|", arg1, arg1, value));
        test_printf(printf(".%dd   |%.*s|", arg2, arg2, value));
        test_printf(printf("%d.d   |%*.s|", arg1, arg1, value));
        test_printf(printf("%d.%dd  |%*.*s|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("0%d.%dd |%0*.*s|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("-%d.%dd |%-*.*s|", arg1, arg2, arg1, arg2, value));
    }
    return 0;
}
