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
#include <TIME.H>

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
void searchJSONValues(char*);
void initProjectRead(char*);
void fileInterpreter(FILE*, bool);
int readAllDirectory(string, bool);
void runningInitWIgnore(FILE*, char*);
void changeSymbolComments(json);
void writeJSONFile(string, json);
void checkStateFiles();
bool verifyModification(bool);
string getString(char*, string);
string replace_all(string, string, string);

// Declaração de Funções de Comandos Gitdocker
void pathCommand(char *);
void initCommand();
void commitCommand(char *);
void descriptionCommand(char *);
void runCommit(bool);
void branchCommand();
void mergeExecute();
void configExecute(char*);

// Variáveis Booleanas para comandos e leitura
bool reading_init = false;
bool reading_file = false;
bool all_path = false;
bool path_defined = false;
bool commited = false;
bool last_commited = false;
bool branched = false;
bool switched = false;
bool contain_branch = false;

bool block_symbol = false;
bool line_symbol = false;

bool modified = false;
bool untracked = false;
bool is_modified = false;

// Variaveis booleanas para parâmetros na CLI
bool recursive = false;
bool param_lang = false;
bool param_patch = false;
bool param_major = false;
bool param_minor = false;
bool param_dir = false;
bool param_ignore = false;
bool rules_arg = false;
bool exts_arg = false;
bool init_arg = false;
bool reset_ext = false;

// Variáveis inteiras para contadores
int count_path = 0;
int count_ext = 0;
int count_init = 0;
int count_commit = 0;
int count_descr = 0;
int count_recursive = 0;
int count_branch = 0;

// Objetos JSON
json config;
json paths;
json info;

// Variáveis Strings
string line_comment;
string start_comment;
string end_comment;
string cli_file;
stringstream conc;
string file_mod;
string branch_str = "main";
string branchname;

// Variaveis Strings para parametros na CLI
string major_str;
string minor_str;
string patch_str;
string lang_str;
string dir_str;
string ignore_str;

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

void writeJSONFile(string filename, json jsondata){
		fstream output;
		output.open(filename, std::ios_base::out);

		if(!output.is_open()){
			SetConsoleTextAttribute(color, DARK_RED);
			cerr << "Falha em abrir o arquivo '" << filename << "'\n";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
		}else{
			stringstream jsonstream;
			jsonstream << jsondata;
			string jsonstr = jsonstream.str();

			jsonstr = replace_all(jsonstr, "\",", "\",\n");
			jsonstr = replace_all(jsonstr, "{", "{\n");
			jsonstr = replace_all(jsonstr, "},", "},\n");
			jsonstr = replace_all(jsonstr, "}", "\n}");
			jsonstr = replace_all(jsonstr, "[", "[\n");
			jsonstr = replace_all(jsonstr, "]", "\n]");
			jsonstr = replace_all(jsonstr, "\n\"", "\n\t\"");
			jsonstr = replace_all(jsonstr, "],", "\t],");

			output << jsonstr << endl;
		}
}

string replace_all(string s, string x, string y){
	size_t pos = 0;
    while (pos += y.length())
    {
        pos = s.find(x, pos);
        if (pos == std::string::npos) {
            break;
        }
 
        s.replace(pos, x.length(), y);
    }

	return s;
}

// @description Função pra imprimir dados da config JSON
void printJSONConfig(){
		std::ifstream f("C:/gitd/configs/config.json");
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

		SetConsoleTextAttribute(color, LIGHT_PINK);
		cout << "\nINICIALIZACAO => " << endl;

		SetConsoleTextAttribute(color, DARK_BLUE2);
		cout << "	Diretorio = ";
		SetConsoleTextAttribute(color, DARK_YELLOW);
		cout << data["INIT"]["dir"] << endl;

		SetConsoleTextAttribute(color, DARK_BLUE2);
		cout << "	Extensoes Ignoradas = ";
		SetConsoleTextAttribute(color, DARK_YELLOW);

		int length_ignore = data["INIT"]["ignore"].size();
		for(int i = 0; i < length_ignore; i++)
			cout << data["INIT"]["ignore"][i] << " ";

		cout << endl << endl;
			
		SetConsoleTextAttribute(color, LIGHT_WHITE);
}

