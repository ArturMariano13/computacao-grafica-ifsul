#ifndef PPM_H_INCLUDED
#define PPM_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct PPM
{
    string tipo;
    int larg;
    int alt;
    int vmax;
    unsigned char *pixels; // unsigned char -> 0 a 255
    PPM()                  // construtor -> inicializar variaveis
    {
        pixels = nullptr;
        larg = 0;
        alt = 0;
        vmax = 255;
        tipo = "";
    }
};

struct RGB
{
    unsigned char r, g, b;
    RGB()
    {
        r = 0;
        g = 0;
        b = 0;
    }
    RGB(unsigned char _r, unsigned char _g, unsigned char _b)
    {
        r = _r;
        g = _g;
        b = _b;
    }
};
ostream &operator<<(ostream &os, const RGB rgb)
{
    return os << (int)rgb.r << ", " << (int)rgb.g << ", " << (int)rgb.b;
}

void destruir(PPM *ppm)
{
    if (ppm->pixels)
        delete ppm->pixels;
    ppm->pixels = nullptr;
    ppm->larg = 0;
    ppm->alt = 0;
    ppm->tipo = "";
    ppm->vmax = 255;
}

void imprimir(PPM *ppm)
{
    cout << "\nPPM\n";
    cout << "Tipo: " << ppm->tipo << endl;
    cout << "Dimensao: " << ppm->larg << "x" << ppm->alt << endl;
    cout << "vMax: " << ppm->vmax << endl;
    if (ppm->pixels) // verifica se o vetor de pixels está alocado
        cout << "Vetor de pixels: " << &(ppm->pixels) << endl;
    else
        cout << "Vetor de pixels: NULL\n";
}

void criar(PPM *ppm, int largura, int altura)
{
    if (ppm->pixels)
        delete ppm->pixels;

    int tamanho = largura * altura * 3; // vezes 3, pois cada pixel possui RGB

    ppm->tipo = "P3";
    ppm->larg = largura;
    ppm->alt = altura;
    ppm->vmax = 255;
    ppm->pixels = new unsigned char[tamanho];

    // definir a cor preta para todos os pixels
    for (int i = 0; i < tamanho; i++)
        ppm->pixels[i] = 0;
}

bool gravar(PPM *ppm, string caminho)
{
    if (!ppm->pixels)
        return false;

    ofstream arq;

    arq.open(caminho);
    if (!arq.is_open())
    {
        cout << "PPM: endereco do arquivo invalido\n";
        return false;
    }

    arq << ppm->tipo << endl;

    arq << ppm->larg << " " << ppm->alt << endl;

    arq << 255 << endl; // valor máximo de cor fixo em 255

    int tam = ppm->larg * ppm->alt * 3; // vezes 3, pois cada pixel possui RGB
    for (int i = 0; i < tam; i++)
    {
        arq << (int)ppm->pixels[i] << endl;
        arq.flush();
    }

    arq.close();
    return true;
}

string lerLinhaArquivoPPM(std::ifstream &arq)
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

bool ler(PPM *ppm, string caminho)
{
    ifstream arq;
    string dado;
    stringstream str;

    arq.open(caminho);
    if (!arq.is_open())
    {
        cout << "PPM: endereco do arquivo invalido\n";
        return false;
    }

    // ler o tipo
    dado = lerLinhaArquivoPPM(arq);
    if (dado == "P3")
        ppm->tipo = dado;
    else
    {
        cout << "PPM: erro ao ler o tipo da imagem\n";
        return false;
    }

    // ler largura e altura
    dado = lerLinhaArquivoPPM(arq);
    str = stringstream(dado);
    if (!(str >> ppm->larg))
    {
        cout << "PPM: erro ao ler a largura\n";
        return false;
    }
    if (!(str >> ppm->alt))
    {
        cout << "PPM: erro ao ler a largura\n";
        return false;
    }

    // ler vmax
    dado = lerLinhaArquivoPPM(arq);
    str = stringstream(dado);
    if (!(str >> ppm->vmax))
    {
        cout << "PPM: erro ao ler vmax\n";
        return false;
    }

    if (ppm->pixels)
        delete ppm->pixels;

    int tam = ppm->larg * ppm->alt * 3; // vezes 3, pois cada pixel possui RGB

    ppm->pixels = new unsigned char[tam];

    int i = 0, p;
    while (!arq.eof())
    {

        if (arq >> p)
        {
            if (i < tam)
                ppm->pixels[i] = (unsigned char)p;
            i++;
        }
        else
            break;
    }

    if (i != tam)
    {
        cout << "PPM: erro ao ler os pixels\n";
        return false;
    }
    arq.close();
    return true;
}

RGB getPixel(PPM *ppm, int x, int y)
{
    RGB rgb;
    if (!ppm->pixels)
        return rgb;

    rgb.r = ppm->pixels[y * ppm->larg * 3 + x * 3];
    rgb.g = ppm->pixels[y * ppm->larg * 3 + x * 3 + 1];
    rgb.b = ppm->pixels[y * ppm->larg * 3 + x * 3 + 2];

    return rgb;
}
void setPixel(PPM *ppm, int x, int y, RGB rgb)
{
    if (!ppm->pixels)
        return;

    ppm->pixels[y * ppm->larg * 3 + x * 3] = rgb.r;
    ppm->pixels[y * ppm->larg * 3 + x * 3 + 1] = rgb.g;
    ppm->pixels[y * ppm->larg * 3 + x * 3 + 2] = rgb.b;
}

