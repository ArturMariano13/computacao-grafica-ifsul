#include <iostream>
#include "PGM.hpp"

using namespace std;



int main(void)
{

	/*//#Exemplo1#: criando uma imagem e gravando no disco
	PGM img1;
	criar(&img1, 5, 7);
	gravar(&img1, "exemplo1.pgm");
	destruir(&img1);

	//#Exemplo2#: imprimindo os atributos da imagem 
	PGM img2;
	cout << "#Exemplo 2#\n";
	imprimir(&img2);
	criar(&img2, 700, 500);
	imprimir(&img2);
	gravar(&img2, "exemplo2.pgm");
	destruir(&img2);
	imprimir(&img2);

	//#Exemplo3#: ler imagem, getPixel, setPixel 
	PGM img3;
	unsigned char corP;
	cout << "\n\n#Exemplo 3#\n";
	ler(&img3, "feep.pgm");

	//ler o valor do pixel de coordenadas (x=1, y=1)
	corP = getPixel(&img3, 1,1);
	cout << "A cor do pixel(1,1): " << (int) corP << endl;

	setPixel(&img3, 1, 1, 255); //alterar a cor do pixel(1,1) para branco(255)
	gravar(&img3, "exemplo3.pgm"); //gravar o resultado no disco
	destruir(&img3);
	*/
//##################################################################

	//Exercício 4
	PGM img4;
	unsigned char cor;
	cor = 128;	// cinza
	cout << "\n\n#Exercicio 4 - Criar com cor#\n";
	exer4(&img4, 10, 10, cor);
	gravar(&img4, "exer4.pgm"); //gravar o resultado no disco
	destruir(&img4);
//##################################################################

	// Exercício 5
	PGM img5;
	cor = 0;
    exer4(&img5, 20, 20, cor);
    cor = 255;
	cout << "\n\n#Exercicio 5 - Setar linha#\n";
    exer5(&img5, 5, cor);
    gravar(&img5, "exer5.pgm");
    destruir(&img5);
//#######################################################

	// Exercício 6
	PGM img6;
	int x = 5;
	int y = 3;
	
	criar(&img6, x, y);


	cout << "\n\n#Exercicio 6 - Validar coordenadas#\n";
	
	cout << "\nInsira o x: ";
	cin >> x;
	fflush(stdin);

	cout << "\nInsira o y: ";
	cin >> y;
	fflush(stdin);

	if (exer6(&img6, x, y))
		cout << "\nCoordenada valida!" << endl;
	else
		cout << "\nCoordenada invalida!" << endl;

	destruir(&img6);

	
	cout << "Pressione uma tecla para encerrar o programa.\n";
	getchar();
	return EXIT_SUCCESS; 
}