void configExecute(char *arg){
	std::ifstream con("C:/gitd/configs/config.json");
	config = json::parse(con);

	if(config[arg].size() != 0){

		if(strcmp(arg, "RULES") == 0){
			if(rules_arg){
				bool has_param = false;

				cout << endl;
			
				if(param_major){
					config[arg]["max_major"] = major_str.c_str();
					writeJSONFile("C:/gitd/configs/config.json", config);

					SetConsoleTextAttribute(color, LIGHT_GREEN);
					std::cout << "O dado '" << major_str << "' da chave 'max_major' foi configurado com sucesso!" << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
					has_param = true;
				}

				if(param_minor){
					config[arg]["max_minor"] = minor_str.c_str();
					writeJSONFile("C:/gitd/configs/config.json", config);

					SetConsoleTextAttribute(color, LIGHT_GREEN);
					std::cout << "O dado '" << minor_str << "' da chave 'max_minor' foi configurado com sucesso!" << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
					has_param = true;
				}

				if(param_patch){
					config[arg]["max_patch"] = patch_str.c_str();
					writeJSONFile("C:/gitd/configs/config.json", config);

					SetConsoleTextAttribute(color, LIGHT_GREEN);
					std::cout << "O dado '" << patch_str << "' da chave 'max_patch' foi configurado com sucesso!" << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
					has_param = true;
				}
			
				if(!has_param){
					SetConsoleTextAttribute(color, LIGHT_RED);
					std::cout << "\nO parametro inserido e invalido!" << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
				}

			}else{
				cout << "\nInsira dados numericos sem aspas ou apenas o valor none" << endl;
				cout << "\nMajor maximo = ";
				cin >> major_str;
				cout << "Minor maximo = ";
				cin >> minor_str;
				cout << "Patch maximo = ";
				cin >> patch_str;

				config[arg]["max_major"] = major_str.c_str();
				config[arg]["max_minor"] = minor_str.c_str();
				config[arg]["max_patch"] = patch_str.c_str();

				writeJSONFile("C:/gitd/configs/config.json", config);

				SetConsoleTextAttribute(color, LIGHT_GREEN);
				std::cout << "\nTodos os dados de 'RULES' foi configurado com sucesso!" << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);
			}
		}else{
			if(strcmp(arg, "EXTENSIONS") == 0){
				if(exts_arg){
					bool has_param = false;

					cout << endl;

					if(param_lang){
						int index = stoi(lang_str);
						int quant_ext = 0;
						string ext_string;
						if(index > 0){
							if(reset_ext)
								config["EXTENSIONS"]["lang"][index-1]["exts"].clear();

							cout << "Insira extensoes com o '.' antes:" << endl;
							cout << "\nQuantidade de extensoes = ";
							cin >> quant_ext;
							int next_index = config["EXTENSIONS"]["lang"][index-1]["exts"].size();
							int total_ext = quant_ext + next_index;
							for(int i = next_index; i < total_ext; i++){
								cout << "extensao " << i+1 << " = ";
								cin >> ext_string;
								config["EXTENSIONS"]["lang"][index-1]["exts"][i] = ext_string.c_str();
							}
							
							writeJSONFile("C:/gitd/configs/config.json", config);

							SetConsoleTextAttribute(color, LIGHT_GREEN);
							std::cout << endl << quant_ext << " extensoes foram adicionadas no conjunto " << index << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
							

						}else{
							SetConsoleTextAttribute(color, LIGHT_RED);
							std::cout << "O indice " << index << " e invalido!" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
						}

						has_param = true;
					}

					if(!has_param){
						SetConsoleTextAttribute(color, LIGHT_RED);
						std::cout << "\nO parametro inserido e invalido!" << endl;
						SetConsoleTextAttribute(color, LIGHT_WHITE);
					}
				}else{
					int quant_ext = 0;
					int quant_com = 0;
					string ext_string;

					int next = config["EXTENSIONS"]["lang"].size();
					cout << "Insira extensoes com o '.' antes:" << endl;
					cout << "\nQuant. de extensoes = ";
					cin >> quant_ext;
					
					if(quant_ext > 0){
						cout << "Quant. de simbolos de comentarios = ";
						cin >> quant_com;

						if(quant_com >= 1 && quant_com <= 3){
							for(int i = 0; i < quant_ext; i++){
								cout << "extensao " << i+1 << " = ";
								cin >> ext_string;
								config["EXTENSIONS"]["lang"][next]["exts"][i] = ext_string.c_str();
							}

							switch(quant_com){
								case 1:
									for(int i = 0; i < quant_com; i++){
										cout << "Comentario de linha/bloco = ";	
										cin >> ext_string;
										config["EXTENSIONS"]["lang"][next]["comments"][i] = ext_string.c_str();
									}
									break;
								case 2:
									for(int i = 0; i < quant_com; i++){
										if(i == 0)
											cout << "Comentario de bloco (abertura) = ";
										if(i == 1)
											cout << "Comentario de bloco (fechadura) = ";
											
										cin >> ext_string;
										config["EXTENSIONS"]["lang"][next]["comments"][i] = ext_string.c_str();
									}
									break;
								case 3:
									for(int i = 0; i < quant_com; i++){
										if(i == 0)
											cout << "Comentario de linha = ";
										if(i == 1)
											cout << "Comentario de bloco (abertura) = ";
										if(i == 2)
											cout << "Comentario de bloco (fechadura) = ";
											
										cin >> ext_string;
										config["EXTENSIONS"]["lang"][next]["comments"][i] = ext_string.c_str();
									}
									break;
							}

							writeJSONFile("C:/gitd/configs/config.json", config);

							SetConsoleTextAttribute(color, LIGHT_GREEN);
							std::cout << endl << "O conjunto " << next+1 << " de extensoes foi adicionado com sucesso!" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);

						}else{
							SetConsoleTextAttribute(color, LIGHT_RED);
							std::cout << "\nErro: O minimo de simbolos de comentarios e 1 e o maximo e 3" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
						}
					}else{
						SetConsoleTextAttribute(color, LIGHT_RED);
						std::cout << "\nErro: A quantidade de extensoes nao pode ser zero!" << endl;
						SetConsoleTextAttribute(color, LIGHT_WHITE);
					}

				}
			}else{
				if(strcmp(arg, "INIT") == 0){
					if(init_arg){
						bool has_param = false;

						cout << endl;

						if(param_dir){
							config[arg]["dir"] = dir_str.c_str();
							writeJSONFile("C:/gitd/configs/config.json", config);

							SetConsoleTextAttribute(color, LIGHT_GREEN);
							std::cout << "O diretorio '" << dir_str << "' da chave 'dir' foi configurado com sucesso!" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
							has_param = true;
						}

						if(param_ignore){
							if(reset_ext)
								config[arg]["ignore"].clear();

							int index = config[arg]["ignore"].size();
							config[arg]["ignore"][index] = ignore_str.c_str();
							writeJSONFile("C:/gitd/configs/config.json", config);

							SetConsoleTextAttribute(color, LIGHT_GREEN);
							std::cout << "A extensao '" << ignore_str << "' foi adicionado na lista de ignorados!" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
							has_param = true;
						}

						if(!has_param){
							SetConsoleTextAttribute(color, LIGHT_RED);
							std::cout << "\nO parametro inserido e invalido!" << endl;
							SetConsoleTextAttribute(color, LIGHT_WHITE);
						}

					}else{
						int quant_ext = 0;
						string ext_string;

						if(reset_ext)
								config[arg]["ignore"].clear();

						int next = config[arg]["ignore"].size();
						cout << "Insira extensoes com o '.' antes e no diretorio insira './' antes de qualquer pasta, ou apenas './':" << endl;
						cout << "\nDiretorio p/ leitura = ";
						cin >> dir_str;
						cout << "\nQuant. de extensoes = ";
						cin >> quant_ext;

						config[arg]["dir"] = dir_str.c_str();

						int total_ext = quant_ext + next;
						for(int i = next; i < total_ext; i++){
							cout << "extensao " << i+1 << " = ";
							cin >> ext_string;
							config[arg]["ignore"][i] = ext_string.c_str();
						}

						writeJSONFile("C:/gitd/configs/config.json", config);

						SetConsoleTextAttribute(color, LIGHT_GREEN);
						std::cout << "O diretorio '" << dir_str << "' e " << quant_ext << " extensoes ignoradas foram configuradas com sucesso!" << endl;
						SetConsoleTextAttribute(color, LIGHT_WHITE);

					}
				}
			}
		}

	}else{
		SetConsoleTextAttribute(color, LIGHT_RED);
		std::cout << "\nEste valor '" << arg << "' nao e valido!" << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);
	}
}

