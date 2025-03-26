#include <stdio.h>
#include <math.h>

int isPrime(int n, int divisor) {
    if (n < 2) {
        return 0; // Không phải số nguyên tố
    }
    if (divisor == 1) {
        return 1; // Là số nguyên tố
    }
    if (n % divisor == 0) {
        return 0; // Không phải số nguyên tố
    }
    return isPrime(n, divisor - 1);
}

int isPrimeNumber(int n) {
    return isPrime(n, (int)sqrt(n));
}

int main() {
    int number;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &number);

    if (isPrimeNumber(number)) {
        printf("%d la so nguyen to\n", number);
    } else {
        printf("%d khong phai la so nguyen to\n", number);
    }

    return 0;
}