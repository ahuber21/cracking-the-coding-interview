#include <string>

// O(N x M) since every object needs to be checked

template <size_t rows, size_t cols>
void set_zero(int (&arr)[rows][cols])
{
    bool zero_rows[rows] = {false};
    bool zero_cols[cols] = {false};

    for (size_t row = 0; row < rows; ++row)
    {
        for (size_t col = 0; col < cols; ++col)
        {
            if (arr[row][col] == 0)
            {
                zero_rows[row] = true;
                zero_cols[col] = true;
            }
        }
    }

    for (size_t row = 0; row < rows; ++row)
    {
        if (zero_rows[row] == false)
            continue;
        for (size_t col = 0; col < cols; ++col)
        {
            arr[row][col] = 0;
        }
    }
    for (size_t col = 0; col < cols; ++col)
    {
        if (zero_cols[col] == false)
            continue;
        for (size_t row = 0; row < rows; ++row)
        {
            arr[row][col] = 0;
        }
    }
}

template <size_t rows, size_t cols>
void print_arr(int (&arr)[rows][cols])
{
    for (int j = 0; j < cols; ++j)
    {
        for (int i = 0; i < rows; ++i)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}

template <size_t rows, size_t cols>
void wrapper(int (&arr)[rows][cols])
{
    printf("Before:\n");
    print_arr(arr);

    set_zero(arr);

    printf("After:\n");
    print_arr(arr);
}

int main()
{

    int arr[4][5] = {
        {1, 2, 3, 4, 5},
        {1, 0, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 0, 5},
    };

    wrapper(arr);

    return 0;
}