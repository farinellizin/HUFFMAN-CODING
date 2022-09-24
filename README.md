<h1 align = "center">
    Codificação de Huffman
</h1>

<h4 align = "center">
    Este repositório contém a implementação da codificação de Huffman como uma forma de comprimir arquivos .txt, tendo como principal resultado esperado ser possível visualizar a diferença entre o arquivo inicial (.txt) e o arquivo final (.bin).
</h4>

<h2 align="center"> 
   💡<strong><em>Algoritmo </em></strong>
</h2>

<p>
    <d1>
        <dt> 1. Criação das Structs para os desejados tipos de dado; </dt>
        <dt> 2. Leitura do arquivo principal (.txt) </dt>
        <dt> 3. Tokenização do conteúdo do arquivo, ao mesmo passo, realizar o tratamento do conteúdo, filtrar palavras que devem entrar e que não devem, certificar que nenhuma réplica será inserida, além de realizar a contagem de cada palavra; </dt>
        <dt> 4. Realizar o processo acima enquanto ainda houverem palavras não processadas no arquivo e registrar cada processamento em um std::unordered_map;</dt>
        <dt> 5. Obter a quantidade de maior aparecimento e menor aparecimento entre todas as palavras;</dt>
        <dt> 6. Realizar a normalização de todos os valores presentes no std::unordered_map;</dt>
        <dt> 7. Transferir todos os valores do std::unordered_map para um std::vector, que receberá o tipo da Struct criada no passo 1; </dt>
        <dt> 8. Realizar a junção de todos os nós presentes no std::vector de acordo com o que foi proposto por Huffman, até que reste somente um elemento; </dt>
        <dt> 9. Gerar os códigos para cada uma das palavras, seguindo a ideia que foi proposta por Huffman;</dt>
        <dt> 10. Juntar os códigos de cada uma das palavras na mesma ordem que elas aparecem no documento .txt;</dt>
        <dt> 11. Escrever em um arquivo binário;</dt>
        <dt> 12. Analisar o ganho de desempenho, o qual é inversamente proporcional ao tamanho do arquivo binário gerado.</dt>
    </d1>
</p>

<h2 align="center">
    ⚠️
    <strong>
        <em>
            Observações Importantes
        </em>
    </strong>
</h2>

- Para o devido funcionamento do programa, atente-se aos espaços no final de cada uma das linhas:
    - Logo após a última palavra, deve haver um caractere de espaço (" "), **EXCETO** na linha final, a qual **NÃO** pode conter caracteres após o que se deseja que seja o conteúdo final.


<h2 align="center">
    📚
    <strong>
        <em>
            Bibliotecas Utilizadas
        </em>
    </strong>
</h2>

- Para o devido funcionamento do programa, todas as bibliotecas abaixo devem ser inseridas no arquivo **_"arithmetics.hpp"_**:

<table align="center">
    <tr>
        <td> std::iostream </td>    
    </tr>
    <tr>
        <td> std::string </td>    
    </tr>
    <tr>
        <td> std::fstream </td>    
    </tr>
    <tr>
        <td> std::unordered_map </td>    
    </tr>
    <tr>
        <td> std::vector </td>    
    </tr>
</table>

<h2 align="center">
    📄
    <strong>
        <em>
            Arquivos Utilizados
        </em>
    </strong>
</h2>

- Para o devido funcionamento do programa, todos os arquivos abaixo devem ser inseridos no arquivo **_main.cpp_**:

<table align="center">
    <tr>
        <td> arithmetics.hpp </td>    
    </tr>
    <tr>
        <td> extrafunctions.hpp </td>    
    </tr>
    <tr>
        <td> HuffTree.hpp </td>    
    </tr>
    <tr>
        <td> queue.cpp </td>    
    </tr>
</table>

<h2 align="center">
    👨‍💻
    <strong>
        <em> 
            Implementação
        </em>    
    </strong>
</h2>

Inicialmente, foram criadas as **Structs** utilizadas no programa, sendo uma para os valores dos nós das árvores de Huffman, denominada **_Data_**, e a outra, sendo responsável por criar de fato o tipo desejado no programa, cujo nome é **_HuffTree_**, presentes no arquivo *_HuffTree.hpp_*, como pode ser visto abaixo:

