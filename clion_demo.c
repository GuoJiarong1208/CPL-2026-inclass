#include <stdio.h>

int main(void)
{
//    if (freopen("../cases/01-basic.in", "r", stdin) == NULL) {
//        return 1;
//    }

    int score;
    while(scanf("%d", &score) != EOF) {
        printf("%d\n", score);
    }

    return 0;
}
