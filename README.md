<a name="title"></a>
# GitDocker v0.2.0

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Descrição da v0.2.0

Na introdução da versão v0.2.0 foi iniciado a implementação dos comandos commit e description no qual é filtrado as mensagens após os comandos através de uma nova função getString(). Também foi adicionado uma nova extensão no config.json que permite ter um arquivo principal com a sintaxe da linguagem do GitDocker.

### Bug Fixes

Nenhum.

### Features/Updates

- Inicio da implementação do comando `@commit` filtrando uma mensagem através da função getString().
- Inicio da implementação do comando `@description` filtrando uma mensagem através da função getString().
- Criação de um novo arquivo chamado **lang.gitdock** que terá um script básico inicial para o parâmetro --init.
- Criação de uma nova extensão no **config.json** que permite ler um bloco com o script do GitDocker.

### TODO

- [x] Criação de novos valores JSON no **info.json** para leitura e escrita de informações, Ex.: Commits & Descriptions.
- [x] Concluir a implementação do comando `@commit` considerando apenas o último commit escrito.
- [x] Concluir a implementação do comando `@description` filtrando todas as últimas descrições escritas para mesclagem com o último commit.

## Versões do Projeto

Segue abaixo uma lista de versões de desenvolvimento do GitDocker:

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.1#title"> Versão 0.0.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.2#title"> Versão 0.0.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.3#title"> Versão 0.0.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.4#title"> Versão 0.0.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.8#title"> Versão 0.0.8 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.0#title"> Versão 0.1.0 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.1#title"> Versão 0.1.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.2#title"> Versão 0.1.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.3#title"> Versão 0.1.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.4#title"> Versão 0.1.4 </a>

### <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.0#title"> Versão 0.2.0 </a>

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.1#title"> Versão 0.2.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.2#title"> Versão 0.2.2 </a>
