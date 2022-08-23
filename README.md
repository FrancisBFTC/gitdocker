# gitdocker

Este é um projeto dedicado criar documentações automáticas durante um desenvolvimento de softwares e ao mesmo tempo realizar comandos do git para versionamento de código.

<a name="menu"></a>
  * <a href="#what"> O que é este sistema? </a>
  * <a href="#how"> Como funciona? </a>
  * <a href="#comp"> Compilando Projeto </a>
  * <a href="#param"> Parâmetros do GitDocker </a>
    * <a href="#param-init">  Parâmetro --init </a>
    * <a href="#param-show">  Parâmetro --show-config </a>
  * <a href="#comm"> Exemplos de Comandos Interpretáveis</a>
    * <a href="#comm-path"> Comando Path</a>
  * <a href="#colab"> Colaborações </a>
  * <a href="#ver"> Versões do Projeto </a>

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

   ```
    gcc -std=c++11
    g++ -std=c++11
   ```
   
 6. Clique em OK.

Caso optar por executar o `Build.bat`, ignore estas etapas. Agora vamos configurar a dependência do GitDocker que é um json-parser. Usamos esta dependência no projeto pois a maior parte das configurações do GitDocker são feitos por arquivos JSON, como também o software gera/altera estes tipos de arquivos, para configurar é bem simples, primeiro clone em sua máquina usando o git o repositório json do nlohmann, desta forma:

```
 git clone https://github.com/nlohmann/json.git
```

Após isto, entra na pasta `json` clonada do repositório e dentro dela entre na pasta `include`, copie a pasta `nlohmann/` e cole na sua pasta `include` do G++, que fica no diretório: `C:\Program Files (x86)\Dev-Cpp\MinGW64\include` ou `C:\Program Files\Dev-Cpp\MinGW64\include` e também dentro do diretório `C:\Program Files (x86)\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include` ou `C:\Program Files\Dev-Cpp\MinGW64\x86_64-w64-mingw32\include`, isto claramente se você estiver instalado seu G++ junto com a IDE DevC++ que foi o meu caso, se não for, procure a pasta include do seu G++ e cole a pasta copiada.

Agora é só compilar o projeto pelo Build.bat e ser feliz! 

<a name="param"></a>
## Parâmetros do GitDocker

O Gitdocker contém parâmetros para configurar o projeto, criar documentações e versionamento de código junto ao git em tempo de desenvolvimento, antes de tudo navegue até a pasta do seu projeto utilizando o comando CD e só após execute o gitdocker com seus parâmetros. Abaixo serão listados os parâmetros disponíveis:

<a name="param-init"></a>
### Parâmetro --init

Através do parâmetro --init ou -i é possível ler comandos iniciais em um arquivo de código-fonte principal. Dentro deste arquivo poderá ter qualquer comando processável pelo Gitdocker, tanto em comentários de linha como em comentários de blocos. A função do --init é inicializar as configurações pra um projeto, como: Definir commits e descriptions principais, gerar READMEs, definir quais arquivos do projeto serão interpretados e diversas outras coisas. Antes de qualquer processamento do gitdocker, é necessário executar primeiramente este parâmetro:

``` 
 gitdocker --init [arquivo.extensão] 
```

ou

``` 
 gitdocker -i [arquivo.extensão] 
```

_Nota : o argumento **[arquivo.extensão]** pode ser qualquer arquivo ou diretório completo onde **'arquivo'** é o nome do seu arquivo e **'.extensão'** é a extensão do seu arquivo, Exemplo: program.cpp_

<a name="param-show"></a>
### Parâmetro --show-config

O --show-config como o próprio nome diz, apresenta ao usuário informações de configurações JSON com um visual formatado. No diretório **'/configs'** existe um arquivo chamado `config.json`, neste arquivo pode ser configurado pelo usuário as regras de versões do seu projeto atual e novas extensões de linguagens de programação. No entanto este arquivo já contém extensões de algumas linguagens, que são identificadas pelo gitdocker para filtrar símbolos de comentários e processar os comandos, para visualizar estas configurações basta digitar:

