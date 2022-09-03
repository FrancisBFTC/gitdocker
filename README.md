<a name="title"></a>
# GitDocker v0.1.3

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

* Processamento de comandos fora de comentários foram corrigidos criando 2 novos booleanos, o **block_symbol** e o **line_symbol**. Todo o código da função fileInterpreter() foi refatorado.
* Processamento de comandos `@path` e `@init` em outros arquivos são evitados. Estes comandos só são executados no arquivo principal passado pelo parâmetro **--init** via CLI. Isso foi feito adicionando uma condicional dentro do fileInterpreter().

### Features/Updates

* Processamento de todos os arquivos pelo `@init` após o comando `@path [all]`, através da função **readAllDirectory()**.
* A função readAllDirectory() foi implementada para ler recursivamente todos os arquivos de um dado diretório, a função executa também outra função chamada **runningInitWIgnore()**.
* A função runningInitWIgnore() foi implementada para só interpretar comandos em arquivos quando passa do teste de arquivos ignorados, isto é, quando as extensões processadas são diferentes das extensões ignoradas. Esta função é chamada no initCommand() e no readAllDirectory().
* o valor JSON **dir** foi adicionado dentro do objeto **INIT** no arquivo **config.json** para armazenar o diretório principal onde o processamento de todos os arquivos será operado, este valor é passado como argumento da função readAllDirectory(), porém há um problema de reconhecimento.


### TODO

* Corrigir problema de reconhecimento de **diretório principal** na operação do parâmetro `[all]` para v0.1.4.
* Processar todos os arquivos com extensões pré-definidas pelo `[all: ...]` dentro de initCommand() para v0.1.4.
* Filtrar extensões no config.json para permitir que o comando @init processe apenas eles para v0.1.4.

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
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.3#title"> Versão 0.2.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.4#title"> Versão 0.2.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.5#title"> Versão 0.2.5 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.6#title"> Versão 0.2.6 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.2.7#title"> Versão 0.2.7 </a>
