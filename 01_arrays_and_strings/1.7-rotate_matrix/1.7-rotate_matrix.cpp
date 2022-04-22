/*
 *
 * Rotate a NxN matrix by 90 degrees
 * Can you do it inplace?
 */
#include <string>

// O(n^2) - touches every element in NxN matrix

template <size_t size>
void rotate(int (&arr)[size][size], size_t n)
{
    for (size_t layer = 0; layer < n / 2; ++layer)
    {
        int first = layer;
        int last = n - 1 - layer;
        for (size_t j = first; j < last; ++j)
        {
            int offset = j - first;

            // store top
            int tmp = arr[first][j];

            // left -> top
            arr[first][j] = arr[last - offset][first];

            // bottom -> left
            arr[last - offset][first] = arr[last][last - offset];

            // right -> bottom
            arr[last][last - offset] = arr[j][last];

            // top -> right
            arr[j][last] = tmp;
        }
    }

    // for (size_t layer = 1; layer <= n; ++layer)
    // {
    //     size_t start_x = , start_y = i;
    //     size_t current_x = i, current_y = i;
    //     size_t next_x = i, next_y = i;
    //     int tmp_val = arr[start_x][start_y];
    //     do
    //     {
    //         rotate_idx(next_x, next_y, i);

    //         tmp_val = arr[next_x][next_y];

    //         arr[next_x][next_y] = arr[current_x][current_y];

    //         current_x = next_x;
    //         current_y = next_y;

    //     } while (current_x != start_x && current_y != start_y);
    // }
}

template <size_t size>
void print_arr(int (&arr)[size][size], size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

template <size_t size>
void wrapper(int (&arr)[size][size], size_t n)
{
    printf("Before:\n");
    print_arr(arr, n);

    rotate(arr, n);

    printf("After:\n");
    print_arr(arr, n);
}

int main()
{
    int arr[2][2] = {
        {1, 2},
        {4, 3},
    };

    wrapper(arr, 2);

    int arr3[3][3] = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5},
    };

    wrapper(arr3, 3);

    int arr4[4][4] = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7},
    };

    wrapper(arr4, 4);

    return 0;
}