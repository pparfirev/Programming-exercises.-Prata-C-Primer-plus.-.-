/* ��������� ���������, ����������� ����������� ������� make_array() �
show_array (). ������� make_array() ��������� ��� ���������. ������ �������� -
��� ���������� ��������� � ������� �������� int, � ������ �������� � ��������,
������� ������ ���� ��������� ������� �������� �������. ��� �������
���������� malloc() ��� �������� ������� ����������� �������, �����������
������� �������� �������� �������� � ���������� ��������� �� ������. �������
show_array() ���������� ���������� ������� �� ������ ��������� � ������. */
// ��12-8.�
#include <stdio.h>
int *make_array(int elem, int val);
void show_array(const int ar[], int n);
int main(void)
{
    int *pa;
    int size;
    int value;
    printf("Enter number of elements: ");
    while(scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the value for initialization: " );
        scanf("%d", &value);
        pa = make_array(size, value);
        if(pa)
        {
        show_array(pa, size);
        free(pa);
        }
    printf("Enter the numbers of elements:  (<1 for exit): ");
    }
    printf("Program closed\n");
    return 0;
}
int *make_array(int elem, int val)
{
    int *pi;
    pi = (int *) malloc(elem * sizeof(int));
    for(int n = 0; n < elem; n++)
    {
        pi[n] = val;
        //printf("%d ", pi[n]);
    }
    return pi;
}
void show_array(const int ar[], int n)
{
    int el_count = 1; // Counting elements in line
    for(int j = 0; j < n; j++, el_count++)
    {
        printf("%d ", ar[j]);
        if(!(el_count % 8)) // If in line 8 elements
            printf("\n"); // print new line
    }
    printf("\n");
}
