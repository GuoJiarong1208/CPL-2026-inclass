#include <stdio.h>

int main(int argc, char **argv)
{
    char fileName[] = "../cases/01-basic.in";

    FILE *in = fopen(fileName, "r");
    if (in == NULL) {
        return 1;
    }

    int score;

    while(fscanf(in, "%d", &score) != EOF){
        printf("%d\n", score);
    }

    return 0;
}
