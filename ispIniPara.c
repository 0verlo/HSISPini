/*************************************************************************
	> File Name: ispIniPara.c
	> Author: 
	> Mail: 
	> Created Time: Thu 27 Apr 2017 02:53:49 PM CST
 ************************************************************************/

#include<stdio.h>
#include"ispIniPara.h"

#include"src/iniparser.h"

static dictionary* g_dictionary = NULL;

int iniFileLoad(const char *iniName)
{
	if(NULL != g_dictionary){
		g_dictionary = NULL;
	}else{
		g_dictionary = iniparser_load(iniName);
		if(NULL == g_dictionary){
			printf("%s load failed\n",iniName);
			return PROC_FAILURE;
		}
	}
	return PROC_SUCCESS;
}

void iniFileFree()
{
	if(NULL != g_dictionary){
		iniparser_freedict(g_dictionary);
	}
	g_dictionary = NULL;
}

int iniSetAE_cfg()
{
    int procState = 0;
	char inStrTmp[128];
	char *outStrTmp = NULL;

	snprintf(inStrTmp,sizeof(inStrTmp),"ExposureAttr_day:gColorAGainRangeMax");
	outStrTmp = iniparser_getstring(g_dictionary, inStrTmp, "-1");
	if(NULL == outStrTmp){
		printf("get gColorAGainRangeMax error\n");
		return PROC_FAILURE;
	}
	printf("result is %s\n",outStrTmp);

	return PROC_SUCCESS;
}
