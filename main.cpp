/*   Author: Wender Francis
	GitDocker v0.0.3
	
	@branch gitdocker-v0.0.3
	@commit Software de documentação e versionamento
	@description Este software irá automatizar a documentação durante o desenvolvimento
				e fornecer uma série de recursos pra integração com o GIT

*/


#include "gitfuncs.h"

//@description Adiciona 2 argumentos no MAIN
int main(int argc, char** argv) {
	
	if(argc > 1){
		if(strcmp(argv[1], "--config") == 0 || strcmp(argv[1], "-c") == 0){
			printf("\nConfigurando Projeto:\n\n");
			configInterpreter(argv[2]);
		}
		
		if(strcmp(argv[1], "--show-config") == 0 || strcmp(argv[1], "-sc") == 0){
			printf("\nConfiguracoes Atuais:\n\n");
			printJSONConfig();
		}
		
	}else{
		showInfoHelp();
	}
	
	return 0;
}

// @description Função pra configurar interpretador
void configInterpreter(char *source){
		FILE *file;
		if((file = fopen(source, "r")) == NULL){
			printf("\nO arquivo de codigo-fonte nao existe!\n");
			return;	
		}
			
		char line[1024];
		
		readTillComments(file, line, source);
		
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
					
					array_file.push_back(strFile);
					
					free(strFile);
				}
				
				if(contains(line, "@"))
		
				fgets(line, sizeof(line), file);
			}
			
		}
		
		/*
		for(int z=0; z < array_file.size(); z++) {
			cout << array_file[z] << endl;	
		}
		*/
		
		
		fclose(file);	
}

// @description Leitura de linhas de um arquivo até determinado caractere
void readTillComments(FILE *file, char *line, char *source){
	
	char *ext = (char*) malloc(strlen(source));
	substring(ext, source, indexOf(source, ".")+1, strlen(source));
	FILE *jsonRead = fopen("configs/config.json", "r");
	
	// TODO: Procurar extensão no JSON e identificar símbolo de comentário
	
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
