#include<stdio.h>
#include<stdlib.h>


void itoa (int n,char s[])
{
int i,j,sign;
int m,p;
if((sign=n)<0)//记录符号
n=-n;//使n成为正数
i=0;
do{
       s[i++]=n%10+'0';//取下一个数字
}
while ((n/=10)>0);//删除该数字
if(sign<0)
s[i++]='-';
s[i]='\0';

/*
for(j=i;j>=0;j--)//生成的数字是逆序的，所以要逆序输出
       printf("%c",s[j]);
printf("\n");
*/
for(m=0,p = i-1; m< p;m++,p--)//生成的数字是逆序的，所以要逆序输出
   { 
int a = s[m];
s[m] = s[p];
s[p] = a;


}
//printf("\n");
}


int
main(void)
{
    int number = 12345;
    char string[25];
    itoa(number,string);
    printf("integer = %d,\t string = %s\n",number,string);
    return EXIT_SUCCESS;
}
