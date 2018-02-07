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
static int intGetTable[512]={0};

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

int iniStringSplit2Int(char *pInputString)
{
        char* pReader;
        char tmpStr[10] = {0};
        int valueConter = 0;
        int strConter = 0;
        int hexMark = 0;

        printf("mark1\n");
        pReader = pInputString;
        while(NULL != pReader)
        {
                if((',' != *pReader)&&('|' != *pReader)&&('\0' != *pReader))
                {
                        if(('X' == *pReader)||('x' == *pReader))
                        {
                                hexMark = 1; 
                        }
                        tmpStr[strConter] = *pReader; 
                        strConter++;
                }
                else if((' ' == *pReader))
                {}
                else
                {
                        tmpStr[strConter] = '\0';
                        if(0 != hexMark)
                        {
                                intGetTable[valueConter] = (int)strtol(tmpStr,NULL,16);
                        }
                        else
                        {
                                intGetTable[valueConter] = atoi(tmpStr);
                        }
                        printf("numbget:%d\n",intGetTable[valueConter]);
                        memset(tmpStr,0,(strConter+1)*sizeof(char));
                        strConter = 0;
                        hexMark = 0;
                        valueConter++;
                }

                if('\0' == *pReader)
                    break;
                pReader++;
        }
        return valueConter;
}

int iniSetAE_cfg()
{
        int i = 0;
        int procState = 0;
        int counterI = 0;
	char inputStrTmp[256];
	int  outIntTmp = -1;
	char *outStrTmp = NULL;

        char *paramSelect = "DAY_PARAM";
#if 1 
	snprintf(inputStrTmp,sizeof(inputStrTmp),"%s:gAGainRangeMax",paramSelect);
	outIntTmp = iniparser_getint(g_dictionary, inputStrTmp, -1);
	if(-1 == outIntTmp){
		printf("get %s error\n",inputStrTmp);
		return PROC_FAILURE;
	}
	printf("result is %d\n",outIntTmp);

	snprintf(inputStrTmp,sizeof(inputStrTmp),"%s:gHighCCM",paramSelect);
	outStrTmp = iniparser_getstring(g_dictionary, inputStrTmp, NULL);
	if(NULL == outStrTmp){
		printf("get %s error\n",inputStrTmp);
		return PROC_FAILURE;
	}
        counterI = iniStringSplit2Int(outStrTmp);
        for(i = 0;i < counterI;i++)
        {
                printf("result is %d\n",intGetTable[i]);
        }

	snprintf(inputStrTmp,sizeof(inputStrTmp),"%s:gSharpenUd",paramSelect);
	outStrTmp = iniparser_getstring(g_dictionary, inputStrTmp, NULL);
	if(NULL == outStrTmp){
		printf("get %s error\n",inputStrTmp);
		return PROC_FAILURE;
	}
        counterI = iniStringSplit2Int(outStrTmp);
        for(i = 0;i < counterI;i++)
        {
                printf("result is %d\n",intGetTable[i]);
        }
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
