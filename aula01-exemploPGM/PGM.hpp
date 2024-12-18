#ifndef PGM_H_INCLUDED
#define PGM_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct PGM
{
    string tipo;
    int larg;
    int alt;
    int vmax;
    unsigned char *pixels; // unsigned char -> 0 a 255
    PGM()                  // construtor -> inicializar variaveis
    {
        pixels = nullptr;
        larg = 0;
        alt = 0;
        vmax = 255;
        tipo = "";
    }
};

void destruir(PGM *pgm)
{
    if (pgm->pixels)
        delete pgm->pixels;
    pgm->pixels = nullptr;
    pgm->larg = 0;
    pgm->alt = 0;
    pgm->tipo = "";
    pgm->vmax = 255;
}

void imprimir(PGM *pgm)
{
    cout << "\nPGM\n";
    cout << "Tipo: " << pgm->tipo << endl;
    cout << "Dimensao: " << pgm->larg << "x" << pgm->alt << endl;
    cout << "vMax: " << pgm->vmax << endl;
    if (pgm->pixels) // verifica se o vetor de pixels está alocado
        cout << "Vetor de pixels: " << &(pgm->pixels) << endl;
    else
        cout << "Vetor de pixels: NULL\n";
}

void criar(PGM *pgm, int largura, int altura)
{
    if (pgm->pixels)
        delete pgm->pixels;

    int tamanho = largura * altura;

    pgm->tipo = "P2";
    pgm->larg = largura;
    pgm->alt = altura;
    pgm->vmax = 255;
    pgm->pixels = new unsigned char[tamanho];

    // definir a cor preta para todos os pixels
    for (int i = 0; i < tamanho; i++)
        pgm->pixels[i] = 0;
}

bool gravar(PGM *pgm, string caminho)
{
    if (!pgm->pixels)
        return false;

    ofstream arq;

    arq.open(caminho);
    if (!arq.is_open())
    {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }

    arq << pgm->tipo << endl;

    arq << pgm->larg << " " << pgm->alt << endl;

    arq << 255 << endl; // valor máximo de cor fixo em 255

    int tam = pgm->larg * pgm->alt;
    for (int i = 0; i < tam; i++)
    {
        arq << (int)pgm->pixels[i] << endl;
        arq.flush();
    }

    arq.close();
    return true;
}

string lerLinhaArquivo(std::ifstream &arq)
{
    string linha = "", dadoLido = "";
    while (!arq.eof())
    {
        linha = "";
        std::getline(arq, linha);
        if (linha.size() > 0 && linha[0] != '#')
            return linha;
    }
    return linha;
}

bool ler(PGM *pgm, string caminho)
{
    ifstream arq;
    string dado;
    stringstream str;

    arq.open(caminho);
    if (!arq.is_open())
    {
        cout << "PGM: endereco do arquivo invalido\n";
        return false;
    }

    // ler o tipo
    dado = lerLinhaArquivo(arq);
    if (dado == "P2")
        pgm->tipo = dado;
    else
    {
        cout << "PGM: erro ao ler o tipo da imagem\n";
        return false;
    }

    // ler largura e altura
    dado = lerLinhaArquivo(arq);
    str = stringstream(dado);
    if (!(str >> pgm->larg))
    {
        cout << "PGM: erro ao ler a largura\n";
        return false;
    }
    if (!(str >> pgm->alt))
    {
        cout << "PGM: erro ao ler a largura\n";
        return false;
    }

    // ler vmax
    dado = lerLinhaArquivo(arq);
    str = stringstream(dado);
    if (!(str >> pgm->vmax))
    {
        cout << "PGM: erro ao ler vmax\n";
        return false;
    }

    if (pgm->pixels)
        delete pgm->pixels;

    int tam = pgm->larg * pgm->alt;

    pgm->pixels = new unsigned char[tam];

    int i = 0, p;
    while (!arq.eof())
    {

        if (arq >> p)
        {
            if (i < tam)
                pgm->pixels[i] = (unsigned char)p;
            i++;
        }
        else
            break;
    }

    if (i != tam)
    {
        cout << "PGM: erro ao ler os pixels\n";
        return false;
    }
    arq.close();
    return true;
}

unsigned char getPixel(PGM *pgm, int x, int y)
{
    if (!pgm->pixels)
        return 0;

    return pgm->pixels[y * pgm->larg + x];
}
void setPixel(PGM *pgm, int x, int y, unsigned char cor)
{
    if (!pgm->pixels)
        return;

    pgm->pixels[y * pgm->larg + x] = cor;
}

// ex4: criar c/ cor
void criar_com_cor(PGM *pgm, int largura, int altura, unsigned char corFundo)
{
    if (pgm->pixels)
        delete pgm->pixels;

    int tamanho = largura * altura;

    pgm->tipo = "P2";
    pgm->larg = largura;
    pgm->alt = altura;
    pgm->vmax = 255;
    pgm->pixels = new unsigned char[tamanho];

    // definir a cor preta para todos os pixels
    for (int i = 0; i < tamanho; i++)
        pgm->pixels[i] = corFundo;
}

// ex5: setlinha
void setLinha(PGM *pgm, int linha, unsigned char cor)
{
    if (!pgm->pixels)
        return;

    for (int i = 0; i < pgm->larg; i++)
    {
        pgm->pixels[linha * pgm->larg + i] = cor;
    }
}

