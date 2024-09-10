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
	cout << "#Exercicio 4 - Criar com cor#\n";
	criar_com_cor(&img4, 10, 10, cor);	// funcao exer4
	gravar(&img4, "exer4.pgm"); //gravar o resultado no disco
	destruir(&img4);

	cout << "\nImagem criada com sucesso - exer4.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");
//##################################################################

	// Exercício 5
	PGM img5;
	cor = 0;
    criar_com_cor(&img5, 20, 20, cor);
    cor = 255;
	cout << "#Exercicio 5 - Setar linha#\n";
    setLinha(&img5, 5, cor);	// funcao exer5
    gravar(&img5, "exer5.pgm");
    destruir(&img5);

	cout << "\nImagem alterada (set linha) com sucesso - exer5.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");
//#######################################################

	// Exercício 6
	PGM img6;
	int x = 5;
	int y = 3;
	
	criar(&img6, x, y);

	cout << "#Exercicio 6 - Validar coordenadas#\n";
	
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

	cout << "\nValidacao de coordenadas concluida\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

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

	cout << "#Exercicio 7 - Preencher regiao#\n";
	preencheRegiao(&img7, x1, y1, x2, y2, cor); 	// funcao exer7
	gravar(&img7, "exer7.pgm");

	destruir(&img7);

	cout << "\nImagem alterada com sucesso (preencher regiao) - exer7.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

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

	cout << "#Exercicio 8 - Setar linhas brancas#\n";
	gravar(&img8, "exer8.pgm");
	destruir(&img8);

	cout << "\nImagem alterada com sucesso (setar linhas brancas) - exer8.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

//###############################################################

	// Exercicio 9
	PGM img9;
	ler(&img9, "img-base.pgm");

	flipVertical(&img9);

	cout << "#Exercicio 9 - Inverter verticalmente#\n";
	gravar(&img9, "exer9.pgm");
	destruir(&img9);

	cout << "\nImagem invertida com sucesso - exer9.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

//#################################################################

	// Exercício 10
	cout << "#Exercicio 10 - Copiar regiao#\n";
	
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

	gravar(&img10, "exer10.pgm");

	destruir(&imgBase);
	destruir(&img10);

	cout << "\nImagem alterada com sucesso (copia regiao) - exer10.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

//#####################################################################

	// Exercício 11
	cout << "#Exercicio 11 - Desenhar borda#\n";

	PGM img11;

	criar_com_cor(&img11, 100, 100, 0);
	desenhaBorda(&img11, 5, 255);
	gravar(&img11, "exer11.pgm");

	destruir(&img11);

	cout << "\nImagem alterada com sucesso (desenhar borda) - exer11.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

//#####################################################################

	// Exercício 12
	cout << "#Exercicio 12 - Desenhar X#\n";

	PGM img12;
	criar_com_cor(&img12, 100, 100, 0);	// criação de imagem preta

	desenharX(&img12, 255);
	gravar(&img12, "exer12.pgm");

	destruir(&img12);

	cout << "\nImagem alterada com sucesso (desenhar X) - exer12.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");
//######################################################################

	// Exercício 13
	cout << "Exercicio 13 - Combinar imagens#\n";
	
	PGM img13a;
	PGM img13b;
	PGM img13;

	int opcao;
	do {
		cout << "########## MENU ##########\n";
		cout << "#        0. Sair         #\n";
		cout << "#        1. Media        #\n";
		cout << "#        2. Maior        #\n";
		cout << "#        3. Menor        #\n";
		cout << "##########################\n";
		cout << "\nSua opcao: ";
		cin >> opcao;
		fflush(stdin);

		if (opcao < 0 || opcao > 3)
		{
			cout << "Opcao invalida!\n";
		}
		else if (opcao == 0)
		{
			break;
		}
		else
		{
			ler(&img13a, "img-base.pgm");
			ler(&img13b, "img-base2.pgm");
			criar(&img13, img13a.larg, img13a.alt);
			combinarImagens(&img13a, &img13b, &img13, opcao);
			gravar(&img13, "exer13.pgm");

			cout << "\nImagem criada com sucesso!\n";
		}
		destruir(&img13);
		destruir(&img13a);
		destruir(&img13b);

		cout << "Para visualizar, basta procurar pela imagem 'exer13.pgm'...\nPara continuar a execucao, pressione qualquer tecla...\n";
		getchar();
		system("cls");

	}while(opcao > 0 && opcao <= 3);

	cout << "\nExercicio 13 concluido - exer13.pgm\n";
	
	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

//######################################################################

// Exercício 14
	cout << "#Exercicio 14 - Desenhar borda#\n";

	PGM img14;
	ler(&img14, "img-base2.pgm");
	criarBorda(&img14, 100, 300, 100, 300, 255);
	gravar(&img14, "exer14.pgm");

	cout << "\nImagem gerada com sucesso - exer14.pgm!\n";

	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");



	destruir(&img14);

// ######################################################################

	// Exercício 15
	cout << "#Exercicio 15 - Converter tons de cinza#\n";

	PGM img15;
	ler(&img15, "img-base.pgm");
	converteCinza(&img15);
	gravar(&img15, "exer15.pgm");

	cout << "\nImagem gerada - tons de cinza convertidos - exer15.pgm\n";

	destruir(&img15);

	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");
	
	cout << "Pressione uma tecla para encerrar o programa.\n";
	getchar();
	return EXIT_SUCCESS; 
}