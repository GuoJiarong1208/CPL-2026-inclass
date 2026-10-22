#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 每个非空行是一组分数。分数为 0..100 的整数，单行不超过缓冲区。 */
enum { LINE_CAP = 4096 };

static int process(FILE *in)
{
    char line[LINE_CAP];
    int line_no = 0;
    int case_no = 0;

    while (fgets(line, sizeof line, in) != NULL) {
        ++line_no;
        size_t len = strlen(line);
        if (len == sizeof line - 1 && line[len - 1] != '\n') {
            fprintf(stderr, "line %d is too long\n", line_no);
            return 1;
        }

        char *p = line;
        int count = 0;
        long sum = 0;
        for (;;) {
            while (isspace((unsigned char)*p)) {
                ++p;
            }
            if (*p == '\0') {
                break;
            }

            errno = 0;
            char *end;
            long score = strtol(p, &end, 10);
            if (end == p || errno == ERANGE || score < 0 || score > 100 ||
                (*end != '\0' && !isspace((unsigned char)*end))) {
                fprintf(stderr, "invalid score on line %d\n", line_no);
                return 1;
            }
            ++count;
            sum += score;
            p = end;
        }

        if (count != 0) {
            ++case_no;
            printf("case %d: count=%d sum=%ld avg=%.2f\n",
                   case_no, count, sum, (double)sum / count);
        }
    }

    if (ferror(in)) {
        perror("input read failed");
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    if (argc > 2) {
        fprintf(stderr, "usage: %s [input-file]\n", argv[0]);
        return 1;
    }

    FILE *in = stdin;
    if (argc == 2) {
        in = fopen(argv[1], "r");
        if (in == NULL) {
            perror(argv[1]);
            return 1;
        }
    }

    int result = process(in);
    if (in != stdin && fclose(in) != 0) {
        perror("input close failed");
        return 1;
    }
    return result;
}

