#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct studentTag {
    char name[10]; // ���ڹ迭�� �� �̸�
    int age;       // ���̸� ��Ÿ���� ������
    double gpa;    // ��� ������ ��Ÿ���� �Ǽ���
} student;

int main()
{
    student *s;  // ����ü�� ����Ű�� ������

    s = (student *)malloc(sizeof(student));

    if (s == NULL) {
        fprintf(stderr, "NULL. \n");
        exit(1);
    }

    strcpy(s->name, "Park");  // (*s).name���ε� �����ϴ�.
    s->age = 20;

    free(s);
}