// Exercicio 3: criar com cor
void criar_com_cor(PPM *ppm, int largura, int altura, RGB corFundo)
{
    if (ppm->pixels)
        delete ppm->pixels;

    int tamanho = largura * altura * 3; // vezes 3, pois cada pixel possui RGB

    ppm->tipo = "P3";
    ppm->larg = largura;
    ppm->alt = altura;
    ppm->vmax = 255;
    ppm->pixels = new unsigned char[tamanho];

    // definir a cor preta para todos os pixels
    for (int i = 0; i < largura; i++)
    {
        for (int j = 0; j < altura; j++)
        {
            setPixel(ppm, i, j, corFundo);
        }
    }
}

// Exercicio 4: setar linha
void setLinha(PPM *ppm, int linha, RGB cor)
{
    for (int i = 0; i < ppm->larg; i++)
    {
        setPixel(ppm, i, linha, cor);
    }
}

// Exercicio 5: validar coordenadas
bool coordValida(PPM *ppm, int x, int y)
{
    bool valida = true;

    if (x < 0 || ppm->larg <= x || y < 0 || ppm->alt <= y)
        valida = false;

    return valida;
}

// Exercicio 6: marcar area
void marcarArea(PPM *ppm, int x1, int y1, int x2, int y2, RGB cor)
{
    if (!coordValida(ppm, x1, y1) || !coordValida(ppm, x2, y2))
    {
        cout << "\nCoordenadas invalidas!\n";
        return;
    }

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

    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            if (i == x1 || i == x2 || j == y1 || j == y2)
            {
                setPixel(ppm, i, j, cor);
            }
        }
    }
}

// Exercicio 7: inserir linhas de cores aleatorias
void linhasAleatorias(PPM *ppm)
{

    srand(time(NULL));

    for (int i = 0; i < ppm->alt; i += 50)
    {
        unsigned char r = rand() % 256;
        unsigned char g = rand() % 256;
        unsigned char b = rand() % 256;
        RGB cor(r, g, b);

        for (int j = 0; j < ppm->larg; j++)
        {
            setPixel(ppm, j, i, cor);
        }
    }
}

// Exercicio 8: copiar regiao
void copiarRegiao(PPM *origem, PPM *destino, int x1, int y1, int x2, int y2)
{
    if (!coordValida(origem, x1, y1) || !coordValida(origem, x2, y2))
    {
        cout << "\nCoordenadas invalidas!\n";
        return;
    }

    // criando imagem preta com mesmas dimensoes
    criar_com_cor(destino, origem->larg, origem->alt, RGB(0, 0, 0));

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

    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            RGB corPixel = getPixel(origem, i, j);
            setPixel(destino, i, j, corPixel);
        }
    }
}

// Exercicio 9: converter PPM para PGM
void converterPGM(PPM *orig, PPM *dest)
{
    criar(dest, orig->larg, orig->alt);

    for (int i = 0; i < orig->larg; i++)
    {
        for (int j = 0; j < orig->alt; j++)
        {
            RGB cor = getPixel(orig, i, j);
            
            // Calcular a luminância
            unsigned char gray = (unsigned char)(cor.r * 0.299 + cor.g * 0.587 + cor.b * 0.114);
            
            // Definir o pixel de destino para o valor de cinza calculado
            setPixel(dest, i, j, RGB(gray, gray, gray));
        }
    }
}

// Exercicio 10: inverter horizontalmente
void flipHorizontal(PPM *ppm)
{
    int largura = ppm->larg;
    int altura = ppm->alt;

    for (int y = 0; y < altura; y++)
    {
        for (int x = 0; x < largura / 2; x++)
        {
            RGB corEsquerda = getPixel(ppm, x, y);
            RGB corDireita = getPixel(ppm, largura - x - 1, y);

            setPixel(ppm, x, y, corDireita);
            setPixel(ppm, largura - x - 1, y, corEsquerda);
        }
    }
}

void marcarAreaComBorda(PPM *ppm, int x1, int y1, int x2, int y2, int espessura, RGB cor)
{
    // Verificação de coordenadas válidas
    if (!coordValida(ppm, x1, y1) || !coordValida(ppm, x2, y2))
    {
        cout << "\nCoordenadas invalidas!\n";
        return;
    }

    // Ordenação das coordenadas
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

    // Limitação da espessura a no máximo 20 pixels
    if (espessura > 20) espessura = 20;

    // Desenho da borda
    for (int i = x1; i <= x2; i++)
    {
        for (int j = y1; j <= y2; j++)
        {
            // Verifica se o pixel está na borda com a espessura dada
            if (i < x1 + espessura || i >= x2 - espessura || 
                j < y1 + espessura || j >= y2 - espessura)
            {
                setPixel(ppm, i, j, cor);
            }
        }
    }
}






#endif