void searchJSONValues(char *specified){
	std::ifstream f("C:/gitd/configs/config.json");
	json data = json::parse(f);

	//string speficied = toString(value);

	int count_langs = data["EXTENSIONS"]["lang"].size();
		
	bool ext_finded = false;
	for(int i = 0; i < count_langs; i++){
		json extension = data["EXTENSIONS"]["lang"][i];
		int count_exts = extension["exts"].size();
			
		for(int j = 0; j < count_exts; j++){
			if(extension["exts"][j] == specified){	
				ext_finded = true;
				break;
			}
		}
	}

	if(ext_finded){
		SetConsoleTextAttribute(color, LIGHT_GREEN);
		std::cout << "Legal! A extensao '" << specified << "' foi encontrada! :)" << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);
	}else{
		SetConsoleTextAttribute(color, LIGHT_RED);
		std::cout << "Que pena! A extensao '" << specified << "' nao foi encontrada! :(" << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "Configure esta extensao utilizando --config." << endl;
	}
	
}

// @description Função para imprimir dados de ajuda
void showInfoHelp(){
	printf("\nGitDocker v0.3.0 Build 202209 \nCriado por Francis (KiddieOS Community)\n");
	printf("Software de Documentacao e versionamento automatizado\n");
	printf("\nusage: gitdocker [--init <arquivo>] [--show-config] [--search <extensao>] [--merge] \n");
	printf("                 [--config <opcao> [--major <numero>] [--minor <numero>] [--patch <numero>] | \n");
	printf("                 [--dir <diretorio>] [--ignore <extensao>] | [--lang <numero>] [--reset]] \n");
	printf("                 [--config-project] [--version] \n\n");
	printf("--init | -i <arquivo> : Define codigo principal onde contem comandos iniciais\n");
	printf("--show-config | -sc : Exibe informacoes das configuracoes JSON \n");
	printf("--search | -s <extensao> : Efetua pesquisa de extensoes no JSON \n");
	printf("--merge | -m : Realiza merge do ultimo branch que esta sendo carregado com o branch atual \n");
	printf("--config | -c <opcao>: Configurar um determinado objeto JSON dado por <opcao>, \n");
	printf("                       As opcoes possiveis sao: RULES, EXTENSIONS e INIT \n");
	printf("--major | -ma <numero>: Definir uma versao maior maxima dada por <numero>, quando --config e RULES \n");
	printf("--minor | -mi <numero>: Definir uma versao menor maxima dada por <numero>, quando --config e RULES\n");
	printf("--patch | -pa <numero>: Definir uma versao de bug (patch) maxima dada por <numero>, quando --config e RULES\n");
	printf("--lang | -l <numero>: Especificar numero de conjunto de extensoes para adicionar, quando --config e EXTENSIONS\n");
	printf("                      Para ver o conjunto de extensoes, veja: gitdocker --show-config\n");
	printf("--dir | -d <diretorio>: Definir um diretorio inicial para leitura do --init, quando --config e INIT \n");
	printf("--ignore | -ig <extensao>: Acrescentar uma extensao para ser ignorada na leitura, quando --config e INIT \n\n");
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
		
		std::ifstream con("C:/gitd/configs/config.json");
		config = json::parse(con);
		

		std::ifstream inf("infos/info.json");
		info = json::parse(inf);
		
		int count_langs = config["EXTENSIONS"]["lang"].size();
		
		bool ext_finded = false;
		for(int i = 0; i < count_langs; i++){
			json extension = config["EXTENSIONS"]["lang"][i];
			int count_exts = extension["exts"].size();
			
			for(int j = 0; j < count_exts; j++){
				if(extension["exts"][j] == ext){	
					changeSymbolComments(extension["comments"]);
					ext_finded = true;
					break;
				}
			}
		}

		if(ext_finded){
			checkStateFiles();
			fileInterpreter(file, true);
			std::fclose(file);

			if(contain_branch){
				string git_push;
				system("git add *");
				system("git commit -m \"Gitdocker auto-commit 1\" >> C:/gitd/logs/log_commit");

				if(switched){
					stringstream branch_conc, merge_conc;
					branch_conc << "git checkout --quiet " << branchname << " >> C:/gitd/logs/log_checkout";
					string git_checkout = branch_conc.str();
					
					system(git_checkout.c_str());
						
					system("git add *");
					system("git commit -m \"Gitdocker auto-commit 2\" >> C:/gitd/logs/log_commit");
						
				}

				SetConsoleTextAttribute(color, LIGHT_CYAN);
				std::cout << "\n@branch ";
				SetConsoleTextAttribute(color, LIGHT_WHITE);
				std::cout << "log: ";
				SetConsoleTextAttribute(color, LIGHT_GREEN);
				std::cout << "Atualizando repositorio remoto para branch '" << branchname << "'..." << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);

				stringstream push_conc;
				string origin = branchname;
				push_conc << "git push --quiet origin " << origin << " --quiet >> C:/gitd/logs/log_push";
				git_push = push_conc.str();

				system(git_push.c_str());
					
			}

			if(recursive){
				stringstream rec_command;
				rec_command << "gitdocker --init " << cli_file;
				string command = rec_command.str();
				for(int i = 0; i < count_recursive+1; i++){
					fstream output;
					output.open(cli_file, std::ios_base::app);

					if(output.is_open()) output.write(" ", 1);
					system(command.c_str());

					system("git add *");
					system("git commit -m \"Gitdocker auto-commit 1\" >> C:/gitd/logs/log_commit");
				}
			}			
		}else{
			std::fclose(file);

			SetConsoleTextAttribute(color, LIGHT_RED);
			std::cout << "\n--init erro => A extensao do arquivo " << source << " nao foi encontrada!" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "Configure uma extensao, Ex.: gitdocker --config --extensions N" << endl;
		}
}