```c++
struct Data {
    float normalizedValue;
    string word;
    vector <bool> binaryCodification;
};

struct HuffTree {
    Data item;
    HuffTree *leftSon, *rightSon, *dad;
};
```

As estruturas acima serão vistas, sendo de fato usadas, futuramente no programa.

Após a implementação acima, tem-se a base do que será necessário para de fato, construir a árvore de Huffman, portanto, chega ao ponto de coletar o conteúdo que, de fato, será inserido na mesma.

Para tal, pode ser visto presente no arquivo *_arithmetics.hpp_* as funções responsáveis para o que é necessário. Inicialmente, é chamada a função **_fillMap()_**, cuja proposta é ler todo o arquivo de texto do qual será extraído o conteúdo. Vale salientar que o arquivo é lido ao passo em que suas palavras são tokenizadas, utilizando a função **std::getline()**, utilizando o caractere espaço (' ') como delimitador de palavras. Quando uma palavra é lida, uma variável recebe seu valor, é chamada a função **_stopLetters()_**, que retornará **true** caso seja uma palavra compatível com as "regras" do programa. A implementação da função supracitada pode ser vista abaixo:

```c++
bool stopLetters(string content) {
    if (content.size() == 1) {
        return false;
    }

    return true;
}
```
void writeInFile(vector <bool> &mainVector) {
    FILE *myfile;
    myfile = fopen("text.bin", "wb");
    
    if (myfile != NULL) {
        fwrite(&mainVector, sizeof(bool), mainVector.size(), myfile);
    }
}
Caso a verificação seja verdadeira, a variável é então passada como parâmetro para a função **_stringTreatment()_**, a qual tem como proposta remover caracteres especiais, acentuação e pontuacão: 

```c++
string stringTreatment(string content) {
    string aux;

    for (long unsigned int i = 0; i < content.size(); i++) {
        if (content[i] != '.' && content[i] != ',' && content[i] != '/' && content[i] != ';' && content[i] != ':' && content[i] != '!' && 
        content[i] != '"' && content[i] != '\'' && content[i] != '[' && content[i] != ']' && content[i] != '{' && content[i] != '}' && 
        content[i] != '(' && content[i] != ')' && content[i] != '/' && content[i] != '|' && content[i] != '\\' && 
        content[i] != '*' && content[i] != '-' && content[i] != '+' && content[i] != '?' && content[i] != '.' && content[i] != '\n') {
            content[i] = tolower(content[i]);
            aux += content[i];
        }
    }

    return aux;
}
```

Após todo esse processamento de palavra, chega ao ponto de verificar se a mesma pode ser inserida no **std::unordered_map**. Para tal, a palavra é procurada dentre todas as outras que já foram inseridas, por meio da função built-in **std::unordered_map::find**, caso a palavra seja encontrada, é incrementado um em seu contador, caso contrário, a palavra é inserida, ela mesma a _chave_, e seu contéudo sendo o contador, iniciado em 1. Além da inserção no **std::unordered_map**, é realizada a inserção em um **std::vector**, sendo ele preenchido com todo o conteúdo do texto, independente de repetições ou não, o que será usado futuramente. A função por completo pode ser vista abaixo:

```c++
void fillMap(unordered_map <string, float> *content, string docName, vector <string> *text) {
    string word;
    
    ifstream myfile;
    myfile.open(docName);
    if (myfile.is_open()) {
        while(!myfile.eof()) {
            getline(myfile, word, ' ');
            
            if (stopLetters(word)) {
                word = stringTreatment(word);

                auto item = content -> find(word);
                if (item != content -> end()) {
                    item -> second++;
                } else {
                    content -> emplace(word, 1);
                }

                text -> push_back(word);
            }
        }
    }
}
```

Após o processo acima, tem-se todo o conteúdo do arquivo presente no **unordered_map**, que agora será usado a fim de se obter quantas vezes a palavra que mais aparece, aparece, assim como a que apresenta menos aparições, para isso, foram usadas as funções **_getMaxRP()_** e**_getMinRP()_**, as quais somente diferem no sinal:

```c++
float getMaxRP(unordered_map <string, float> *content) {
    float max = 0;
    string aux;

    for (auto item: *content) {
        if (item.second > max) {
            max = item.second;
            aux = item.first;
        }
    }

    return max;
}
```

