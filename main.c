#include<stdio.h>
//#include <stdbool.h>
//#define n 6      //��Ʊ����ֵ�����1����Ϊ��Ҫ�����ֵΪ0����Ʊ
//#define m 4      //�����m����Ʊ
int money = 0, tmoney = 0;//money���������������;  tmoney�ǹ���ֵ
int m = 0, n = 0;
printf("�������ܹ��м�����Ʊ��");
scanf("%d", &n);
n = n + 1;
int a[n];
a[0] = 0;
printf("�����뼸����Ʊ����ֵ��");
for (i = 1; i < n; i++) {
    scanf("%d", &a[i]);
};
printf("�����������������Ʊ��");
scanf("%d", &m);
bool flag;

void traceback(int t) {
    if (t == m) {
        if (tmoney == money + 1)
            flag = true;
        return;
    }
    for (int i = 0; i < n; i++) {
        tmoney += a[i];
        if (tmoney <= money + 1)
            traceback(t + 1);
        tmoney -= a[i];
    }
}

int main() {
    while (true) { //���ֵΪ���٣���֪�����費��ѭ��ȷ��
        flag = false;
        traceback(0);     //t������Ʊ������
        if (flag)
            money++;
        else
            break;
    }
    printf("%d", money);
    return 0;
}
