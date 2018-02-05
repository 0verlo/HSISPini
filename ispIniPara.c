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
	char inputStrTmp[256];
	char *outStrTmp = NULL;

        char *paramSelect = "DAY_PARAM";
#if 0
	snprintf(inputStrTmp,sizeof(inputStrTmp),"%s:gAGainRangeMax",paramSelect);
	outStrTmp = iniparser_getstring(g_dictionary, inputStrTmp, NULL);
	if(NULL == outStrTmp){
		printf("get %s error\n",inputStrTmp);
		return PROC_FAILURE;
	}
	printf("result is %s\n",outStrTmp);

	snprintf(inputStrTmp,sizeof(inputStrTmp),"%s:gHighCCM",paramSelect);
	outStrTmp = iniparser_getstring(g_dictionary, inputStrTmp, NULL);
	if(NULL == outStrTmp){
		printf("get %s error\n",inputStrTmp);
		return PROC_FAILURE;
	}
	printf("result is %s\n",outStrTmp);
#endif
	snprintf(inputStrTmp,sizeof(inputStrTmp),"%s:g_gamma_table",paramSelect);
	outStrTmp = iniparser_getstring(g_dictionary, inputStrTmp, NULL);
	if(NULL == outStrTmp){
		printf("get %s error\n",inputStrTmp);
		return PROC_FAILURE;
	}
	printf("result is %s\n",outStrTmp);

            return PROC_SUCCESS;
}