```c++
float getMinRP(unordered_map <string, float> *content) {
    float min = 20000;
    string aux;

    for (auto item: *content) {
        if (item.second < min) {
            min = item.second;
            aux = item.first;
        }
    }

    return min;
}
```

Os valores obtidos acima serão importantes para a normalização de valores que se pede no programa. A intenção é não possuir valores excessivamente grandes, estando eles sempre entre 0 e 1. Para tal, foi implementada a função **_normalizeAccounting()_**, que percorrerá todo o **std::unordered_map**, realizando o mesmo tipo de operação para todas as posições. A equação para normalização pode ser vista abaixo:

$$ rankingPalavra = {rankingPalavra\over(maiorRanking - menorRanking)} $$

Na qual:
   - Ranking palavra representa quantas vezes a atual palavra apareceu;
   - maiorRanking é quantas vezes a palavra que mais apareceu, apareceu;
   - menorRanking é quantas vezes a palavra que menos apareceu, apareceu.

A função foi implementada sem maiores dificuldades, e pode ser visualizada em sequência:

```c++
void normalizeAccounting(float maxRP, float minRP, unordered_map <string, float> &content) {
    for (auto item: content) {
        content[item.first] = ((item.second) / (maxRP - minRP));
    }
}
```

Após os valores serem normalizados dentro do **std::unordered_map**, chega ao ponto de transformá-los em "nós soltos" da árvore de Huffman, por meio da função **_mapToVector()_**. Para tal propósito, foi criado um **std::vector** com o tipo de dado **HuffTree***, isto é, o ponteiro da **Struct** vista em uma das primeiras linhas da implementação, que representa os nós de uma árvore. Percebe-se que, nela existem 3 tipos de dados:
   - **_float:_** representa o valor normalizado de cada uma das palavras;
   - **_string:_** armazena, de fato, o conteúdo da palavra;
   - **_vector booleano:_** é usado posteriormente para, realmente implementar a codificação de Huffman, haja visto que a codificação fica salvo no mesmo.

Anteriormente, foram usados dois tipos de dados para estruturar o **std::unordered_map**:
   - **_string:_** era a chave para acessar o conteúdo seguinte;
   - **_float:_** valor normalizado que realmente interessa.

Já que houve essa semelhança, propositalmente, os dados serão transferidos da seguinte forma:
   - A chave se tornará o conteúdo da **_string_** presente na estrutura, enquanto o **_float_** será o conteúdo acessado pela chave correspondente.

A implementação do que foi salientado acima pode ser visto na sequência: 

```c++
void mapToVector(vector <HuffTree*> &treeValues, unordered_map <string, float> &content) {
    HuffTree *aux;

    for (auto search: content) {
        aux = new HuffTree;
        aux -> item.word = search.first;
        aux -> item.normalizedValue = search.second;
        aux -> leftSon = NULL;
        aux -> rightSon = NULL;
        treeValues.push_back(aux);
    }
}
```

Após o que foi realizado acima, é necessário utilizar de um método de ordenação, haja visto que a ideia da **Codificação de Huffman** consiste em sempre juntar os menores valores. A ordenação foi feita visando a ordem decrescente, de forma que os dois menores valores estejam nas duas últimas posições do **std::vector**. Para tal propósito, foi implementado o **_Insertion Sort_**, haja visto que há constantes reinserções no **std::vector** anteriormente mencionado. A função pode ser vista abaixo:

```c++
void insertionSort(vector <HuffTree*> &treeValues) {
    HuffTree *aux;
    int j;

    for (long unsigned int i = 1; i < treeValues.size(); i++) {
        aux = treeValues[i];
        j = i - 1;

        while (j >= 0 && aux -> item.normalizedValue > treeValues[j] -> item.normalizedValue) {
            treeValues[j + 1] = treeValues[j];
            j = j - 1;
        }

        treeValues[j + 1] = aux;
    }
}
```

Toda a parte "preparativa" para a **Codificação de Huffman** já foi realizada, portanto, chega ao momento de realmente implementá-la. Para tal, foi criada a função **_joinNodes()_**, a qual recebe o **std::vector** anteriormente criado e preenchido na função **_mapToVector()_**.

