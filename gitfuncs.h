#ifndef __GITFUNCS__

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

string returnString(char*);
char *substring(char*, const char*, size_t, size_t);
int indexOf(char*, const char*);
bool contains(char*, string);
void printJSONConfig();
void showInfoHelp();
void configInterpreter(char*);
void readTillComments(FILE*, char[ ], char*);

bool reading = false;
//vector <string> array_file;

// @description Converte um char* em String
string returnString(char *str){
	stringstream data1;
	data1 << str;
	return data1.str();
}

// @description fun��o que verifica se uma String cont�m outra
bool contains(char* first, string second)
{
	 int pos = 0;
     pos = returnString(first).find(second);
	 
     if(pos == -1)
         return false;
     else
         return true;    
          
}

// @description Fun��o que pega uma parte de uma String
char *substring(char *dst, const char *src, size_t start, size_t end){
    return strncpy(dst, src + start, end);
}

// @description Fun��o que pega �ndice de uma String em outra String
int indexOf(char *a, const char *str){
	return strstr(a, str) - a;
}

// @description Fun��o pra imprimir dados da config JSON
void printJSONConfig(){
		FILE *file;
		if((file = fopen("configs/config.json", "r")) == NULL){
			printf("\nErro em abrir o arquivo para leitura!\n");
			return;	
		}
			
		char line[1024];
		
		while(fgets(line, sizeof(line), file) != NULL){
			printf("%s", line);
		}
			
		fclose(file);	
}

// @description Fun��o para imprimir dados de ajuda
void showInfoHelp(){
	printf("\nGitDocker v0.0.3 Build 202208 \nCriado por Francis (KiddieOS Community)\n");
	printf("Software de Documentacao e versionamento automatizado\n");
	printf("\nusage: gitdocker [--config <arquivo>] [--show-config] \n\n");
	printf("--config | -c <arquivo> : Define codigo principal onde contem configuracoes iniciais\n");
	printf("--show-config | -sc : Exibe informacoes das configuracoes JSON \n\n");

	
}

#endif
