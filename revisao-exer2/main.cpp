#include <iostream>
#include <vector>
#include "PGM.hpp"

using namespace std;


void floodfill(PGM *img, int x, int y, 
                      unsigned char prevClr, unsigned char newClr) {
    
    if (getPixel(img, x, y) != prevClr)
       return;
  
    setPixel(img, x , y , newClr);
    
    if(coordValida(img, x-1, y)) 
        floodfill(img, x-1, y, prevClr, newClr);
    if(coordValida(img, x+1, y) )
        floodfill(img, x+1, y, prevClr, newClr);
    if(coordValida(img, x, y-1) )
        floodfill(img, x, y-1, prevClr, newClr);
    if(coordValida(img, x, y+1) )
        floodfill(img, x, y+1, prevClr, newClr);
}


int main() {
    setlocale(LC_ALL, "Portuguese");
    string entrada = "dino.pgm";
    string saida = "saida_filled.pgm";

    cout << "########## PROGRAMA DE PREENCHIMENTO POR INUNDACAO ##########\n";

    PGM imgEntrada;

    ler(&imgEntrada, entrada);
  
    unsigned char corFundo = getPixel(&imgEntrada, 125, 125);
    unsigned char novaCor = 100;

    // Realiza o preenchimento por inundação
    floodfill(&imgEntrada, 125, 125, corFundo, novaCor);

    // Grava a imagem de saída
    gravar(&imgEntrada, saida);

    destruir(&imgEntrada);

    cout << "\nPreenchimento concluído. Imagem de saída gravada como " << saida << ".\n";
    cout << "Pressione uma tecla para encerrar o programa.\n";
    getchar();
    return EXIT_SUCCESS;
}