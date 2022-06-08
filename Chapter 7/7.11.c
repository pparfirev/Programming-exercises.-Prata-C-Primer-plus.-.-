/* �������� ��� Mail Order Grocery ������� �������� �� ���� $2.05 �� ����, ������
�� $1.15 �� ���� � ������� �� $1.09 �� ����. �� ���������� ������ �� ��������
�������� ������������� ������ 5% �� ������ �� ����� $100 � ����. ������� ����������
$6.50 �� �������� � ��������� ������ ����� � 5 ������ ��� �����, $14.00
�� ��������� � �������� ������ ����� �� 5 �� 20 ������ � $14.00 ���� $0.50 ��
������ ���� ��� �������� ������ � �����, ����������� 20 ������. ��������
���������, ������� ���������� �������� swi tch � ����� ���, ��� � ����� �� ����
� ������������ �������� ����������� ������� �������� ��� ��������� � ������;
� ����� �� ���� � � ��� ������ � ������; � ����� �� ���� � � ��� �������
� ������; � � ����� �� ���� q � ��������� ������� ������. ��������� ������
����� ���� ���� ����������� ������. �� ���� ���� ������������ ������ 4 �����
������ � ����� ������ ��� 5 ������ ������, ��������� ������ ��������
� ������ 9 ������ ������. ����� ��������� ������ ��������� ����� �������,
������, ���� ����, ������� �� �������� � ������ ����� ������. ����� ���������
������ ���������� ��� ���������� � �������: ��������� ����� ������, ����������
���������� ������, ��������� ������� ����������� ���� ������, �����
��������� ������, ������ (���� ����), ������� �� �������� � �������� ����� ������
� ������ ���� ������.*/
#include <stdio.h>
#include <stdlib.h>
#define AR_PR 2.05 // ���� �� ���� ���������
#define BE_PR 1.15 // �� ���� ������
#define CARR_PR 1.09 // �� ���� �������
#define DISC 0.95 // ������ 5% ��� ����� ������ �� 100$
#define DEL1 6.50 // ��������� �������� �� 5 ������
#define DEL2 14.00 // ��������� �������� �� 5 �� 20 ������

int main()
{
    char cat; // ��������� ������ ���������
    float art_w = 0, be_w = 0, car_w = 0; // ��� ����������� ������;
    float art_w_t = 0, be_w_t = 0, car_w_t = 0; // ����� ���������� ������
    float ar_pr_t = 0, be_pr_t = 0, car_pr_t = 0; // ����� ���� ���������� ���� ������
    float pr_t = 0; // ����� ���� ���� ������
    float veg_w = 0; // ����� ��� ���� ������
    float pr_t_d = 0; // ���� � ������ ��������
    printf("Choose the production:\n");
    printf("a.Artichoke\nb.Beet\nc.Carrot\nq.Go to checkout\n"); // ����� ���������
    while(scanf("%c", &cat) == 1) // ����������� ���� �������� ������ (getchar ������ ��� �� ������� ���������)
    {

        switch(cat)
        {
            case '\n': continue; // ���������� ���������� ������ ����� ������ � �������
            case 'a': printf("Enter the weight of artichoke you're need:\n"); // ���� ������� ��������
                      scanf("%f", &art_w);
                      art_w_t += art_w; // ����������� ���� ��� ��������� ������ ��������� (������������� ��� ������� �����)
                      printf("Choose the category or press q to checkout:\n");
                      continue;
            case 'b': printf("Enter the weight of beet you're need:\n"); // �����
                      scanf("%f", &be_w);
                      be_w_t += be_w;
                      printf("Choose the category or press q to checkout:\n");
                      continue;
            case 'c': printf("Enter the weight of carrot you're need:\n"); // �������
                      scanf("%f", &car_w);
                      car_w_t += car_w;
                      printf("Choose the category or press q to checkout:\n");
                      continue;
            case 'q': break; // ��� ������� q ������� � ����������
            default:  printf("You must enter the symbol from a to c or q.\n"); // ���� ������� ������������� ������� �� ������� �� �������� ������
                      printf("Choose the category or press q to checkout:\n");
                      continue;

        }
    printf("You're totally choose: %0.2f pounds of artichoke, %0.2f pounds of beet and %0.2f pounds of carrot\n", art_w_t, be_w_t, car_w_t);
    ar_pr_t = art_w_t * AR_PR; // ��������� ���������
    be_pr_t = be_w_t * BE_PR; // ��������� ������
    car_pr_t = car_w_t * CARR_PR; // ��������
    pr_t = ar_pr_t + be_pr_t + car_pr_t; // ����� ���� ������ �� ��������� ��������
    veg_w = art_w_t + be_w_t + car_w_t; // ����� ��� ������
    printf("Your order %0.2f$ for artichoke, %0.2f$ for beet, %0.2f$ fot carrot.\nTotal price without delivery %0.2f%$, total weight %0.2f pounds.\n", ar_pr_t, be_pr_t, car_pr_t, pr_t, veg_w);
    if(pr_t >= 100) // ���� ����� ������ ������ �� ����� 100$ ��� ����
    {
        pr_t = pr_t * DISC; // ������ 5%
        printf("Your discount is %0.2f$\n", pr_t * 0.05); //  ��������� � ������
    }
    if(veg_w <= 5) // ���� ��� 5 ������ � ������
        pr_t_d = pr_t + DEL1; // ����� �����
    else if(pr_t > 5 && pr_t <= 20) // ���� ��� �� 5 �� 20
        pr_t_d = pr_t + DEL2;
    else // ����� 20
        pr_t_d = pr_t + DEL2 + (0.5 * (veg_w - 20)); // ����� �����
    printf("Total price of your order is %0.2f$. (%0.2f$ for vegetables and %0.2f$ for delivery)\n", pr_t_d, pr_t, (pr_t_d - pr_t)); // ����� ���� ������
    printf("Choose the production:\n");
    printf("a.Artichoke\nb.Beet\nc.Carrot\nq.Go to checkout\n"); // ����� ���������
    }
    printf("Program Closed\n");
    return 0;
}
