#include "../includes/nomallocs.h"

void test_printf(int n)
{
    ft_printf(" - Return: %d\n", n);
}

int main(int argc, char **argv)
{

    int value;
    
    value = (argc < 2) ? 42 : atoi(argv[argc - 1]);

    test_printf(ft_printf("d     |%d|", value));
    test_printf(ft_printf("1d    |%1d|", value));
    test_printf(ft_printf("5d    |%5d|", value));
    test_printf(ft_printf("-1d   |%-1d|", value));
    test_printf(ft_printf("-5d   |%-5d|", value));
    test_printf(ft_printf("01d   |%01d|", value));
    test_printf(ft_printf("05d   |%05d|", value));
    test_printf(ft_printf(".d    |%.d|", value));
    test_printf(ft_printf(".1d   |%.1d|", value));
    test_printf(ft_printf(".5d   |%.5d|", value));
    test_printf(ft_printf("0.d   |%0.d|", value));
    test_printf(ft_printf("-.d   |%-.d|", value));
    test_printf(ft_printf("1.d   |%1.d|", value));
    test_printf(ft_printf("5.d   |%5.d|", value));
    test_printf(ft_printf("1.1d  |%1.1d|", value));
    test_printf(ft_printf("1.5d  |%1.5d|", value));
    test_printf(ft_printf("5.1d  |%5.1d|", value));
    test_printf(ft_printf("5.5d  |%5.5d|", value));
    test_printf(ft_printf("5.4d  |%5.4d|", value));
    test_printf(ft_printf("4.5d  |%4.5d|", value));
    test_printf(ft_printf("05.1d |%05.1d|", value));
    test_printf(ft_printf("05.5d |%05.5d|", value));
    test_printf(ft_printf("05.4d |%05.4d|", value));
    test_printf(ft_printf("04.5d |%04.5d|", value));
    test_printf(ft_printf("-5.1d |%-5.1d|", value));
    test_printf(ft_printf("-5.5d |%-5.5d|", value));
    test_printf(ft_printf("-5.4d |%-5.4d|", value));
    test_printf(ft_printf("-4.5d |%-4.5d|", value));

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = atoi(argv[3]);
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        ft_printf("\n\n--- Star args ---\n");
        test_printf(ft_printf("%dd    |%*d|", arg1, arg1, value));
        test_printf(ft_printf("-%dd   |%-*d|", arg1, arg1, value));
        test_printf(ft_printf("0%dd   |%0*d|", arg1, arg1, value));
        test_printf(ft_printf(".%dd   |%.*d|", arg2, arg2, value));
        test_printf(ft_printf("%d.d   |%*.d|", arg1, arg1, value));
        test_printf(ft_printf("%d.%dd  |%*.*d|", arg1, arg2, arg1, arg2, value));
        test_printf(ft_printf("0%d.%dd |%0*.*d|", arg1, arg2, arg1, arg2, value));
        test_printf(ft_printf("-%d.%dd |%-*.*d|", arg1, arg2, arg1, arg2, value));
    }
    return 0;
}
