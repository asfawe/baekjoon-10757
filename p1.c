#include <stdio.h>
#include <string.h>

int reverse(char arr[])
{
    int i;
    int len = strlen(arr);
    for (i = 0; i < len / 2; i++)
    {
        char temp = arr[i];
        arr[i] = arr[len - 1 - i];
        arr[len - 1 - i] = temp;
    }

    return 0;
}

int main()
{

    char a[10002] = {0};
    char b[10002] = {0};
    char r[10003] = {0};
    int i;
    int len = 0;
    int sum; // 각 인덱스에 있는 숫자 끼리 더해준 값을 저장해주는 변수.
    int carry = 0;

    scanf("%s %s", a, b);
    reverse(a);
    reverse(b);

    if (strlen(a) > strlen(b)) // 큰수 기준
    {
        len = strlen(a);
    }
    else
    {
        len = strlen(b);
    }

    for (i = 0; i < len; i++)
    {
        sum = a[i] - '0' + b[i] - '0' + carry;

        while (sum < 0)
        {
            sum += '0';
        }
        if (sum > 9)
        {
            carry = 1;
        }
        else
        {
            carry = 0;
        }

        r[i] = sum % 10 + '0';
        // printf("%d", sum);
    }
    if (carry == 1) // 만약 마지막 숫자가 반올림을 해야 하는 상황을 맞이했다면... for문에서 작업을 못 해주기 때문에 이쪽에서 작업을 해주는 것이다.
    {
        r[len] = '1';
    }
    reverse(r);
    printf("%s", r);

    return 0;
}