void checkStateFiles(){
		paths["modifieds"].clear();
		system("git status > C:/gitd/logs/log_status");
		FILE *file_status = fopen("C:/gitd/logs/log_status", "r");
		if(file_status != NULL){
			char line_status[500];
			int count_mod = 0;
			int count_unt = 0;
			while(fgets(line_status, sizeof(line_status), file_status) != NULL){
				if(contains(line_status, "modified:")){
					modified = true;
					string line_str = toString(line_status);
					int sizeword = line_str.find("modified:")+strlen("modified:   ");
					line_str = line_str.substr(sizeword, line_str.find("\n")-sizeword);
					paths["modifieds"][count_mod] = line_str;
					count_mod++;
				}

				if(contains(line_status, "Untracked files:")){
					while(fgets(line_status, sizeof(line_status), file_status) != NULL){
						if(!contains(line_status, "git add") && (strcmp(line_status, "\n") != 0)){
							untracked = true;
							char *line_unt = line_status;
							line_unt = trim(line_unt);
							paths["untrackeds"][count_unt] = line_unt;
							count_unt++;
						}	
					}
				}

			}
		}
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

void branchCommand(){
	switched = false;
	branched = false;
	bool exist_branch = false;
	count_branch = info["INFOS"]["branchs"].size();
	for(int i = 0; i < count_branch; i++){
		if(info["INFOS"]["branchs"][i] == branchname.c_str())
			exist_branch = true;
	}

	string git_checkout;
	
	if(!exist_branch){
		stringstream branch_conc;
		branch_conc << "git checkout --quiet -b " << branchname << " >> C:/gitd/logs/log_checkout";
		git_checkout = branch_conc.str();

		info["INFOS"]["branchs"][count_branch] = branchname.c_str();
		writeJSONFile("infos/info.json", info);

		branched = true;

		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "\n@branch ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: ";
		SetConsoleTextAttribute(color, LIGHT_GREEN);
		std::cout << "A branch '" << branchname << "' foi criada!" << endl << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);

		system(git_checkout.c_str());

		info["INFOS"]["merge"][0] = branchname.c_str();
		writeJSONFile("infos/info.json", info);

	}else{
		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "\n\n@branch ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: ";
		SetConsoleTextAttribute(color, LIGHT_GREEN);
		std::cout << "Alternando para branch '" << branchname << "'" << endl << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);

		switched = true;

		info["INFOS"]["merge"][1] = branchname.c_str();
		writeJSONFile("infos/info.json", info);
	}

}

