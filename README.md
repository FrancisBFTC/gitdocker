# gitdocker

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

<a name="menu"></a>
  * <a href="#what"> O que é este sistema? </a>
  * <a href="#how"> Como funciona? </a>
  * <a href="#comp"> Compilando Projeto </a>
  * <a href="#param"> Parâmetros do GitDocker </a>
    * <a href="#param-init">  Parâmetro --init </a>
    * <a href="#param-show">  Parâmetro --show-config </a>

<a name="what"></a>
## O que é este sistema?

É um sistema que terá geradores README automatizados, geradores de mensagens de commit e geradores de descrições de commit, tudo automaticamente. Todos os processos do git, do git push ao merge, serão uma sequência de tarefas automáticas que o programador fará diariamente, isso facilitará o processo de documentação do software. O programador se preocupará apenas em adicionar comentários de linha no código-fonte com comandos interpretáveis pelo aplicativo de controle de versão. A outra ideia que também facilitará é o processo de contagem de versões. A cada build que o programador fizer em seu sistema, o contador de versões poderá incrementar em um arquivo de versão todos os números que ele programou. Um exemplo: em pequenas modificações e correções de bugs, o último número será incrementado, mas o programador poderá configurar suas próprias regras de versão definindo limites numéricos de forma programada, ou definindo em tempo real quando o número da 2ª versão pode ser incrementado , e pode ser repensado nisso como um arquivo de configuração para interpretar comandos em comentários de linha.

Este aplicativo pode ser integrado em qualquer software de compilação ou sistema operacional. E o programador, enquanto desenvolve, pode criar a documentação de seu software, simultaneamente.

<a name="how"></a>
## Como funciona?

O executável de controle de versão leria todo o código-fonte procurando diretivas nos comentários, interpretaria e criaria arquivos de dados pré-formatados e JSONs para serem lidos por um ShellScript (ou código em C) enquanto o enviavam para o github. A princípio o aplicativo irá identificar a extensão da linguagem, fará uma comparação de um vetor enorme (ou estrutura JSON) para identificar a linguagem e descobrir qual símbolo é utilizado para comentários, após isso ele irá analisar todos os comentários, procurando tags de documentação, fazendo a interpretação e processamento necessário para documentação e controle de versão, tudo direto no próprio código-fonte, a partir de qualquer linguagem de programação. Assim este estará disponível e acessível a todos os tipos de programadores, contendo convenções que serão conhecidas e ensinadas através de tutoriais.

<a name="comp"></a>
## Compilando Projeto

Antes de tudo certifique-se que você está na plataforma Windows pois atualmente na data de hoje (22/08/2022) não foi implementado ainda a compatibilidade com plataforma Linux, para isto ainda utilizarei diretivas de compilação e um outro MakeFile/Build e alterarei este README. Porém atualmente no repositório contém um arquivo chamado `Build.bat` que terá as linhas de comando para compilar o projeto usando o parâmetro adicional -std=C++11 e aqui há um detalhe **muito importante**: este parâmetro é essencial pra executar uma dependência do projeto que é um json-parser clonado de outro repositório, então se você decidir executar o `GitDocker.dev` para abrir a IDE DevC++, certifique-se de configurar sua IDE pra executar o g++ usando -std=C++11, as instruções para isto está logo abaixo:

 1. Abra o projeto com DevC++
 2. Vá na aba **Ferramentas**
 3. Escolha **Opções do Compilador**
 4. Na janela que abrir, clique em **Programas**
 5. Nos campos de textos do gcc e g++ adicione -std=c++11, ficando assim

   `
    gcc -std=c++11
    
    g++ -std=c++11
   `
   
 6. Clique em OK.

Caso optar por executar o `Build.bat`, ignore estas etapas. Agora vamos configurar a dependência do GitDocker que é um json-parser. Usamos esta dependência no projeto pois a maior parte das configurações do GitDocker são feitos por arquivos JSON, como também o software gera/altera estes tipos de arquivos, para configurar é bem simples, primeiro clone em sua máquina usando o git o repositório json do nlohmann, desta forma:

