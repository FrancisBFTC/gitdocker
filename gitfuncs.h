/*   
	Author: Wender Francis
	GitDocker v0.1.1
	
	@branch gitdocker-v0.1.1
	@commit Software de documentação e versionamento
	@description Este software irá automatizar a documentação durante o desenvolvimento
				e fornecer uma série de recursos pra integração com o GIT

*/


#ifndef __GITFUNCS_H__

// Inclusões de Bibliotecas de C e C++
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>
#include <string.h>
#include <vector>
#include <windows.h>
#include <fstream>
#include <dirent.h>
#include <cstdlib>

// Inclusões de Bibliotecas adicionais
#include <nlohmann/json.hpp>

// Importando NameSpaces
using namespace std;
using json = nlohmann::json;

// Declaração de Funções
string toString(char*);
void toChar(string, char*);
char *substring(char*, const char*, size_t, size_t);
int indexOf(char*, const char*);
bool contains(char*, string);
void printJSONConfig();
void showInfoHelp();
void initProjectRead(char*);
void fileInterpreter(FILE*, bool);
int readAllDirectory(string, bool);
void runningInitWIgnore(FILE*, char*);
void changeSymbolComments(json);
string getString(char*, string);

// Declaração de Funções de Comandos Gitdocker
void pathCommand(char *);
void initCommand();
void commitCommand(char *);
void descriptionCommand(char *);

// Variáveis Booleanas para comandos e leitura
bool reading_init = false;
bool reading_file = false;
bool all_path = false;
bool path_defined = false;

bool block_symbol = false;
bool line_symbol = false;

// Variáveis inteiras para contadores
int count_path = 0;
int count_ext = 0;
int count_init = 0;

// Objetos JSON
json config;
json paths;

// Variáveis Strings
string line_comment;
string start_comment;
string end_comment;
string cli_file;
stringstream conc;

// Variáveis do Windows
HANDLE color;

// Definições de Cores para o HANDLE
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


// @description Converte um char* em String
string toString(char *str)
{
	stringstream data1;
	data1 << str;
	return data1.str();
}

// @description Converte uma String em char*
void toChar(string str, char *value)
{
	int i;
	for(i = 0; i < str.length(); i++)
		value[i] = str[i];

	value[i] = 0;
}

// @description função que verifica se uma String contém outra
bool contains(char* first, string second)
{
	return (toString(first).find(second) == -1) ? false : true;         
}

// @description Função que pega uma parte de uma String
char *substring(char *dst, const char *src, size_t start, size_t end)
{
    return strncpy(dst, src + start, end);
}

// @description Função que pega índice de uma String em outra String
int indexOf(char *a, const char *str)
{
	return strstr(a, str) - a;
}

// @description Remove espaços e tabs de uma String
char * trim( char * in )
{
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

// @description Função pra iniciar projeto
void initProjectRead(char *source){
		FILE *file;
		if((file = fopen(source, "r")) == NULL){
			SetConsoleTextAttribute(color, DARK_RED);
			std::cout << "--init error: O arquivo de codigo-fonte nao existe!" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			return;	
		}

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
					changeSymbolComments(extension["comments"]);
					break;
				}
			}
		}
		
		
		fileInterpreter(file, true);
			
		std::fclose(file);	
}

