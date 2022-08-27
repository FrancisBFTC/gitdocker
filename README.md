# GitDocker v0.1.2

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

Nenhum.

### Features/Updates

1. Divisão do código de leitura das linhas de arquivos para uma função nova - o fileInterpreter().
2. o fileInterpreter() é chamado tanto no initProjectRead() como também no initCommand() que por sua vez também chamará o fileInterpreter(), recursivamente. Os comandos serão processados no fileInterpreter().
3. Nova função adicionada - o initCommand() para processar o comando `@init`.
4. Leitura de linhas dos arquivos individuais especificados no comando `@path` após a chamada do comando `@init`.
5. Novas variáveis booleanas adicionadas - o **path_defined** e o **reading_file**. A 1ª variável é definida para **true** se o GitDocker identifica o comando `@path` e a 2ª variável é definida para **true** se a leitura de arquivo no fileInterpreter() se trata do comando `@init`.
6. Novos comandos de testes adicionados - o **@branch** e o **@commit**.
7. O novo array JSON **ignore** no objeto **INIT** do arquivo **config.json** foi adicionado com 4 extensões pré-definidas.
8. Foi implementado um loop dentro do initCommand() na leitura de arquivos do comando `@path` com intuito de verificar as extensões pré-definidas no array JSON **ignore** a fim de ignorar a leitura de arquivos que contenha estas extensões.
9. Novos arquivos de exemplos foram adicionados na pasta **examples** para testar os novos recursos.

### TODO

1. Implementar na versão 0.1.3 a leitura de arquivos com extensões pré-definidas no parâmetro `[all: ...]` do comando `@path` a partir do comando `@init`.
2. Implementar na versão 0.1.3 a leitura de **todos** os arquivos de um dado diretório configurado no objeto JSON **INIT** inserido no comando `@path` a partir do comando `@init` (respeitando o array JSON **ignore** do mesmo objeto).
3. Corrigir bug desta versão 0.1.2 para a versão 0.1.3 relacionado a leitura do nome `@path` em códigos que estão fora de comentários, isso surgiu devido as novas modificações onde arquivos são lidos de forma recursiva.
4. Iniciar a implementação dos comandos `@commit` e `@description` na versão 0.1.4 na preparação de migração de versão de 0.1.4 para 0.2.0.

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
