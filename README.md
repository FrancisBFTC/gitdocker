<a name="title"></a>
# GitDocker v0.2.1

A partir desta versão é possível efetuar commits e descriptions em diversos arquivos. Ao invés de digitar 2 comandos (git add e git commit) x a quantidade de arquivos lidos, o que levaria muito tempo, o GitDocker agora trabalha com mensagens de commits automatizadas a nível do código-fonte, podendo assim economizar mais tempo na produção de software.

### Bug Fixes

* Adaptação de String C++ para String C das mensagens de commits e descriptions na função getString(), pois as mensagens estavam vindo com o caractere nulo.

### Features/Updates

* Criação de 2 variáveis de tamanho - o **count_commit** e o **count_descr** que armazenam o tamanho dos arrays de commit e descriptions, respectivamente, do **info.json** para representar o novo índice de commits e descriptions.
* Adaptação do array **commits[]** no arquivo **info.json** onde cada índice terá a mensagem de commit e pra cada commit um array de descrições.
* Nova função adicionada chamada **writeJSONFile()** que aceita 2 parâmetros: o diretório do arquivo e os dados JSON. Esta função armazena no arquivo especificado um dado json.
* Implementação dos comandos `@commit` e `@description` através de 2 funções: o **commitCommand()** e o **descriptionCommand()**. Cada função primeiro verifica se existe uma mensagem de commit ou descrição armazenada no info.json, caso não existir, ele armazena a mensagem do comando `@commit` ou `@description` na variável json **info** e atualiza o arquivo **info.json** com os dados de **info**. Uma vez commitado, não é possível commitar vários commits em um mesmo arquivo numa única execução, apenas se for arquivos diferentes ou execuções diferentes.
* Implementação da função **runCommit()** que de fato efetua os comandos **git add** e **git commit** quando uma nova mensagem foi adicionada ao json **info**. Esta função commita cada arquivo diferente e é chamada antes da execução do comando `@init` e também após a leitura do arquivo atual na função **fileInterpreter()**.

### TODO

- [x] Corrigir bug que impede os comandos `@commit` e `@description` serem realizados após o comando `@init` no arquivo principal pelo parâmetro **--init** via CLI.
- [ ]  Iniciar implementação do parâmetro **--search** na CLI.
- [ ]  Iniciar implementação do comando `@branch` que efetuará o git checkout e o git push.

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

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.1"> Versão 0.2.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.2"> Versão 0.2.2 </a>