// ex6: coordValida
bool coordValida(PGM *pgm, int x, int y)
{
    bool valida = true;

    if (pgm->larg <= x || pgm->alt <= y)
        valida = false;

    return valida;
}

// ex7: preencher regiao
void preencheRegiao(PGM *pgm, int x1, int y1, int x2, int y2, unsigned char cor)
{
    // Garantir que x1 <= x2 e y1 <= y2
    if (x1 > x2)
    {
        int aux = x1;
        x1 = x2;
        x2 = aux;
    }

    if (y1 > y2)
    {
        int aux = y1;
        y1 = y2;
        y2 = aux;
    }

    // Verificar se as coordenadas são válidas
    if (!coordValida(pgm, x1, y1) || !coordValida(pgm, x2, y2))
    {
        cout << "Coordenadas invalidas!" << endl;
        return;
    }

    // Preencher a região
    for (int y = y1; y <= y2; y++)
    {
        for (int x = x1; x <= x2; x++)
        {
            setPixel(pgm, x, y, cor);
        }
    }
}

// ex9: inverter verticalmente
void flipVertical(PGM *pgm)
{
    int j = pgm->alt;
    for (int i = 0; i < pgm->alt / 2; i++)
    {
        j--;
        for (int x = 0; x < pgm->larg; x++)
        {
            unsigned char temp = pgm->pixels[i * pgm->larg + x];
            pgm->pixels[i * pgm->larg + x] = pgm->pixels[j * pgm->larg + x];
            pgm->pixels[j * pgm->larg + x] = temp;
        }
    }
}

// ex10: copiar região
void copiarRegiao(PGM *pgm1, PGM *pgm2, int p1[], int p2[])
{
    int x1 = p1[0], x2 = p2[0], y1 = p1[1], y2 = p2[1];

    if (x1 > x2)
    {
        int aux = x1;
        x1 = x2;
        x2 = aux;
    }

    if (y1 > y2)
    {
        int aux = y1;
        y1 = y2;
        y2 = aux;
    }

    // Verificar se as coordenadas são válidas
    if (!coordValida(pgm1, x1, y1) || !coordValida(pgm1, x2, y2))
    {
        cout << "Coordenadas invalidas!" << endl;
        return;
    }

    // Preencher a região
    for (int y = y1; y <= y2; y++)
    {
        for (int x = x1; x <= x2; x++)
        {
            setPixel(pgm2, x, y, getPixel(pgm1, x, y));
        }
    }
}

// ex11: desenhar borda
void desenhaBorda(PGM *pgm, int espessura, unsigned char cor)
{
    if (espessura <= 0 || espessura > 10 || espessura >= pgm->larg || espessura >= pgm->alt)
    {
        cout << "\nnERRO: Não é possível criar uma borda desse tamanho!\n";
        return;
    }

    // Desenha borda superior e inferior
    for (int j = 0; j < espessura; j++)
    {
        for (int i = 0; i < pgm->larg; i++)
        {
            // Superior
            setPixel(pgm, i, j, cor);
            // Inferior
            setPixel(pgm, i, pgm->alt - 1 - j, cor);
        }
    }

    // Desenha borda esquerda e direita
    for (int i = 0; i < espessura; i++)
    {
        for (int j = 0; j < pgm->alt; j++)
        {
            // Esquerda
            setPixel(pgm, i, j, cor);
            // Direita
            setPixel(pgm, pgm->larg - 1 - i, j, cor);
        }
    }
}

// ex12: desenhar X
void desenharX(PGM *pgm, unsigned char cor)
{
    for (int i = 0; i < pgm->larg; i++)
    {
        for (int j = 0; j < pgm->alt; j++)
        {
            // Cálculo das diagonais principal e secundária
            if (i == j || i + j == pgm->larg - 1)
            {
                setPixel(pgm, i, j, cor);
            }
        }
    }
}

// ex13: combinar imagens
void combinarImagens(PGM *pgm1, PGM *pgm2, PGM *pgmComb, int combinacao)
{
    // Itera sobre cada pixel da imagem
    for (int i = 0; i < pgm1->larg; i++)
    {
        for (int j = 0; j < pgm1->alt; j++)
        {
            // Pega o valor do pixel nas imagens pgm1 e pgm2
            int pixel1 = getPixel(pgm1, i, j);
            int pixel2 = getPixel(pgm2, i, j);
            int valorComb;

            // Combina os pixels de acordo com a opção de combinação
            if (combinacao == 1)
            {
                valorComb = (pixel1 + pixel2) / 2;
            }
            else if (combinacao == 2)
            {
                valorComb = max(pixel1, pixel2);
            }
            else
            {
                valorComb = min(pixel1, pixel2);
            }
            setPixel(pgmComb, i, j, valorComb);
        }
    }
}

// ex14: criar borda em determinada região
void criarBorda(PGM *pgm, int x1, int x2, int y1, int y2, unsigned char cor)
{
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (i == x1 || i == x2 || j == y1 || j == y2)
            {
                setPixel(pgm, i, j, cor);
            }
            
        }
    }
}

void converteCinza(PGM *pgm)
{
    for (int i = 0; i < pgm->larg; i++)
    {
        for (int j = 0; j < pgm->alt; j++)
        {
            if (getPixel(pgm, i, j) > 128)
                setPixel(pgm, i, j, 255);
            else
            setPixel(pgm, i, j, 0);
        }
    }
}

#endif