void mergeExecute(){
	std::ifstream f("infos/info.json");
	json infom = json::parse(f);

	string oldbranch = infom["INFOS"]["merge"][0];
	string newbranch = infom["INFOS"]["merge"][1];

	SetConsoleTextAttribute(color, LIGHT_CYAN);
	std::cout << "\n--merge ";
	SetConsoleTextAttribute(color, LIGHT_WHITE);
	std::cout << "log: ";
	SetConsoleTextAttribute(color, LIGHT_GREEN);
	std::cout << "Realizando o merging de '" << newbranch << "' com '" << oldbranch << "'..." << endl;
	SetConsoleTextAttribute(color, LIGHT_WHITE);

	stringstream merge_conc;
	merge_conc << "git merge " << newbranch << " " << oldbranch << " -X theirs >> C:/gitd/logs/log_merge";
	system(merge_conc.str().c_str());
			
	string currently = infom["INFOS"]["merge"][1];
	infom["INFOS"]["merge"][0] = currently.c_str();
	writeJSONFile("infos/info.json", infom);

	system("git add *");
	system("git commit -m \"Gitdocker auto-commit 3\" >> C:/gitd/logs/log_commit");

	SetConsoleTextAttribute(color, LIGHT_CYAN);
	std::cout << "--merge ";
	SetConsoleTextAttribute(color, LIGHT_WHITE);
	std::cout << "log: ";
	SetConsoleTextAttribute(color, LIGHT_GREEN);
	std::cout << "Atualizando repositorio remoto para branch '" << branchname << "'..." << endl << endl;
	SetConsoleTextAttribute(color, LIGHT_WHITE);

	stringstream push_conc;
	push_conc << "git push --quiet origin " << newbranch << " --quiet >> C:/gitd/logs/log_push";
	system(push_conc.str().c_str());	
}

