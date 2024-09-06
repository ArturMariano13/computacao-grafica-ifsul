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
/*
	//Exercício 4
	PGM img4;
	unsigned char cor;
	cor = 128;	// cinza
	cout << "\n\n#Exercicio 4 - Criar com cor#\n";
	criar_com_cor(&img4, 10, 10, cor);	// funcao exer4
	gravar(&img4, "exer4.pgm"); //gravar o resultado no disco
	destruir(&img4);
//##################################################################

	// Exercício 5
	PGM img5;
	cor = 0;
    criar_com_cor(&img5, 20, 20, cor);
    cor = 255;
	cout << "\n\n#Exercicio 5 - Setar linha#\n";
    setLinha(&img5, 5, cor);	// funcao exer5
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

	if (coordValida(&img6, x, y)) 	// validar cooredenada
		cout << "\nCoordenada valida!" << endl;
	else
		cout << "\nCoordenada invalida!" << endl;

	destruir(&img6);
//##########################################################

	// Exercicio 7
	PGM img7;
	int x1 = 20;
	int y1 = 20;

	criar(&img7, x1, y1);

	x1 = 5;
	y1 = 4;

	int x2 = 8;
	int y2 = 10;

	cout << "\n\n#Exercicio 7 - Preencher regiao#\n";
	preencheRegiao(&img7, x1, y1, x2, y2, cor); 	// funcao exer7
	gravar(&img7, "exer7.pgm");

	destruir(&img7);

//###########################################################

	// Exercicio 8
	PGM img8;
	criar_com_cor(&img8, 500, 500, 0); 		// funcao exer4
	unsigned char corBranca = 255;

	int i = 0;

	while (i < 500)
	{
		if ((i + 1) % 50 == 0)
			setLinha(&img8, i, corBranca);
		
		i++;
	}

	cout << "\n\n#Exercicio 8 - Setar linhas brancas#\n";
	gravar(&img8, "exer8.pgm");
	destruir(&img8);

//###############################################################

	// Exercicio 9
	PGM img9;
	ler(&img9, "img-base.pgm");

	flipVertical(&img9);

	cout << "\n\n#Exercicio 9 - Inverter verticalmente#\n";
	gravar(&img9, "exer9.pgm");
	destruir(&img9);

//#################################################################

	// Exercício 10
	cout << "\n\n#Exercicio 10 - Copiar regiao#\n";
	
	PGM imgBase;
	PGM img10;
	ler(&imgBase, "img-base.pgm");
	unsigned char corPreta = 0;

	// criação da imagem com cor preta
	criar_com_cor(&img10, imgBase.larg, imgBase.alt, corPreta);

	// Inserir aqui as coordenadas da região
	int p1[2] = {50, 50};
	int p2[2] = {100, 250};

	copiarRegiao(&imgBase, &img10, p1, p2);

	// gravação da imagem em disco
	gravar(&img10, "exer10.pgm");

	// desaloca memória
	destruir(&imgBase);
	destruir(&img10);
	
//#####################################################################

	// Exercício 11
	cout << "\n\n#Exercicio 11 - Desenhar borda#\n";

	PGM img11;

	criar_com_cor(&img11, 100, 100, 0);
	desenhaBorda(&img11, 5, 255);
	gravar(&img11, "exer11.pgm");

//#####################################################################

	// Exercício 12
	cout << "\n\n#Exercicio 12 - Desenhar X#\n";

	PGM img12;
	criar_com_cor(&img12, 100, 100, 0);	// criação de imagem preta

	desenharX(&img12, 255);
	gravar(&img12, "exer12.pgm");

	destruir(&img12);
*/
//######################################################################

	// Exercício 13
	

	
	cout << "Pressione uma tecla para encerrar o programa.\n";
	getchar();
	return EXIT_SUCCESS; 
}