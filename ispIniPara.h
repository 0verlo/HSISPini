/*************************************************************************
	> File Name: ispIniPara.h
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Apr 2017 02:49:20 PM CST
 ************************************************************************/

#ifndef _ISPINIPARA_H
#define _ISPINIPARA_H

#define PROC_SUCCESS 1
#define PROC_FAILURE 0

#include"src/iniparser.h"

int iniFileLoad(const char *iniName);
void iniFileFree();

int iniSetAE_cfg();

#endif
