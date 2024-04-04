#include <stdio.h>

int ucln(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return ucln(b, a % b);
    }
}

int main()
{
    int a, b;
    printf("Nhập hai số nguyên a và b: ");
    scanf("%d%d", &a, &b);
    int ketqua = ucln(a, b);
    printf("Ước chung lớn nhất của %d và %d là: %d\n", a, b, ketqua);
    return 0;
}