// @description Função do comando Path: registra diretórios
void pathCommand(char *line){
    int lengthCmd = indexOf(line, "@path")+strlen("@path")+1;
	char *strFile = (char*) malloc(strlen(line));
						
	if(contains(line, end_comment)){
		substring(strFile, line, lengthCmd, strlen(line)-end_comment.length()-lengthCmd);
		reading_init = false;
	}else{
		if(contains(line, "\n"))
			substring(strFile, line, lengthCmd, indexOf(line, "\n"));
		else
			substring(strFile, line, lengthCmd, strlen(line)+1);
	} 
							
	if(contains(line, "\n"))
		strFile[strlen(strFile)-1] = 0;

	strFile = trim(strFile);

	if(contains(strFile, "[all:")){
		string text = toString(strFile);
    	vector<string> words;

    	char dot_char = ',';
    	stringstream sstream(text);
    	string word;
    	while (std::getline(sstream, word, dot_char)) {
        	words.push_back(word);
    	}

		for(int j = 0; j < words.size(); j++){
			if(words[j].find("[all:") != -1)
				words[j].replace(words[j].find("[all:"), 5, "");

			if(words[j].find("]") != -1)
				words[j].replace(words[j].find("]"), 1, "");

			paths["exts"][count_ext] = words[j];
			count_ext++;
		}

		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "@path ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: Registrando ";
		SetConsoleTextAttribute(color, DARK_YELLOW);
		std::cout << "'" << words.size() << " Extensoes' ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "para leitura" << endl;
		
	}else{
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

	SetConsoleTextAttribute(color, LIGHT_GREEN);
	std::cout << "\nPaths Obj:" << paths["paths"] << endl;
	SetConsoleTextAttribute(color, LIGHT_RED);
	std::cout << "Exts Obj:" << paths["exts"] << endl;
	SetConsoleTextAttribute(color, LIGHT_WHITE);
}

// @description Função do comando commit para mensagens de commit
void commitCommand(char *line){
	string msgCommand = getString(line, "@commit");
	cout << "STRING : '" << msgCommand << "'" << endl;
}

// @description Função do comando description para descrições de commits
void descriptionCommand(char *line){
	string msgCommand = getString(line, "@description");
	cout << "STRING : '" << msgCommand << "'" << endl;
}

string getString(char *line, string command){

	string lineStr = toString(line);
	int sizeStr = lineStr.find(command)+command.length()+1;

	if(contains(line, end_comment)){
		lineStr = lineStr.substr(sizeStr, lineStr.find(end_comment)-sizeStr+1);
		reading_init = false;
	}else{
		if(contains(line, "\n"))
			lineStr = lineStr.substr(sizeStr, lineStr.find("\n"));
		else
			lineStr = lineStr.substr(sizeStr, lineStr.length()+1);
	} 

	if(contains(line, "\n"))
		lineStr[lineStr.length()-1] = 0;

	return lineStr;
}

// @description Comando init para processar as leituras
void initCommand(){
	// TODO: pegar parâmetro de tempo pela variável line

	if(path_defined){
		FILE *file_read;
		if(all_path){
			string directory = config["INIT"]["dir"];
			conc << directory;
			readAllDirectory(directory, false);

			conc.str("");
		}else{
			if(paths["paths"] != NULL){
				
				cout << endl;
				for(count_init = 0; count_init < paths["paths"].size(); count_init++){
					string files = paths["paths"][count_init];
					char *filesChar = (char*) malloc(files.length());
					toChar(files, filesChar);

					if((file_read = fopen(filesChar, "r")) == NULL){
						SetConsoleTextAttribute(color, DARK_RED);
						std::cout << "O arquivo '" << filesChar << "' definido no path nao existe!" << endl;
						SetConsoleTextAttribute(color, LIGHT_WHITE);
					}else{
						if(contains(filesChar, ".")){
							char *ext = (char*) malloc(strlen(filesChar));
							substring(ext, filesChar, indexOf(filesChar, "."), strlen(filesChar));

							int count_langs = config["EXTENSIONS"]["lang"].size();
							bool finded = false;
							for(int i = 0; i < count_langs; i++){
								json extension = config["EXTENSIONS"]["lang"][i];
								int count_exts = extension["exts"].size();
								
								for(int j = 0; j < count_exts; j++){
									if(extension["exts"][j] == ext){
										changeSymbolComments(extension["comments"]);
										runningInitWIgnore(file_read, filesChar); 
										finded = true;
										break;
									}
								}
								if(finded) break;
							}
								
							free(ext);
						}

					}

					free(filesChar);
				
				}
				
			}

			if(paths["exts"] != NULL){
				string directory = config["INIT"]["dir"];
				conc << directory;
				readAllDirectory(directory, true);

				conc.str("");
			}
		}

		fclose(file_read);
	}

}

// @description função de interpretador de comandos
void fileInterpreter(FILE* file, bool is_read){
	char line[1024];
	block_symbol = false;

	while((fgets(line, sizeof(line), file)) != NULL){
		line_symbol = false;

		if(contains(line, start_comment)) block_symbol = true;
		if(contains(line, line_comment)) line_symbol = true;

		if(block_symbol || line_symbol){
			if(is_read){
				if(contains(line, "@path ")){
					pathCommand(line);
					path_defined = true;
				}
				if(contains(line, "@init")){
					initCommand();
				}
			}
			//cout << "LINHA: " << line << endl;
			if(contains(line, "@commit")){
				commitCommand(line);
			}
			if(contains(line, "@description")){
				descriptionCommand(line);
			}
			if(contains(line, "@branch")){
				cout << "\tO comando @branch existe!" << endl;
			}
		}

		if(contains(line, end_comment)) block_symbol = false;

	}

}

// @description Ler todos os diretórios pelo parâmetro [all] ou [all: ...]
int readAllDirectory (std::string nomeDir, bool is_allext) {
    DIR *dir = 0;
    struct dirent *input = 0;
 
	// nomeDir.c_str()
    dir = opendir (nomeDir.c_str());
 
    if (dir == 0) return 0;

    //Iterar sobre o diretorio
    while (input = readdir (dir)){

		if(input->d_namlen > 2){
			
			stringstream conc1;
			conc1 << nomeDir << input->d_name;
			FILE *filedir = fopen(conc1.str().c_str(), "r");
			string rootdir = config["INIT"]["dir"];
			
			bool is_folder = filedir == NULL;
			if(is_folder){
				conc << input->d_name << "/";

				//cout << "PASTA: " << conc.str() << endl;
				readAllDirectory(conc.str(), is_allext);

				stringstream conc2;
				conc2 << input->d_name << "/";
				string root = conc.str().replace(conc.str().find(conc2.str()), conc2.str().length(), "");
				conc.str("");
				conc << root;

			}else{
				string full_dir = conc1.str().c_str(); // diretorio completo do arquivo

				//cout << "ARQUIVO: " << full_dir << endl;

				if(!is_allext){
					if(contains(input->d_name, ".")){
						char *ext = (char*) malloc(strlen(input->d_name));
						substring(ext, input->d_name, indexOf(input->d_name, "."), strlen(input->d_name));

						int count_langs = config["EXTENSIONS"]["lang"].size();
						bool finded = false;
						for(int i = 0; i < count_langs; i++){
							json extension = config["EXTENSIONS"]["lang"][i];
							int count_exts = extension["exts"].size();
							
							for(int j = 0; j < count_exts; j++){
								if(extension["exts"][j] == ext){
									changeSymbolComments(extension["comments"]);
									finded = true;
									break;
								}
							}
							if(finded) break;
						}

						if(finded)
							runningInitWIgnore(filedir, input->d_name); 

						free(ext);
					}
				}else{
					bool contain_ext = false;
					char *ext = (char*) malloc(strlen(input->d_name));

					if(contains(input->d_name, ".")){
						substring(ext, input->d_name, indexOf(input->d_name, "."), strlen(input->d_name));
						for(int x = 0; x < paths["exts"].size(); x++){
							string ext_save = paths["exts"][x];

							if(ext_save == ext){
								contain_ext = true;
								break;
							}
						}	
					}
					
					if(contain_ext){
						
						int count_langs = config["EXTENSIONS"]["lang"].size();
						bool finded = false;
						for(int i = 0; i < count_langs; i++){
							json extension = config["EXTENSIONS"]["lang"][i];
							int count_exts = extension["exts"].size();
							
							for(int j = 0; j < count_exts; j++){
								if(extension["exts"][j] == ext){
									changeSymbolComments(extension["comments"]);
									finded = true;
									break;
								}
							}
							if(finded) break;
						}

						if(finded)
							runningInitWIgnore(filedir, input->d_name); 
						else{
							SetConsoleTextAttribute(color, LIGHT_CYAN);
							std::cout << "@init ";
							SetConsoleTextAttribute(color, LIGHT_WHITE);
							std::cout << "log: Erro => ";
							SetConsoleTextAttribute(color, LIGHT_RED);
							std::cout << "A extensao '" << ext << "' nao foi configurada no JSON!" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
						} 

					}
						
					free(ext);
				}

			}
			
		}

		
	}
            
 
    closedir (dir);
     
    return 1;
}

// @description Executa processamento init ignorando extensões
void runningInitWIgnore(FILE *file_open, char *name_file){
	bool ignore = false;
	for(int j = 0; j < config["INIT"]["ignore"].size(); j++){
		string ignore_ext = config["INIT"]["ignore"][j];
		if(contains(name_file, ignore_ext) || name_file == cli_file){
			ignore = true;
			break;
		}
	}

	if(!ignore){
		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "@init ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: Processando arquivo ";
		SetConsoleTextAttribute(color, DARK_YELLOW);
		std::cout << "'" << name_file << "' ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "..." << endl;
					
		fileInterpreter(file_open, false);
	}else{
		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "@init ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: Erro => ";
		SetConsoleTextAttribute(color, LIGHT_RED);
		std::cout << "o arquivo '" << name_file << "' nao contem uma extensao valida!" << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);
	}	
}

// @description Altera símbolos de comentários dinâmicamente para cada arquivo lido
void changeSymbolComments(json comments){
	switch(comments.size()){
		case 1:
			line_comment = comments[0];
			start_comment = comments[0];
			end_comment = "";
			break;
		case 2:
			line_comment = comments[0];
			start_comment = comments[0];
			end_comment = comments[1];
			break;
		case 3:
			line_comment = comments[0];
			start_comment = comments[1];
			end_comment = comments[2];
			break;
	}
}

#endif
