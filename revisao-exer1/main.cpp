#include <iostream>
#include <vector>
#include <algorithm>
#include "PGM.hpp"  // Certifique-se de que o arquivo de cabeçalho PGM.hpp tem as funções necessárias

using namespace std;

// Função para obter os vizinhos válidos de um pixel na posição (x, y)
void getVizinhos(PGM *pgm, int x, int y, vector<unsigned char> &vizinhos)
{
    // Verifica e adiciona cada vizinho, considerando os limites da imagem
    if (coordValida(pgm, x-1, y-1) && getPixel(pgm, x-1, y-1) != 0) 
        vizinhos.push_back(getPixel(pgm, x - 1, y - 1));     // Superior esquerdo
    if (coordValida(pgm, x-1, y) && getPixel(pgm, x - 1, y) != 0) 
        vizinhos.push_back(getPixel(pgm, x - 1, y));                   // Esquerdo
    if (coordValida(pgm, x-1, y-1) && getPixel(pgm, x-1, y+1) != 0) 
        vizinhos.push_back(getPixel(pgm, x - 1, y + 1));    // Inferior esquerdo
    if (coordValida(pgm, x, y-1) && getPixel(pgm, x, y-1) != 0) 
        vizinhos.push_back(getPixel(pgm, x, y - 1));                   // Superior
    if (coordValida(pgm, x, y+1) && getPixel(pgm, x, y+1) != 0) 
        vizinhos.push_back(getPixel(pgm, x, y + 1));        // Inferior
    if (coordValida(pgm, x+1, y-1) && getPixel(pgm, x+1, y-1) != 0) 
        vizinhos.push_back(getPixel(pgm, x + 1, y - 1)); // Superior direito
    if (coordValida(pgm, x+1, y) && getPixel(pgm, x+1, y) != 0) 
        vizinhos.push_back(getPixel(pgm, x + 1, y));       // Direito
    if (coordValida(pgm, x+1, y+1) && getPixel(pgm, x+1, y+1) != 0) 
        vizinhos.push_back(getPixel(pgm, x + 1, y + 1)); // Inferior direito

}

// Função principal para preencher buracos com a mediana dos vizinhos
void preencheBuracos(PGM *pgm)
{
    for (int i = 0; i < pgm->larg; i++)
    {
        for (int j = 0; j < pgm->alt; j++)
        {
            if (getPixel(pgm, i, j) == 0)
            {
                // Obtém os vizinhos válidos usando o método auxiliar
                vector<unsigned char> vec;
                getVizinhos(pgm, i, j, vec);

                // Ordena o vetor de vizinhos
                sort(vec.begin(), vec.end());

                // Calcula a mediana dos vizinhos
                unsigned char mediana;
                size_t tamanho = vec.size();
                if (tamanho % 2 == 0) {
                    mediana = (vec[tamanho / 2 - 1] + vec[tamanho / 2]) / 2;
                } else {
                    mediana = vec[tamanho / 2];
                }

                // Preenche o buraco com a mediana
                setPixel(pgm, i, j, mediana);
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese");

    string entrada = "entrada.pgm";
    string saida = "saida.pgm";

    cout << "########## PROGRAMA DE TRANSFORMACOES 2D ##########\n";

    PGM imgEntrada;

    // Lê a imagem de entrada
    if (!ler(&imgEntrada, entrada)) {
        cerr << "Erro ao ler a imagem de entrada: " << entrada << endl;
        return EXIT_FAILURE;
    }

    preencheBuracos(&imgEntrada);

    // Grava a imagem de saída
    if (!gravar(&imgEntrada, saida)) {
        cerr << "Erro ao gravar a imagem de saída: " << saida << endl;
        destruir(&imgEntrada);
        return EXIT_FAILURE;
    }

    destruir(&imgEntrada);

    cout << "\nTransformação concluída. Imagem de saída gravada como " << saida << ".\n";
    cout << "Pressione uma tecla para encerrar o programa.\n";
    getchar();
    return EXIT_SUCCESS;
}
