#include <stdio.h>

int main(int argc, char *argv[])
{
    int nums[3];
    nums[1] = (int) argv[1][0] - '0';
    nums[2] = (int) argv[3][0] - '0';
    char operator = argv[2][0];

    if(operator == '+'){
        printf("%i\n", (nums[1] + nums[2]));
    } else if((int) nums[2] == '-'){
        printf("%i\n", (nums[1] - nums[2]));
    }
}