#include <stdio.h>
#include <stdlib.h>

//short int frequency_table[10000000];
int main()
{
    int len_array = 0;
    long long int reqd_strength = 0;

    scanf("%d", &len_array);

    int num[len_array + 7];

    for (int i = 0; i < len_array; i++)
    {
        scanf("%d", &num[i]);
    }
    scanf("%lld", &reqd_strength);

    long int matrix_with_reqd_strength = 0;

    for (long long int side_len_kool = 1; side_len_kool <= len_array; side_len_kool++)
    {
        if (reqd_strength % side_len_kool != 0)
        {
            continue;
        }
        short int *frequency_table = (short int *)(calloc(10000007, (sizeof(short int))));

        int side_len_strength = len_array - side_len_kool + 1;
        long long int sum[side_len_strength + 7];
        sum[0] = 0;
        for (int i = 0; i < side_len_kool; i++)
        {
            sum[0] += num[i];
        }
        frequency_table[(sum[0] - 1) % 10000007]++;

        for (int i = 1; i < side_len_strength; i++)
        {
            sum[i] = 0;
            sum[i] = sum[i - 1] + num[i + side_len_kool - 1] - num[i - 1];
            frequency_table[sum[i] - 1]++;
        }

        long long int IDK_what_t0_name_this = reqd_strength / side_len_kool;

        for (int i = 0; i < side_len_strength; i++)
        {
            int key = IDK_what_t0_name_this - sum[i];

            if (key < 0)
            {
                continue;
            }

            matrix_with_reqd_strength += frequency_table[(key - 1) % 10000007];
        }
        free(frequency_table);
    }
    printf("%ld\n", matrix_with_reqd_strength);
    return 0;
}
