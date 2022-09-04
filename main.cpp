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
			
			if(argv[3] != NULL)
				if(strcmp(argv[3], "--recursive") == 0 || strcmp(argv[3], "-r") == 0)
					recursive = true;

			cli_file = argv[2];
			initProjectRead(argv[2]);
			if(switched)
				system("gitdocker --merge");
		}
		
		if(strcmp(argv[1], "--show-config") == 0 || strcmp(argv[1], "-sc") == 0){
			SetConsoleTextAttribute(color, LIGHT_GREEN);
			std::cout << "\nLendo Configuracoes...\n" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);

			printJSONConfig();
		}

		if(strcmp(argv[1], "--config") == 0 || strcmp(argv[1], "-c") == 0){
			if(argv[2] != NULL){
				if(strcmp(argv[2], "RULES")){
					SetConsoleTextAttribute(color, LIGHT_GREEN);
					std::cout << "\nConfigurando Regras de Versao..." << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
				}
				if(strcmp(argv[2], "EXTENSIONS")){
					SetConsoleTextAttribute(color, LIGHT_GREEN);
					std::cout << "\nConfigurando Extensoes..." << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
				}
				if(strcmp(argv[2], "INIT")){
					SetConsoleTextAttribute(color, LIGHT_GREEN);
					std::cout << "\nConfigurando Inicializacao..." << endl;
					SetConsoleTextAttribute(color, LIGHT_WHITE);
				}

				bool can_config = true;

				if(strcmp(argv[2], "RULES") == 0 && argc > 3){
					rules_arg = true;
				
					for(int i = 3; i < argc; i++){
						if(strcmp(argv[i], "--major") == 0 || strcmp(argv[i], "-ma") == 0){
							if(argv[i+1] != NULL){
								param_major = true;
								major_str = argv[i+1];
							}else{
								SetConsoleTextAttribute(color, LIGHT_RED);
								std::cout << "\nO parametro --major espera um valor!" << endl;
								SetConsoleTextAttribute(color, LIGHT_WHITE);
								can_config = false;
								break;
							}
						}else{
							if(strcmp(argv[i], "--minor") == 0 || strcmp(argv[i], "-mi") == 0){
								if(argv[i+1] != NULL){
									param_minor = true;
									minor_str = argv[i+1];
								}else{
									SetConsoleTextAttribute(color, LIGHT_RED);
									std::cout << "\nO parametro --minor espera um valor!" << endl;
									SetConsoleTextAttribute(color, LIGHT_WHITE);
									can_config = false;
									break;
								}
							}else{
								if(strcmp(argv[i], "--patch") == 0 || strcmp(argv[i], "-pa") == 0){
									if(argv[i+1] != NULL){
										param_patch = true;
										patch_str = argv[i+1];
									}else{
										SetConsoleTextAttribute(color, LIGHT_RED);
										std::cout << "\nO parametro --patch espera um valor!" << endl;
										SetConsoleTextAttribute(color, LIGHT_WHITE);
										can_config = false;
										break;
									}
								}
							}
						}
					}

				}else{
					if(strcmp(argv[2], "EXTENSIONS") == 0 && argc > 3){
						exts_arg = true;
						for(int i = 3; i < argc; i++){
							if(strcmp(argv[i], "--lang") == 0 || strcmp(argv[i], "-l") == 0){
								if(argv[i+1] != NULL){
									param_lang = true;
									lang_str = argv[i+1];
								}else{
									SetConsoleTextAttribute(color, LIGHT_RED);
									std::cout << "\nO parametro " << argv[i] << " espera um valor!" << endl;
									SetConsoleTextAttribute(color, LIGHT_WHITE);
									can_config = false;
									break;
								}
							}

							if(strcmp(argv[i], "--reset") == 0 || strcmp(argv[i], "-re") == 0)
								reset_ext = true;
						}
					}else{
						if(strcmp(argv[2], "INIT") == 0 && argc > 3){
							init_arg = true;

							for(int i = 3; i < argc; i++){
								if(strcmp(argv[i], "--dir") == 0 || strcmp(argv[i], "-d") == 0){
									if(argv[i+1] != NULL){
										param_dir = true;
										dir_str = argv[i+1];
									}else{
										SetConsoleTextAttribute(color, LIGHT_RED);
										std::cout << "\nO parametro " << argv[i] << " espera um valor!" << endl;
										SetConsoleTextAttribute(color, LIGHT_WHITE);
										can_config = false;
										break;
									}
								}else{
									if(strcmp(argv[i], "--ignore") == 0 || strcmp(argv[i], "-ig") == 0){
										if(argv[i+1] != NULL){
											param_ignore = true;
											ignore_str = argv[i+1];
										}else{
											SetConsoleTextAttribute(color, LIGHT_RED);
											std::cout << "\nO parametro " << argv[i] << " espera um valor!" << endl;
											SetConsoleTextAttribute(color, LIGHT_WHITE);
											can_config = false;
											break;
										}
									}
								}

								if(strcmp(argv[i], "--reset") == 0 || strcmp(argv[i], "-re") == 0)
									reset_ext = true;
							}

						}
					}


				}

			if(can_config)
				configExecute(argv[2]);


			}else{
				SetConsoleTextAttribute(color, LIGHT_RED);
				std::cout << "\nO parametro --config espera um valor!" << endl;
				SetConsoleTextAttribute(color, LIGHT_WHITE);
			}

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
			mergeExecute();
		}

		if(strcmp(argv[1], "--config-project") == 0 || strcmp(argv[1], "-cp") == 0){
			SetConsoleTextAttribute(color, LIGHT_GREEN);
			std::cout << "\nConfigurando Projeto...\n" << endl;
			SetConsoleTextAttribute(color, LIGHT_WHITE);

			
		}

		if(strcmp(argv[1], "--version") == 0 || strcmp(argv[1], "-v") == 0){
			std::cout << "\nGitDocker v0.3.0 Build 202209\n" << endl;
		}
		
	}else{
		showInfoHelp();
	}
	
	return 0;
}