Partindo do conteúdo presente na estrutura supracitada, é criado um looping **while** que itera até que o tamanho do **std::vector** seja **1**, haja visto que, no momento em que chegar em tal condição, todos os nós "soltos" já terão sido agrupados.

Dentro do looping, o primeiro passo é fazer com que duas variáveis auxiliares, **leftSon** e **rightSon**, do tipo **HuffTree**, recebam, respectivamente, o último e o penúltimo valor do **std::vector**, pois, como já foi citado anteriormente, já são os dois menores, além de seguir o que é entendido até mesmo nas árvores binárias: o filho esquerdo sempre recebe o menor valor, ficando o maior para o direito.

Seguido da obtenção dos dois nós, é chamada a função built-in **std::vector::pop_back()**, pois as duas últimas posições não serão mais úteis, e não podem estar na estrutura uma vez que comprometeriam as iterações futuras da função.

Feito isso, há a criação de um novo nó, aquele que será o pai dos dois nós anteriormente obtidos. O valor do mesmo será a soma dos valores normalizados dos dois nós retirados do **std::vector**, enquanto os filhos serão definidos seguindo o seguinte critério:
- O filho esquerdo será o primeiro valor retirado (menor do **std::vector**);
- O filho direito será o segundo valor retirado (segundo menor do **std::vector**).

Além disso, os supracitados filhos receberão o endereço de memória do nó recentemente criado, como sendo seu "pai". Por fim, o novo nó é inserido novamente no **std::vector**, a fim de repetir o mesmo processo até que o tamanho da estrutura de armazenamento se torne **1**.

Ao sair do looping, a raiz da árvore recebe **NULL** como pai, e recebe um **std::vector booleano** vazio, que será utilizado futuramente. A implementação pode ser vista abaixo:

```c++
void joinNodes(vector <HuffTree*> &treeValues) {
    HuffTree *leftSon;
    HuffTree *rightSon;
    HuffTree *aux;
    vector <bool> auxVec;
    
    while (treeValues.size() != 1) {
        leftSon = treeValues[treeValues.size() - 1];
        rightSon = treeValues[treeValues.size() - 2];

        treeValues.pop_back();
        treeValues.pop_back();

        aux = new HuffTree;
        aux -> item.normalizedValue = (leftSon -> item.normalizedValue + rightSon -> item.normalizedValue);
        aux -> leftSon = leftSon;
        aux -> leftSon -> dad = aux;
        aux -> rightSon = rightSon;
        aux -> rightSon -> dad = aux;

        treeValues.push_back(aux);
        insertionSort(treeValues);
    }

    treeValues[0] -> dad = NULL;
    treeValues[0] -> item.binaryCodification = auxVec;
}
```

Chega ao ponto em que se deve gerar o código para cada uma das palavras que se tem armazenada na árvore, seguindo as regras da **Codificação de Huffman**. Para tal, foi criado a função **_generateCode()_**. Na mesma, foi utilizada a lógica da *_impressão por largura_* para percorrer pela árvore, utilizando uma **Fila** como estrutura auxiliar para o processo.

É iniciado um looping na raiz da árvore, e então é checado se o filho esquerdo é diferente de nulo, caso seja, o **std::vector** da estrutura do pai é inserida no do filho, além de utilizar a função **std::vector::push_back()** para acresentar o valor booleano **0**, na última posição. O mesmo processo é realizado para o filho direito, com a contraposição de que, ao contrário de inserir o mesmo valor booleano, é inserido o **1**.

Por fim, após as atualizações, os filhos são inseridos na fila, para que possam ser processados futuramente no looping.

```c++
void generateCode(HuffTree **t) {
    Queue aQueue;
    MEQueue(&aQueue);
    qData aux, son;
    aux.val = *t;
    doQueue(&aQueue, aux);
    bool booleanAux;

    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);

        if (aux.val -> leftSon != NULL) {
            aux.val -> leftSon -> item.binaryCodification = aux.val -> leftSon -> dad-> item.binaryCodification;
            booleanAux = 0;
            aux.val -> leftSon -> item.binaryCodification.push_back(booleanAux);

            son.val = aux.val -> leftSon;
            doQueue(&aQueue, son);
        }

        if (aux.val -> rightSon != NULL) {
            aux.val -> rightSon -> item.binaryCodification = aux.val -> rightSon -> dad -> item.binaryCodification;
            booleanAux = 1;
            aux.val -> rightSon -> item.binaryCodification.push_back(booleanAux);

            son.val = aux.val -> rightSon;
            doQueue(&aQueue, son);
        }
    }
}
```