``` 
 gitdocker --show-config 
```

ou

``` 
 gitdocker -sc 
```
<a name="comm"></a>
## Exemplos de Comandos Interpretáveis

Os comandos interpretáveis são palavras-chaves escritas em comentários de código-fonte no qual o executável GitDocker irá ler e processar uma determinada tarefa. Todos os comandos tem um prefixo @ antes da palavra-chave e podem ser precedidos de um ou mais parâmetros ou nenhum parâmetro. Cada comando no GitDocker tem sua própria tarefa, efetuando ações desde a documentação de projeto personalizado até o versionamento de código automatizado com a utilização da ferramenta git, no entanto é necessário ler um arquivo inicial através do parâmetro de linha de comando --init, que irá ler e processar todos os comandos digitados no arquivo. Abaixo vamos as descrições e exemplos dos comandos disponíveis. 

<a name="comm-path"></a>
### Comando PATH

O comando @path serve pra registrar arquivos ou diretórios em um objeto JSON. Os dados são armazenados neste objeto para serem lidos posteriormente. A função do comando @path é registrar para o GitDocker saber quais arquivos ele deve processar dentro de um projeto, lendo os diversos comandos de commit, descriptions e outros em arquivos de código-fonte. No entanto, o comando @path pode ser omitido e a partir daí o GitDocker vai considerar apenas os arquivos que foram modificados ou adicionados no projeto. O grande problema disso, é que existem milhares de tipos de arquivos possíveis em diversos projetos onde não existe um código-fonte, como Exemplo: Um executável, uma imagem, um vídeo, etc.. e mesmo descartando esta lista, ainda existem arquivos que contém dados e DSLs (Uma linguagem de domínio específico) que não possuem blocos de comentários e que após modificados, o GitDocker tentará ler mas não encontrará nada, perdendo um bom tempo de processamento, ainda mais se o projeto for muito grande. Então pra resolver este problema, entra o comando @path. 

Este comando atualmente possui 3 tipos de parâmetros:

    1. O nome de um arquivo ou diretório.
    2. Parâmetro [all] que especifica todos os arquivos.
    3. Parâmetro [all: ...] onde as reticências são extensões de arquivos separados por vírgula.

**Nota:** _O Parâmetro [all] irá ler todos os arquivos de um determinado diretório, este diretório pode ser configurado no arquivo config.json (Implementado a partir da versão 0.1.2). Neste diretório pode ficar apenas arquivos de código-fonte, evitando assim problemas e conflitos._

### 1. Registrando arquivos

Vamos supor que você tenha um projeto numa pasta chamada **MyProject** e lá contém o arquivo **main.c** no diretório raiz e existem 2 arquivos na pasta **Includes**: O arquivo **data.h** e **datas.inc**. O seu projeto tem esta seguinte estrutura de pastas:

<img src="https://imgur.com/oLkyHGq.png" alt="Estrutura de pastas de MyProject">

O main.c é o seu código-fonte principal que será compilado pra executável, o data.h e datas.inc são arquivos de cabeçalho de dados para serem incluídos o programa em C. Note que nós temos um novo arquivo que não mencionei - O **gitdock.cpp** (Aliás poderia ser de qualquer extensão desde que seja configurado no config.json, veja na seção ...). Este arquivo é recomendável ser adicionado no projeto pra não houver ambíguidades, pois é a partir dele que o GitDocker vai ler as configurações iniciais. 

Neste arquivo **gitdock.cpp** vamos colocar o comando @path seguindo a imagem abaixo:

<img src="https://imgur.com/HITsmdb.png" alt="Comando path no arquivo gitdock.cpp">

Nesta linha diz que vamos registrar num objeto JSON interno do GitDocker o arquivo **main.c** e este arquivo posteriormente será processado. Poderemos também fazer da seguinte maneira:

<img src="https://imgur.com/rxHQzH9.png" alt="3 Comandos path no arquivo gitdock.cpp">

