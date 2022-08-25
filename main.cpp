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
		
	}else{
		showInfoHelp();
	}
	
	return 0;
}
