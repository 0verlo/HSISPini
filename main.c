/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Apr 2017 02:42:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include"ispIniPara.h"

void main()
{
    int procState = 0;
    procState = iniFileLoad("info.ini");
    procState = iniSetAE_cfg();
    iniFileFree();
    printf("hello\n");

    unsigned int testNum = 0x10000;
    printf("%d\n",testNum);

    int i;
    for(i = 0;i < 10;i++)
    {
        printf("%d",i);
    }
    i = 0;
    while(i < 10)
    {
        i++;
        printf("%d",i);
    }
    i = 0;
    do
    {
        i++;
        printf("%d",i);
    }while(i<10);
}
