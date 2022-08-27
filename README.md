<a name="title"></a>
# GitDocker v0.1.4

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

* A função readAllDirectory() não lia exatamente todos os sub-diretórios, ela só lia diretórios e sub-diretórios da pasta raiz, foi corrigido e testado esta parte adicionando uma variável de concatenação de diretórios **conc** e um booleano **is_folder**, ainda utilizando a biblioteca **dirent.h**.
* A filtragem de símbolos de comentários era feita apenas no início da função initProjectRead(), ou seja, no arquivo principal. Quando era lido vários arquivos pelo parâmetro `[all]` ou `[all: ...]`, mesmo sendo outras extensões os símbolos de comentários permaneciam os mesmos, então a filtragem foi dividida para uma função que é chamada em readAllDirectory() e initProjectRead() para alterar dinamicamente os símbolos de comentários pra cada extensão lida no momento.
* O diretório do objeto **dir** no objeto **INIT** do arquivo **config.json** não era processado, para isto foi adicionado em initCommand() como parâmetro da função readAllDirectory() uma variável de concatenação que recebe inicialmente o valor do objeto JSON **dir**, também em readAllDirectory() é concatenado o diretório principal com o diretório/arquivo lido atualmente.

### Features/Updates

* Todos os arquivos pelo comando `@path [all]` são lidos e processados através da função initCommand().
* Todos os arquivos de extensões pré-definidas pelo comando `@path [all: ...]` são lidos e processados através da função initCommand().
* Uma filtragem de extensões do **config.json** é feita antes de ler qualquer arquivo tanto pelo parâmetro `[all]` quanto pelo parâmetro `[all: ...]` na função readAllDirectory().
* Um diretório base principal pode ser lido para o parâmetro `[all]` e `[all: ...]` do comando `@path` configurando no arquivo **config.json**.
* O comando de teste `@description` foi adicionado.
* Novos arquivos de testes adicionados.

### TODO

* Implementar comando `@commit` a partir da versão v0.2.0
* Implementar comando `@description` a partir da versão v0.2.0
* Iniciar a criação do parâmetro **--search** na CLI.

<a name="ver"></a>

## Versões do Projeto

Segue abaixo uma lista de versões de desenvolvimento do GitDocker:

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.1"> Versão 0.0.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.2"> Versão 0.0.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.3"> Versão 0.0.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.4"> Versão 0.0.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.8"> Versão 0.0.8 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.0"> Versão 0.1.0 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.1"> Versão 0.1.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.2"> Versão 0.1.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.3"> Versão 0.1.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.4"> Versão 0.1.4 </a>

### <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.0"> Versão 0.2.0 </a>