Após a geração dos códigos, é necessário traduzir o texto tido como input para valores binários, de forma que todos os códigos se tornem um único. Para tal propósito, foi criada a função **_translateToBinary()_**. Nela, é criado um looping que itera até que o **std::vector text**, criado quando ainda era feita a leitura de arquivo, esteja vazio, pois, com isso, significará que todo o texto já foi processado. 

É sempre retirada a primeira palavra do **std::vector**, como forma de seguir a ordem. Na sequência, é procurada na **Árvore de Huffman**, a codificação referente à determinada palavra.

Brevemente, a função **_findWordCode()_** é a responsável por tal tarefa. Ela funciona seguindo a proposta da *_impressão por largura_*. Quando a palavra desejada é encontrada, o conteúdo do **std::vector booleano** é salvo em um endereço de memória, a fim de ser aproveitado em outro lugar. A implementação é a que segue.

```c++
void findWordCode(HuffTree **t, string wordToSearch, vector <bool> &vectorToSave) {
    Queue aQueue;
    MEQueue(&aQueue);
    qData aux, son;
    aux.val = *t;
    doQueue(&aQueue, aux);
    
    while(!isQueueEmpty(&aQueue)) {
        deQueue(&aQueue, &aux);

        if (aux.val -> item.word == wordToSearch) {
            vectorToSave = aux.val -> item.binaryCodification;
        }

        if (aux.val -> leftSon != NULL) {
            son.val = aux.val -> leftSon;
            doQueue(&aQueue, son);
        }

        if (aux.val -> rightSon != NULL) {
            son.val = aux.val -> rightSon;
            doQueue(&aQueue, son);
        }

    }
}
```

Voltando a tradução, ao se ter o conteúdo booleano de uma única palavra, o mesmo é "concatenado" ao conteúdo das palavras anteriores, como uma forma de compor o texto.

Por fim, a primeira posição do **std::vector text** é apagada, haja visto que a mesma já foi processada, assim como o **std::vector** auxiliar é limpo, a fim de estar apto a receber o próximo conteúdo sem comprometer a integridade do programa. Segue a implementação:

```c++
void translateToBinary(vector <bool> &mainVector, vector <string> &text, HuffTree **t) {
    string aux;
    vector <bool> auxVec;

    while (!text.empty()) {
        findWordCode(t, text[0], auxVec);
        for (long unsigned int i = 0; i < auxVec.size(); i++) {
            mainVector.push_back(auxVec[i]);
        }

        text.erase(text.begin());
        auxVec.clear();
    }   
}
```

Por fim, o que resta é inserir o conteúdo do **mainVector** no documento **.bin**. É utilizada a função built-in do **C**, **fwrite**. A transcrição foi realizada em uma outra função para fins organizacionais:

```c++
void writeInFile(vector <bool> &mainVector) {
    FILE *myfile;
    myfile = fopen("text.bin", "wb");
    
    if (myfile != NULL) {
        fwrite(&mainVector, sizeof(bool), mainVector.size(), myfile);
    }
}
```

<h2 align="center">
    📈
    <strong>
        <em> 
            Resultados Esperados
        </em>    
    </strong>
</h2>

Uma boa forma de avaliar a eficiência e funcionalidade do programa se dá pela observação na diminuição do tamanho dos arquivos, eficiência essa que foi de fato possivel de visualizar:

#### Conteúdo .txt:

<p align="center">
  <img height="250rem" src="/imgs/txtprop.png">
</p>

#### Conteúdo .bin:

<p align="center">
  <img height="250rem" src="/imgs/binprop.png">
</p>

<h2 align="center">
    🔧
    <strong>
        <em> 
            Compilação e Execução
        </em>    
    </strong>
</h2>

| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o g++, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação             

É recomendável utilizar o comando **make clean** antes de partir para o **make** e sequencialmente **make run**.
