#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <sstream>

using namespace std;

bool contains(char*, string);


int main(int argc, char** argv) {
	
	FILE *file;
	if(argc > 1){
		if(contains(argv[1], ".json")){
			if((file = fopen(argv[1], "r")) == NULL){
				printf("\nErro em abrir o arquivo para leitura!\n");
				return 1;	
			}
			
			char line[1024];
			printf("\nArquivo aberto com sucesso\n");
			while(fgets(line, sizeof(line), file) != NULL){
				printf("%s", line);
			}
			
			
			fclose(file);
		}else{
			printf("\nO arquivo nao e um arquivo JSON!\n");
		}
		
		
	}else{
		printf("O GitDocker espera ao menos 1 argumento");
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