`git clone https://github.com/nlohmann/json.git`

Após isto, entra na pasta `json` clonada do repositório e dentro dela entre na pasta `include`, copie a pasta `nlohmann/` e cole na sua pasta `include` do G++, que fica no diretório: `C:\Program Files (x86)\Dev-Cpp\MinGW64\include` ou `C:\Program Files\Dev-Cpp\MinGW64\include` e também dentro do diretório `C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include` ou `C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include`, isto claramente se você estiver instalado seu G++ junto com a IDE DevC++ que foi o meu caso, se não for, procure a pasta include do seu G++ e cole a pasta copiada.

Agora é só compilar o projeto pelo Build.bat e ser feliz! 

<a name="param"></a>
## Parâmetros do GitDocker

O Gitdocker contém parâmetros para configurar o projeto, criar documentações e versionamento de código junto ao git em tempo de desenvolvimento, antes de tudo navegue até a pasta do seu projeto utilizando o comando CD e só após execute o gitdocker com seus parâmetros. Abaixo serão listados os parâmetros disponíveis:

<a name="param-init"></a>
### Parâmetro --init

Através do parâmetro --init ou -i é possível ler comandos iniciais em um arquivo de código-fonte principal. Dentro deste arquivo poderá ter qualquer comando processável pelo Gitdocker, tanto em comentários de linha como em comentários de blocos. A função do --init é inicializar as configurações pra um projeto, como: Definir commits e descriptions principais, gerar READMEs, definir quais arquivos do projeto serão interpretados e diversas outras coisas. Antes de qualquer processamento do gitdocker, é necessário executar primeiramente este parâmetro:

` gitdocker --init [arquivo.extensão] `

ou

` gitdocker -i [arquivo.extensão] `

_Nota : o argumento **[arquivo.extensão]** pode ser qualquer arquivo ou diretório completo onde **'arquivo'** é o nome do seu arquivo e **'.extensão'** é a extensão do seu arquivo, Exemplo: program.cpp_

<a name="param-show"></a>
### Parâmetro --show-config

O --show-config como o próprio nome diz, apresenta ao usuário informações de configurações JSON com um visual formatado. No diretório **'/configs'** existe um arquivo chamado `config.json`, neste arquivo pode ser configurado pelo usuário as regras de versões do seu projeto atual e novas extensões de linguagens de programação. No entanto este arquivo já contém extensões de algumas linguagens, que são identificadas pelo gitdocker para filtrar símbolos de comentários e processar os comandos, para visualizar estas configurações basta digitar:

` gitdocker --show-config`

ou

` gitdocker -sc `

## Para colaboradores

Antes de tudo, dê um Fork no Projeto e clone o repositório em sua máquina, crie uma nova branch seguindo o padrão de versões do gitdocker:

**Criando uma branch -->**

<code>
git checkout -b gitdocker-v0.0.x
</code>
<br><br>

Obs.: 'x' deve ser um número acima da última versão criada do gitdocker. Se por exemplo o gitdocker está na versão v1.0.1, sabemos que sua branch deve ser v1.0.2 e assim por diante.

Nesta nova versão adicione suas funções, Exemplo: Um novo parâmetro da CLI e uma nova função, efetua os testes, tudo funcionando então dê o git push ao Github. Entre no meu repositório do Gitdocker na Branch Main e abra a sessão de Pull Request, crie uma nova Pull Request, escolha seu repositório atualizado e escreva um comentário dizendo quais foram as suas alterações.

Com isto irei analisar o código e verificar se posso fazer o merge com a branch main.

## Versões do Projeto

Segue abaixo uma lista de versões de desenvolvimento do GitDocker:

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.1"> Versão 0.0.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.2"> Versão 0.0.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.3"> Versão 0.0.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.4"> Versão 0.0.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.8"> Versão 0.0.8 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.0"> Versão 0.1.0 </a>
