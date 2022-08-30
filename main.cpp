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
			SetConsoleTextAttribute(color, LIGHT_GREEN);
			std::cout << "\nInicializando Projeto...\n" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);
			
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
		
	}else{
		showInfoHelp();
	}
	
	return 0;
}
