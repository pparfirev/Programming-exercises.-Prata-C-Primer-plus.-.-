#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
/* Экспериментальным путем выясните, как ваша система обрабатывает переполнение
при выполнении операций над целыми числами и над числами с плавающей
запятой, а также потерю значимости при выполнении операций над числами
с плавающей запятой; т.е. напишите программу, в которой присутствуют
такие проблемы. (Для получения сведений о наибольших и наименьших значениях
просмотрите обсуждение limits.h и float.h в главе 4.) */

int main()
{
    printf("Max value of int is %d \n", INT_MAX);
    int int_overflow = INT_MAX + 1;
    printf("Int overflow is %d \n", int_overflow);
    printf("Max value of float is %f \n", FLT_MAX);
    float float_overflow = FLT_MAX +500000;
    printf("Float overflow is %f \n", float_overflow);
    float n1 = 2.74;
    float n2 = 3.56;
    int sum = n1 + n2;
    printf("Wrong summary is %d \n", sum);
    return 0;
}
