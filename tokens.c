#include <stdio.h>
enum { MAX_NUMBERS = 100 };

int main(void)
{
    int numbers[MAX_NUMBERS];
    int count = 0;
    int value;
    int result;
    long long sum = 0;

    while ((result = scanf("%d", &value)) == 1) {
        if (count == MAX_NUMBERS) {
            fputs("too many numbers\n", stderr);
            return 1;
        }
        numbers[count++] = value;
    }

    for(int i = 0; i < count; ++i) {
        printf("%d\n", numbers[i]);
        sum += numbers[i];
    }
    printf("%d", sum);
    return 0;
}
