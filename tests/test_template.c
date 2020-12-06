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

    test_printf(printf("<flag>     |%<flag>|", value));
    test_printf(printf("1<flag>    |%1<flag>|", value));
    test_printf(printf("5<flag>    |%5<flag>|", value));
    test_printf(printf("-1<flag>   |%-1<flag>|", value));
    test_printf(printf("-5<flag>   |%-5<flag>|", value));
    test_printf(printf("01<flag>   |%01<flag>|", value));
    test_printf(printf("05<flag>   |%05<flag>|", value));
    test_printf(printf(".<flag>    |%.<flag>|", value));
    test_printf(printf(".1<flag>   |%.1<flag>|", value));
    test_printf(printf(".5<flag>   |%.5<flag>|", value));
    test_printf(printf("0.<flag>   |%0.<flag>|", value));
    test_printf(printf("-.<flag>   |%-.<flag>|", value));
    test_printf(printf("1.<flag>   |%1.<flag>|", value));
    test_printf(printf("5.<flag>   |%5.<flag>|", value));
    test_printf(printf("1.1<flag>  |%1.1<flag>|", value));
    test_printf(printf("1.5<flag>  |%1.5<flag>|", value));
    test_printf(printf("5.1<flag>  |%5.1<flag>|", value));
    test_printf(printf("5.5<flag>  |%5.5<flag>|", value));
    test_printf(printf("5.4<flag>  |%5.4<flag>|", value));
    test_printf(printf("4.5<flag>  |%4.5<flag>|", value));
    test_printf(printf("05.1<flag> |%05.1<flag>|", value));
    test_printf(printf("05.5<flag> |%05.5<flag>|", value));
    test_printf(printf("05.4<flag> |%05.4<flag>|", value));
    test_printf(printf("04.5<flag> |%04.5<flag>|", value));
    test_printf(printf("-5.1<flag> |%-5.1<flag>|", value));
    test_printf(printf("-5.5<flag> |%-5.5<flag>|", value));
    test_printf(printf("-5.4<flag> |%-5.4<flag>|", value));
    test_printf(printf("-4.5<flag> |%-4.5<flag>|", value));

    if (argc == 4)
    {
        int arg1;
        int arg2;

        value = atoi(argv[3]);
        arg1 = atoi(argv[1]);
        arg2 = atoi(argv[2]);

        printf("\n\n--- Star args ---\n");
        test_printf(printf("%d<flag>   |%*<flag>|", arg1, arg1, value));
        test_printf(printf("-%d<flag>  |%-*<flag>|", arg1, arg1, value));
        test_printf(printf("0%d<flag>  |%0*<flag>|", arg1, arg1, value));
        test_printf(printf(".%d<flag>  |%.*<flag>|", arg2, arg2, value));
        test_printf(printf("%d.<flag>  |%*.<flag>|", arg1, arg1, value));
        test_printf(printf("%d.%d<flag> |%*.*<flag>|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("0%d.%d<flag>|%0*.*<flag>|", arg1, arg2, arg1, arg2, value));
        test_printf(printf("-%d.%d<flag>|%-*.*<flag>|", arg1, arg2, arg1, arg2, value));
    }
    return 0;
}
