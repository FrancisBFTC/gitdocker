/*
	Author: Wender Francis
	GitDocker v0.0.3
	
	@branch gitdocker-v0.0.3
	@commit Software de documenta��o e versionamento
	@description Este software ir� automatizar a documenta��o durante o desenvolvimento
				e fornecer uma s�rie de recursos pra integra��o com o GIT

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

//@description Adiciona 2 argumentos no MAIN
int main(int argc, char** argv) {
	
	if(argc > 1){
		if(strcmp(argv[1], "--config") == 0 || strcmp(argv[1], "-c") == 0){
			printf("\nConfiguracao do --config\n");
			/*
				TODO: Ler configura��es iniciais de um arquivo e salva isso,
				onde estas configura��es poder�o ser informa��es para um README,
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

// @commit Fun��o pra imprimir dados da config JSON
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

// @commit Fun��o para imprimir dados de ajuda
void showInfoHelp(){
	printf("\nGitDocker v0.0.3 Build 202208 \nCriado por Francis (KiddieOS Community)\n");
	printf("Software de Documentacao e versionamento automatizado\n");
	printf("\nusage: gitdocker [--config <arquivo>] [--show-config] \n\n");
	printf("--config | -c <arquivo> : Define codigo principal onde contem configuracoes iniciais\n");
	printf("--show-config | -sc : Exibe informacoes das configuracoes JSON \n\n");
}
