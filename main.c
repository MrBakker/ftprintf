#include "ft_printf.h"
#include <stdio.h>
#include <time.h>

int main(void)
{
	char    ptr1[] = "Appeltaart is lekker bro %s someone else\n";
    char    *ptr2 = "HELLO";

    int count2 = ft_printf(ptr1, ptr2);

    // int count1 = printf(ptr1, ptr2);
    // if (count1 != count2)
        // {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d\nStd function:\t%d\n-\n", count2, count1);}
		
		
		
		// {
    // char    ptr1[] = "This %s is a |%                  ++   ---0000####>\\h---+H| [%%%%%%% ]% ++|| test\n%000---++++234563478.2345Q\n\nfgggh %%%----Hoi\n%      -####]geuigh\n%----++++534534.12\n";
    // char    *ptr2 = "HELLO";

    // int count1 = printf(ptr1, ptr2);
    // int count2 = ft_printf(ptr1, ptr2);
    // if (count1 != count2)
    //     {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d\nStd function:\t%d\n-\n", count2, count1);}
	// char *n = NULL;
	// count1 = printf("%10s|\n", n);
	// count2 = ft_printf("%10s|\n", n);
	// if (count1 != count2)
    //     {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d\nStd function:\t%d\n-\n", count2, count1);}
	// char format[] = "This i%2s... failed?\n";
	// char param[] = "s a test";
	// count1 = printf(format, param);
	// count2 = ft_printf(format, param);
	// if (count1 != count2)
    //     {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d\nStd function:\t%d\n-\n", count2, count1);}
	// char format2[] = "This is a number %#+15.8X... failed?\n";
	// int payload = 1;
	// count1 = printf(format2, payload);
	// count2 = ft_printf(format2, payload);
	// if (count1 != count2)
    //     {printf("\n-\nReturn value is incorrect :((\nYour function:\t%d\nStd function:\t%d\n-\n", count2, count1);}
}
