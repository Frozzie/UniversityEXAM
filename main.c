#include <errno.h> 
#include <stdio.h> 
#include <string.h> 

typedef struct _data1
{
    int arr_int[10];
    int num_int;
} data1;

#define not_in_mem 12

void func1 (data1 *data, int index, int val)
{
    
    if (index >= data->num_int)
    {
        errno = not_in_mem; // Not in allocated memory
    }
    else
    {
        data->arr_int[index] = val;
        errno = 0; // err reset
    }
}

int main ()
{
    data1 s;
    int i = 8;
    s.num_int = 10;

    while(i < 12)
    {
        func1 (&s, i++, 21);

        printf("Value of errno: %d\n", errno);
        perror("Message from perror");
    }
    
    printf("\n");

    while(i > 7)
    {
        func1 (&s, i--, 21);

        printf("Value of errno: %d\n", errno);
        perror("Message from perror");
    }

    return 0;
}