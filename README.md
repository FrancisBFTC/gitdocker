# GitDocker v0.1.0

### bug fixes

Na atualização da versão 0.0.8 para 0.1.0 foram corrigidos bugs em relação ao comando path e são eles:

* O comando path em comentários de linha não eram lidos
* Comentários após um comentário de bloco não eram processados
* Comentários de blocos que eram fechados na mesma linha registrava no path a fechadura do bloco
* Um comentário na linha final que não terminava com quebra de linha era ignorado

### Funcionalidades/Alterações

* Todas as funções foram reunidas no header "gitfuncs.h"
* O processamento do comando path é chamado por uma função
* A função configInterpreter() foi alterada pra initProjectRead() e foi completamente refatorada
* O parâmetro --config está deprecado, ao invés disso utilize --init
* A função printJSONConfig() agora apresenta na tela dados JSON formatado de configurações
* Com a função initProjectRead() agora é possível ler qualquer comentário de qualquer linguagem, desde que seja configurada no arquivo "config.json" (Atualmente possui 3 conjuntos de extensões e comentários)
* Coloração de textos apresentados no CMD foram implementadas
* Foram adicionados na pasta "examples" 5 arquivos de extensões diferentes para testar comando path
* O comando path agora contém o parâmetro 'ALL' que define um booleano para permitir a leitura de todos os arquivos

### TODO in v0.1.1 & v0.1.2:

* Criar parâmetro do comando path para ler todos os arquivos de extensões especificadas.
* Testar leitura de arquivos das extensões especificadas/arquivos especificados pelo comando path

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
