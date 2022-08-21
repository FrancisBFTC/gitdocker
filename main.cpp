/*   Author: Wender Francis
	GitDocker v0.0.3
	
	@branch gitdocker-v0.0.3
	@commit Software de documentação e versionamento
	@description Este software irá automatizar a documentação durante o desenvolvimento
				e fornecer uma série de recursos pra integração com o GIT

*/

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

bool contains(char*, string);
void printJSONConfig();
void showInfoHelp();
void configInterpreter(char*);
void readTillComments(FILE*, char[ ]);

bool reading = false;

//@description Adiciona 2 argumentos no MAIN
int main(int argc, char** argv) {
	
	if(argc > 1){
		if(strcmp(argv[1], "--config") == 0 || strcmp(argv[1], "-c") == 0){
			printf("\nConfigurando Projeto:\n\n");
			configInterpreter(argv[2]);
			/*
				TODO: Ler configurações iniciais de um arquivo e salva isso,
				onde estas configurações poderão ser informações para um README,
				apontamento para arquivos onde tem comandos do gitdocker, etc...
			*/
		}
		
		if(strcmp(argv[1], "--show-config") == 0 || strcmp(argv[1], "-sc") == 0){
			printJSONConfig();
		}
		
	}else{
		showInfoHelp();
	}
	
	return 0;
}

string returnString(char *str){
	stringstream data1;
	data1 << str;
	return data1.str();
}

bool contains(char* first, string second)
{
	 int pos = 0;
     pos = returnString(first).find(second);
	 
     if(pos == -1)
         return false;
     else
         return true;    
          
}

// @description Função que pega uma parte de uma String
char *substring(char *dst, const char *src, size_t start, size_t end){
    return strncpy(dst, src + start, end);
}

// @description Função que pega índice de uma String em outra String
int indexOf(char *a, const char *str){
	return strstr(a, str) - a;
}

// @description Função pra imprimir dados da config JSON
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

// @description Função para imprimir dados de ajuda
void showInfoHelp(){
	printf("\nGitDocker v0.0.3 Build 202208 \nCriado por Francis (KiddieOS Community)\n");
	printf("Software de Documentacao e versionamento automatizado\n");
	printf("\nusage: gitdocker [--config <arquivo>] [--show-config] \n\n");
	printf("--config | -c <arquivo> : Define codigo principal onde contem configuracoes iniciais\n");
	printf("--show-config | -sc : Exibe informacoes das configuracoes JSON \n\n");
}

// @description Função pra configurar interpretador
void configInterpreter(char *source){
		FILE *file;
		if((file = fopen(source, "r")) == NULL){
			printf("\nO arquivo de codigo-fonte nao existe!\n");
			return;	
		}
			
		char line[1024];
		
		readTillComments(file, line);
		
		while(reading){
			
			while(!contains(line, "@")){
				char *value = fgets(line, sizeof(line), file);
				
				if(contains(line, "*/") || value == NULL){
					reading = false;
					break;
				}
			}
			
			if(reading){
				if(contains(line, "@path ")){
					int lengthCmd = strlen("@path")+indexOf(line, "@path")+1;
					char *strFile = (char*) malloc(strlen(line));
					substring(strFile, line, lengthCmd, indexOf(line, "\n"));
					strFile[strlen(strFile)-1] = 0;
					
					printf("@path log: Registrando '%s' para leitura\n", strFile);
					free(strFile);
				}
				
				fgets(line, sizeof(line), file);
			}
			
		}
		
		
			
		fclose(file);	
}

// @description Leitura de linhas de um arquivo até determinado caractere
void readTillComments(FILE *file, char *line){
	reading = false;
	while(!reading){
		char *value = fgets(line, sizeof(line), file);
		if(value != NULL){
			if(contains(line, "/*") || contains(line, "//")){
				reading = true;
			}
		}else{
			break;
		}
	}
}
