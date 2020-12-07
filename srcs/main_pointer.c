#include "../includes/nomallocs.h"

void test_printf(int n)
{
    ft_printf(" - Return: %d\n", n);
}

int main(int argc, char **argv)
{

    int value;
    
    value = (argc < 2) ? 42 : atoi(argv[argc - 1]);

    test_printf(ft_printf("p     |%p|", &value));
    test_printf(ft_printf("1p    |%1p|", &value));
    test_printf(ft_printf("5p    |%5p|", &value));
    test_printf(ft_printf("-1p   |%-1p|", &value));
    test_printf(ft_printf("-5p   |%-5p|", &value));
    test_printf(ft_printf("01p   |%01p|", &value));
    test_printf(ft_printf("05p   |%05p|", &value));
    test_printf(ft_printf(".p    |%.p|", &value));
    test_printf(ft_printf(".1p   |%.1p|", &value));
    test_printf(ft_printf(".5p   |%.5p|", &value));
    test_printf(ft_printf("0.p   |%0.p|", &value));
    test_printf(ft_printf("-.p   |%-.p|", &value));
    test_printf(ft_printf("1.p   |%1.p|", &value));
    test_printf(ft_printf("5.p   |%5.p|", &value));
    test_printf(ft_printf("1.1p  |%1.1p|", &value));
    test_printf(ft_printf("1.5p  |%1.5p|", &value));
    test_printf(ft_printf("5.1p  |%5.1p|", &value));
    test_printf(ft_printf("5.5p  |%5.5p|", &value));
    test_printf(ft_printf("5.4p  |%5.4p|", &value));
    test_printf(ft_printf("4.5p  |%4.5p|", &value));
    test_printf(ft_printf("05.1p |%05.1p|", &value));
    test_printf(ft_printf("05.5p |%05.5p|", &value));
    test_printf(ft_printf("05.4p |%05.4p|", &value));
    test_printf(ft_printf("04.5p |%04.5p|", &value));
    test_printf(ft_printf("-5.1p |%-5.1p|", &value));
    test_printf(ft_printf("-5.5p |%-5.5p|", &value));
    test_printf(ft_printf("-5.4p |%-5.4p|", &value));
    test_printf(ft_printf("-4.5p |%-4.5p|", &value));

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = atoi(argv[3]);
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        ft_printf("\n\n--- Star args ---\n");
        test_printf(ft_printf("%dp   |%*p|", arg1, arg1, &value));
        test_printf(ft_printf("-%dp  |%-*p|", arg1, arg1, &value));
        test_printf(ft_printf("0%dp  |%0*p|", arg1, arg1, &value));
        test_printf(ft_printf(".%dp  |%.*p|", arg2, arg2, &value));
        test_printf(ft_printf("%d.p  |%*.p|", arg1, arg1, &value));
        test_printf(ft_printf("%d.%dp |%*.*p|", arg1, arg2, arg1, arg2, &value));
        test_printf(ft_printf("0%d.%dp|%0*.*p|", arg1, arg2, arg1, arg2, &value));
        test_printf(ft_printf("-%d.%dp|%-*.*p|", arg1, arg2, arg1, arg2, &value));

        ft_printf("\n\n--- NULL args ---\n");
        test_printf(ft_printf("%dp   |%*p|", arg1, arg1, 0));
        test_printf(ft_printf("-%dp  |%-*p|", arg1, arg1, 0));
        test_printf(ft_printf("0%dp  |%0*p|", arg1, arg1, 0));
        test_printf(ft_printf(".%dp  |%.*p|", arg2, arg2, 0));
        test_printf(ft_printf("%d.p  |%*.p|", arg1, arg1, 0));
        test_printf(ft_printf("%d.%dp |%*.*p|", arg1, arg2, arg1, arg2, 0));
        test_printf(ft_printf("0%d.%dp|%0*.*p|", arg1, arg2, arg1, arg2, 0));
        test_printf(ft_printf("-%d.%dp|%-*.*p|", arg1, arg2, arg1, arg2, 0));
    }
    return 0;
}
