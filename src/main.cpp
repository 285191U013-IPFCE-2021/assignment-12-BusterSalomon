
#include "..\include\duration.h"
#include <stdio.h>


// File for sandboxing and trying out code
int main(int argc, char **argv) {
    Duration TestDuration;
    int c_time = TestDuration.getDuration();

    printf ("%d", c_time);

    return 0;
}