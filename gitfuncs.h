/*   
	Author: Wender Francis
	GitDocker v0.1.0
	
	@branch gitdocker-v0.1.0
	@commit Software de documentação e versionamento
	@description Este software irá automatizar a documentação durante o desenvolvimento
				e fornecer uma série de recursos pra integração com o GIT

*/


#ifndef __GITFUNCS_H__

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <ctype.h>

#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

string returnString(char*);
char *substring(char*, const char*, size_t, size_t);
int indexOf(char*, const char*);
bool contains(char*, string);
void printJSONConfig();
void showInfoHelp();
void initProjectRead(char*);

void pathCommand(char *);

HANDLE color;

bool reading = false;
bool all_path = false;
int count_path = 0;

json config;
json paths;

string line_comment;
string start_comment;
string end_comment;



#define DARK_BLUE		1
#define DARK_GREEN		2
#define DARK_CYAN		3
#define DARK_RED 		4
#define DARK_PINK 		5
#define DARK_YELLOW 	6
#define DARK_WHITE		7
#define DARK_GREY		8
#define	DARK_BLUE2		9
#define LIGHT_GREEN 	10
#define LIGHT_CYAN		11
#define LIGHT_RED		12
#define	LIGHT_PINK		13
#define LIGHT_YELLOW	14
#define LIGHT_WHITE		15

//vector <string> array_file;

// @description Converte um char* em String
string returnString(char *str){
	stringstream data1;
	data1 << str;
	return data1.str();
}

// @description Converte uma String em char*
char *returnChar(string str){
	char *value;
	for(int i = 0; i < str.length(); i++){
		value[i] = str[i];
	}
}

// @description função que verifica se uma String contém outra
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

// @description Remove espaços de uma String
char * trim( char * in ){
    char * p = in;
	char * out;
    int i = 0;
    while( *p ){
        if( !isspace(*p) && strcmp(p, "	") != 0)
            in[i++] = *p;

        p++;
    }
    in[i] = 0;
    return in;
}

// @description Função pra imprimir dados da config JSON
void printJSONConfig(){
		std::ifstream f("configs/config.json");
		json data = json::parse(f);
			
		SetConsoleTextAttribute(color, LIGHT_PINK);
		cout << "REGRAS => " << endl;
		SetConsoleTextAttribute(color, DARK_BLUE2);
		cout << "	Major Maximo = ";
		SetConsoleTextAttribute(color, DARK_RED);
		cout << data["RULES"]["max_major"] << endl;
			
		SetConsoleTextAttribute(color, DARK_BLUE2);
		cout << "	Minor Maximo = ";
		SetConsoleTextAttribute(color, DARK_RED);
		cout << data["RULES"]["max_minor"] << endl;
			
		SetConsoleTextAttribute(color, DARK_BLUE2);
		cout << "	Patch Maximo = ";
		SetConsoleTextAttribute(color, DARK_RED);
		cout << data["RULES"]["max_patch"] << endl << endl;
		
		SetConsoleTextAttribute(color, LIGHT_PINK);
		cout << "EXTENSOES => " << endl;
		
		int length_lang = data["EXTENSIONS"]["lang"].size();
		for(int i = 0; i < length_lang; i++){
			json extensions = data["EXTENSIONS"]["lang"][i];
			int length_ext = extensions["exts"].size();
			SetConsoleTextAttribute(color, DARK_BLUE);
			cout << "	CONJUNTO " << (i+1) << " = ";
			SetConsoleTextAttribute(color, DARK_YELLOW);
			for(int j = 0; j < length_ext; j++){
				cout << extensions["exts"][j] << ", ";
			}
			cout << endl;
		}	
			
		SetConsoleTextAttribute(color, LIGHT_WHITE);
}

// @description Função para imprimir dados de ajuda
void showInfoHelp(){
	printf("\nGitDocker v0.0.3 Build 202208 \nCriado por Francis (KiddieOS Community)\n");
	printf("Software de Documentacao e versionamento automatizado\n");
	printf("\nusage: gitdocker [--init <arquivo>] [--show-config] \n\n");
	printf("--init | -i <arquivo> : Define codigo principal onde contem comandos iniciais\n");
	printf("--show-config | -sc : Exibe informacoes das configuracoes JSON \n\n");
}

// @description Função pra configurar interpretador
void initProjectRead(char *source){
		FILE *file;
		if((file = fopen(source, "r")) == NULL){
			SetConsoleTextAttribute(color, DARK_RED);
			std::cout << "O arquivo de codigo-fonte nao existe!" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			return;	
		}
			
		char line[1024];
		
		//readTillComments(file, line, source);

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
					//std::cout << "Lang. " << i << ": " << extension["exts"][j] << endl;
				}
			}
			//std::cout << "Lang. " << i << ": " << extension << endl;
		}
		
		
		while((fgets(line, sizeof(line), file)) != NULL){
			
			reading = (contains(line, start_comment) || contains(line, line_comment)) ? true : reading;
			
			if(reading){
				if(contains(line, "@path ")){
					pathCommand(line);
				}	

			}	

		}

		SetConsoleTextAttribute(color, LIGHT_GREEN);
		std::cout << "\nPaths Obj:" << paths << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		
		//std::cout << "\nValores Lidos:\n\n" << config << endl;
			
		std::fclose(file);	
}

// @description Função do comando Path: registra diretórios
void pathCommand(char *line){
    int lengthCmd = indexOf(line, "@path")+strlen("@path")+1;
	char *strFile = (char*) malloc(strlen(line));
						
	if(contains(line, end_comment)){
		substring(strFile, line, lengthCmd, strlen(line)-end_comment.length()-lengthCmd);
		reading = false;
	}else{
		if(contains(line, "\n"))
			substring(strFile, line, lengthCmd, indexOf(line, "\n"));
		else
			substring(strFile, line, lengthCmd, strlen(line)+1);
	} 
							
	if(contains(line, "\n"))
		strFile[strlen(strFile)-1] = 0;

	strFile = trim(strFile);
							
	if(strcmp(strFile, "[all]") == 0){
		if(!all_path){
			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "@path ";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "log: ";
			SetConsoleTextAttribute(color, DARK_YELLOW);
			std::cout << "TODOS ";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "os arquivos serao lidos!" << endl;
		}else{
			SetConsoleTextAttribute(color, LIGHT_YELLOW);
			std::cout << "Aviso: O parametro ALL ja foi definido!" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);
		}
		all_path = true;
	}else{
		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "@path ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: Registrando ";
		SetConsoleTextAttribute(color, DARK_YELLOW);
		std::cout << "'" << strFile << "' ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "para leitura" << endl;
								
		//array_file.push_back(strFile);
		paths["paths"][count_path] = strFile;
								
		std::free(strFile);
		count_path++;
	}
}

#endif