// @description Função do comando commit para mensagens de commit
void commitCommand(char *line){
	 string msgCommand = getString(line, "@commit");

	last_commited = false;

	if(!commited){
		bool exist_commit = false;
		count_commit = info["INFOS"]["commits"].size();
		for(int i = 0; i < count_commit; i++)
			if(info["INFOS"]["commits"][i]["msg"] == msgCommand.c_str())
				exist_commit = true;

		if(!exist_commit){
			if(is_modified){
				vector<string> descriptions;

				info["INFOS"]["commits"][count_commit]["msg"] = msgCommand.c_str();
				info["INFOS"]["commits"][count_commit]["desc"] = descriptions;
				
				writeJSONFile("infos/info.json", info);
				commited = true;
				last_commited = true;

				branchname = branch_str;

				SetConsoleTextAttribute(color, LIGHT_CYAN);
				std::cout << "\n\n@commit ";
				SetConsoleTextAttribute(color, LIGHT_WHITE);
				std::cout << "log: ";
				SetConsoleTextAttribute(color, LIGHT_GREEN);
				std::cout << "O commit '" << msgCommand << "' foi adicionado!";
				SetConsoleTextAttribute(color, LIGHT_WHITE);
			}else{
				SetConsoleTextAttribute(color, LIGHT_CYAN);
				std::cout << "\n@commit ";
				SetConsoleTextAttribute(color, LIGHT_WHITE);
				std::cout << "log: ERRO => ";
				SetConsoleTextAttribute(color, DARK_RED);
				std::cout << "O arquivo '" << file_mod << "' nao foi modificado!";
				SetConsoleTextAttribute(color, LIGHT_WHITE);
			}
		}else{
			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "\n@commit ";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "log: INFO => ";
			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "A mensagem '" << msgCommand << "' ja foi commitada.";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
		}

	}else{
		bool exist_commit = false;
		for(int i = 0; i < count_commit; i++)
			if(info["INFOS"]["commits"][i]["msg"] == msgCommand.c_str())
				exist_commit = true;

		if(exist_commit){
			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "\n@commit ";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "log: INFO => ";
			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "A mensagem '" << msgCommand << "' ja foi commitada.";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
		}else{
			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "\n@commit ";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "log: AVISO => ";
			SetConsoleTextAttribute(color, DARK_YELLOW);
			std::cout << "A mensagem '" << msgCommand << "' sera adicionado no proximo commit!";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			count_recursive++;
		}
	}
	
}

