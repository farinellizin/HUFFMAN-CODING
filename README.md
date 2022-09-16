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
        <dt> <br><br><br> CONTINUAR DEPOIS</dt>
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

Partindo do conteúdo presente na estrutura supracitada, é criado um looping **while** que itera até que o tamanho do **std::vector** seja **1**, haja visto que, no momento em que chegar em tal condição, todos os nós "soltos" já terão sido juntados.

Dentro do looping, o primeiro passo é fazer com que duas variáveis auxiliares, **leftSon** e **rightSon**, do tipo **HuffTree**, recebam, respectivamente, o último e o penúltimo valor do **std::vector**, pois, como já foi citado anteriormente, já são os dois menores, além de seguir o que é entendido até mesmo nas árvores binárias: o filho esquerdo sempre recebe o menor valor, ficando o maior para o direito.

Seguido da obtenção dos dois nós, é chamada a função built-in **std::vector::pop_back()**, pois as duas últimas posições não serão mais úteis, e não podem estar na estrutura uma vez que comprometeriam as iterações futuras da função.