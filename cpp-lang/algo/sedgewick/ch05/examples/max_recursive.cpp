#include <iostream>

int max(int values[], int left, int right)
{
    if (left == right)
        return values[left];

    int mid = (left + right) / 2;
    int val1 = max(values, left, mid);
    int val2 = max(values, mid + 1, right);

    return (val1 < val2) ? val2 : val1;
}

int main()
{
    int values[] = {
        12, 45, 89, 88, 78,
        56, 22, 33, 45, 87,
        56, 49, 55, 23, 77,
        63, 68, 54, 78, 69,
        56, 12, 39, 82, 18
    };

    std::cout << max(values, 0, 24) << std::endl;

    return 0;
}