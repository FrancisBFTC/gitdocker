/*   Author: Wender Francis
	GitDocker v0.0.3
	
	@branch gitdocker-v0.0.3
	@commit Software de documentação e versionamento
	@description Este software irá automatizar a documentação durante o desenvolvimento
				e fornecer uma série de recursos pra integração com o GIT

*/


#include "gitfuncs.h"
#include <fstream>
#include <nlohmann/json.hpp>

#include <iostream>

using json = nlohmann::json;

json config;
json paths;

string line_comment;
string start_comment;
string end_comment;


//@description Adiciona 2 argumentos no MAIN
int main(int argc, char** argv) {
	
	if(argc > 1){
		if(strcmp(argv[1], "--config") == 0 || strcmp(argv[1], "-c") == 0){
			printf("\nConfigurando Projeto:\n\n");
			configInterpreter(argv[2]);
		}
		
		if(strcmp(argv[1], "--show-config") == 0 || strcmp(argv[1], "-sc") == 0){
			printf("\nConfiguracoes Atuais:\n\n");
		//	printJSONConfig();
			std::ifstream f("configs/config.json");
			json data = json::parse(f);
			
			cout << data << endl;
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
		
		int count = 0;
		
		while(reading){
			
			while(!contains(line, "@")){
				char *value = fgets(line, sizeof(line), file);
				
				if(contains(line, end_comment) || value == NULL){
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
					
					//array_file.push_back(strFile);
					paths["paths"][count] = strFile;
					
					free(strFile);
					count++;
				}
				
				if(contains(line, "@"))
					fgets(line, sizeof(line), file);
			}
			
		}
		
		cout << "\nPaths Obj:" << paths << endl;
		//cout << "\nValores Lidos:\n\n" << config << endl;
		//cout << "Quant. Linguagens Configuradas': " << config["EXTENSIONS"]["lang"].size() << endl;
		
		fclose(file);	
}

// @description Leitura de linhas de um arquivo até determinado caractere
void readTillComments(FILE *file, char *line, char *source){
	
	char *ext = (char*) malloc(strlen(source));
	substring(ext, source, indexOf(source, "."), strlen(source));
	
	std::ifstream f("configs/config.json");
	config = json::parse(f);
	
	int count_langs = config["EXTENSIONS"]["lang"].size();
	
	for(int i = 0; i < count_langs; i++){
		json extension = config["EXTENSIONS"]["lang"][i];
		int count_exts = extension["exts"].size();
		
		for(int j = 0; j < count_exts; j++){
			if(extension["exts"][j] == ext){
				
				switch(extension["comments"].size()){
					case 1:
						line_comment = extension["comments"][0];
						start_comment = extension["comments"][0];
						end_comment = extension["comments"][0];
						break;
					case 2:
						line_comment = extension["comments"][0];
						start_comment = extension["comments"][0];
						end_comment = extension["comments"][1];
						break;
					case 3:
						line_comment = extension["comments"][0];
						start_comment = extension["comments"][1];
						end_comment = extension["comments"][2];
						break;
				}
				break;
				//cout << "Lang. " << i << ": " << extension["exts"][j] << endl;
			}
		}
		//cout << "Lang. " << i << ": " << extension << endl;
	}
	
	reading = false;
	while(!reading){
		char *value = fgets(line, sizeof(line), file);
		if(value != NULL){
			if(contains(line, start_comment) || contains(line, line_comment)){
				reading = true;
			}
		}else{
			break;
		}
	}
}