// @description Função do comando description para descrições de commits
void descriptionCommand(char *line){
	string msgCommand = getString(line, "@description");

	if(last_commited){

		bool exist_descr = false;
		count_descr = info["INFOS"]["commits"][count_commit]["desc"].size();
		for(int i = 0; i < count_descr; i++)
			if(info["INFOS"]["commits"][count_commit]["desc"][i] == msgCommand.c_str())
				exist_descr = true;

		if(!exist_descr){

			info["INFOS"]["commits"][count_commit]["desc"][count_descr] = msgCommand.c_str();
			
			writeJSONFile("infos/info.json", info);

			SetConsoleTextAttribute(color, LIGHT_CYAN);
			std::cout << "\n@description ";
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			std::cout << "log: ";
			SetConsoleTextAttribute(color, LIGHT_GREEN);
			std::cout << "A descricao '" << msgCommand << "' foi adicionado!" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);

		}
	}
	
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

	is_modified = verifyModification(is_read);
	
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
					runCommit(is_read);
					initCommand();
					checkStateFiles();
					block_symbol = true;
					is_modified = verifyModification(true);
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
				string msgCommand = getString(line, "@branch");
				contain_branch = true;
				branch_str = msgCommand;
				
			}

		}

		if(contains(line, end_comment)) block_symbol = false;

	}

	runCommit(is_read);

}

bool verifyModification(bool is_read){
	for(int i = 0; i < paths["modifieds"].size(); i++){
		string file_name = paths["modifieds"][i];
		if(is_read){
			file_mod = cli_file;
			if(file_name == cli_file)
				return true;
		}else{
			string file_path = paths["paths"][count_init];
			file_mod = file_path;
			if(file_name == file_path)
				return true;
		}
	}
	return false;
}

void runCommit(bool is_read){
	if(commited){
		
		if(contain_branch)
			branchCommand();
		
		int sizeDescription = info["INFOS"]["commits"][count_commit]["desc"].size();

		stringstream git_add_conc;

		if(is_read)
			git_add_conc << "git add " << cli_file;
		else{
			string file_name = paths["paths"][count_init];
			git_add_conc << "git add " << file_name;
		}

		string git_add = git_add_conc.str();

		stringstream git_commit_conc;
		git_commit_conc << "git commit -m " << info["INFOS"]["commits"][count_commit]["msg"];

		for(int i = 0; i < sizeDescription; i++){
			string msgDescription = info["INFOS"]["commits"][count_commit]["desc"][i];
			git_commit_conc << " -m \"" << "* " << msgDescription << "\"";
		}
		
		git_commit_conc << " >> C:/gitd/logs/log_commit";

		string git_commit = git_commit_conc.str();
		
		SetConsoleTextAttribute(color, LIGHT_CYAN);
		std::cout << "@commit ";
		SetConsoleTextAttribute(color, LIGHT_WHITE);
		std::cout << "log: ";
		SetConsoleTextAttribute(color, LIGHT_GREEN);
		std::cout << "O ultimo commit adicionado esta sendo realizado..." << endl;
		SetConsoleTextAttribute(color, LIGHT_WHITE);

		system(git_add.c_str());
		system(git_commit.c_str());
	}

	commited = false;
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