Perceba que agora nós temos 2 comentários de linha, cada qual com um comando @path lendo um arquivo diferente, ou seja, os arquivos **data.h** e **datas.inc**, especificando também a pasta onde eles estão (Includes). Abaixo dos comentários de linha existe o comentário de bloco usando o comando @path pro arquivo **main.c** e mais abaixo a declaração de 2 Funções em C. Esta imagem é pra demonstrar que não importa a forma que os comentários estão organizados, o comando @path será processado da mesma forma, mesmo inserindo espaços ou tabs entre o @path e o arquivo (Exceto no próprio arquivo, não utilize arquivos com espaços). A declaração de funções e outros códigos serão ignorados pelo GitDocker justamente porque ele só processa os comandos em comentários.

No exemplo da 1ª imagem (Com 1 comando @path), agora vamos executar o GitDocker utilizando o parâmetro --init da seguinte maneira:

```
gitdocker --init gitdock.cpp
```

O --init vai inicializar o projeto lendo o arquivo gitdock.cpp, dentro dele vai ler o parâmetro do comando @path, que é o arquivo main.cpp e o resultado seria:

<img src="https://imgur.com/N9yof38.png" alt="Strings de 1 Log do comando path no CMD">

Mas no caso da 2ª imagem (Com 3 comandos @path), fazendo o mesmo procedimento que antes no terminal: `gitdocker --init gitdock.cpp`, teríamos este resultado:

<img src="https://imgur.com/HvnswO8.png" alt="Strings de 3 Logs do comando path no CMD">

Perceba que na 1ª imagem do terminal do VSCode nós temos uma mensagem de log do @path dizendo que está registrando o arquivo main.cpp e abaixo é apresentado um objeto JSON com o nome do arquivo especificado. Cada vez que é usado o comando @path, um novo índice é adicionado neste array JSON com um novo arquivo, é assim que funciona o registro de arquivos pelo GitDocker. Na 2ª imagem feito no próprio CMD, temos 3 logs do @path e 3 arquivos do objeto JSON do @path. Também temos outro índice do mesmo objeto chamado de "exts", que é um array json que inicialmente é nulo, como visto na tela (Falaremos sobre isso posteriormente).

O que significa que, os arquivos que tiverem registrados neste objeto JSON, serão lidos pelo GitDocker e processados com outros comandos, descartando os arquivos que foram modificados lidos pela ferramenta git.

### 2. Registrando TODOS os arquivos

; TODO fazer descrições do parâmetro [all]

<a name="colab"></a>
## Colaborações

Antes de tudo, dê um Fork no Projeto e clone o repositório em sua máquina, crie uma nova branch seguindo o padrão de versões do gitdocker:

**Criando uma branch -->**

<code>
git checkout -b gitdocker-v0.0.x
</code>
<br><br>

Obs.: 'x' deve ser um número acima da última versão criada do gitdocker. Se por exemplo o gitdocker está na versão v1.0.1, sabemos que sua branch deve ser v1.0.2 e assim por diante.

Nesta nova versão adicione suas funções, Exemplo: Um novo parâmetro da CLI e uma nova função, efetua os testes, tudo funcionando então dê o git push ao Github. Entre no meu repositório do Gitdocker na Branch Main e abra a sessão de Pull Request, crie uma nova Pull Request, escolha seu repositório atualizado e escreva um comentário dizendo quais foram as suas alterações.

Com isto irei analisar o código e verificar se posso fazer o merge com a branch main.

<a name="ver"></a>
## Versões do Projeto

Segue abaixo uma lista de versões de desenvolvimento do GitDocker:

* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.1"> Versão 0.0.1 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.2"> Versão 0.0.2 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.3"> Versão 0.0.3 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.4"> Versão 0.0.4 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.0.8"> Versão 0.0.8 </a>
* <a href="https://github.com/FrancisBFTC/gitdocker/tree/gitdocker-v0.1.0"> Versão 0.1.0 </a>
