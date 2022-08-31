<a name="title"></a>
# GitDocker v0.1.1

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

### Bug Fixes

1. A função toChar() foi adicionado o 2ª parâmetro char* e removido o retorno, motivos: Não funcionava!
2. No caso de 1 comments lido no sub-array "exts" do objeto "EXTENSIONS" no JSON config, a api json dava erro de leitura em comandos path para arquivos que continham apenas 1 símbolo de comentário, logo a variável end_comments é limpada.

### Features/Updates

1. A função contains() foi substituída por uma linha de retorno.
2. A função de conversão de char* para String 'returnString()' foi deprecado, ao invés disso utilize toString()
3. A função de conversão de String para char* 'returnChar()' foi deprecado, ao invés disso utilize toChar()
4. Uma nova condição foi adicionada para o comando Path, que armazena em um objeto JSON cada extensão lida do Path, desta forma o Path pode registrar todas as extensões especificadas pelo parâmetro [all: ...]
5. O parâmetro all do comando Path foi deprecado, ao invés disso utilize [all]
6. Uma nova linha de log do comando Path foi adicionada, imprimindo dados de extensões do parâmetro [all: ...]

### TODO 

Efetuar os primeiros testes de leitura de arquivos especificados no comando Path a partir do parâmetro --init na linha de comando na versão posterior (v.0.1.2)

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
