/*   
	Author: Wender Francis
	GitDocker v0.1.0
	
	@branch gitdocker-v0.1.0
	@commit Software de documentação e versionamento
	@description Este software irá automatizar a documentação durante o desenvolvimento
				e fornecer uma série de recursos pra integração com o GIT

*/


#include "gitfuncs.h"


//@description Adiciona 2 argumentos no MAIN
int main(int argc, char** argv) {
	
	color = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if(argc > 1){
		if(strcmp(argv[1], "--init") == 0 || strcmp(argv[1], "-i") == 0){
			if(!recursive){
				SetConsoleTextAttribute(color, LIGHT_GREEN);
				std::cout << "\nInicializando Projeto...\n" << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);
			}else{
				SetConsoleTextAttribute(color, LIGHT_GREEN);
				std::cout << "\nReinicializacao...\n" << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);
			}
			
			if(argv[3] != NULL)
				if(strcmp(argv[3], "--recursive") == 0 || strcmp(argv[3], "-r") == 0)
					recursive = true;

			cli_file = argv[2];
			initProjectRead(argv[2]);
		}
		
		if(strcmp(argv[1], "--show-config") == 0 || strcmp(argv[1], "-sc") == 0){
			SetConsoleTextAttribute(color, LIGHT_GREEN);
			std::cout << "\nLendo Configuracoes...\n" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);

			printJSONConfig();
		}

		if(strcmp(argv[1], "--config") == 0 || strcmp(argv[1], "-c") == 0){
			SetConsoleTextAttribute(color, LIGHT_GREEN);
			std::cout << "\nConfigurando Projeto..." << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);

			SetConsoleTextAttribute(color, LIGHT_YELLOW);
			std::cout << "\nEste parametro ainda nao foi implementado nesta versao!" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			// TODO configurar projeto aqui
		}

		if(strcmp(argv[1], "--search") == 0 || strcmp(argv[1], "-s") == 0){
			if(argv[2] != NULL){
				SetConsoleTextAttribute(color, LIGHT_GREEN);
				std::cout << "\nIniciando Pesquisa de Extensoes...\n" << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);

				searchJSONValues(argv[2]);
			}else{
				SetConsoleTextAttribute(color, LIGHT_RED);
				std::cout << "\n--search erro => Nenhum valor foi especificado!" << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);
				std::cout << "Especifique uma extensao, Ex.: gitdocker --search .html" << endl;
			}
		}

		if(strcmp(argv[1], "--merge") == 0){
			std::ifstream f("infos/info.json");
			json infom = json::parse(f);

			string oldbranch = infom["INFOS"]["merge"][0];
			string newbranch = infom["INFOS"]["merge"][1];
			stringstream merge_conc;
			merge_conc << "git merge " << newbranch << " " << oldbranch << " -X theirs";
			system(merge_conc.str().c_str());
			
			string currently = infom["INFOS"]["merge"][1];
			infom["INFOS"]["merge"][0] = currently.c_str();
			//infom["INFOS"]["merge"][1] = " ";
			writeJSONFile("infos/info.json", infom);

			stringstream push_conc;
			push_conc << "git push origin " << newbranch;
			system(push_conc.str().c_str());
		}
		
	}else{
		showInfoHelp();
	}
	
	return 0;
}
