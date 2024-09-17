#include <iostream>
#include "PPM.hpp"

using namespace std;

int main(void)
{
	int r = 255, g = 0, b = 255;
	int x1, y1, x2, y2;

	/*
	//#Exemplo1#: criando uma imagem e gravando no disco
	PPM img1;
	criar(&img1, 5, 7);
	gravar(&img1, "exemplo1.ppm");
	destruir(&img1);

	//#Exemplo2#: imprimindo os atributos da imagem
	PPM img2;
	cout << "#Exemplo 2#\n";
	imprimir(&img2);
	criar(&img2, 700, 500);
	imprimir(&img2);
	gravar(&img2, "exemplo2.ppm");
	destruir(&img2);
	imprimir(&img2);

	//#Exemplo3#: ler imagem, getPixel, setPixel
	PPM img-exemplo3;
	RGB corP;
	cout << "\n\n#Exemplo 3#\n";
	ler(&img-exemplo3, "exemploPPM.ppm");

	//ler o valor do pixel de coordenadas (x=1, y=1)
	corP = getPixel(&img-exemplo3, 0,0);
	cout << "A cor do pixel(0,0): [" << corP << "] " << endl;

	setPixel(&img-exemplo3, 1, 0, RGB(0, 128, 128)); //alterar a cor do pixel(1, 0) para RGB(0, 128, 128)
	setPixel(&img-exemplo3, 2, 0, RGB(255, 0, 255)); //alterar a cor do pixel(2, 0) para rosa
	setPixel(&img-exemplo3, 2, 4, RGB(128, 0, 128)); //alterar a cor do pixel(2, 4) para roxo
	gravar(&img-exemplo3, "exemplo3.ppm"); //gravar o resultado no disco
	destruir(&img-exemplo3);
	*/

		// Exercicio 3: criar com cor
		PPM img3;
		do
		{
			cout << "#     Exercicio 3 - criar com cor     #\n";

			// Validação para o valor de R
			do
			{
				cout << "\nInsira o valor para R (0-255): ";
				cin >> r;
				fflush(stdin);
				if (r < 0 || r > 255)
				{
					cout << "Valor inválido! O valor de R deve estar entre 0 e 255.\n";
				}
			} while (r < 0 || r > 255);

			// Validação para o valor de G
			do
			{
				cout << "\nInsira o valor para G (0-255): ";
				cin >> g;
				fflush(stdin);
				if (g < 0 || g > 255)
				{
					cout << "Valor inválido! O valor de G deve estar entre 0 e 255.\n";
				}
			} while (g < 0 || g > 255);

			// Validação para o valor de B
			do
			{
				cout << "\nInsira o valor para B (0-255): ";
				cin >> b;
				fflush(stdin);
				if (b < 0 || b > 255)
				{
					cout << "Valor inválido! O valor de B deve estar entre 0 e 255.\n";
				}
			} while (b < 0 || b > 255);

		} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255);


		criar_com_cor(&img3, 500, 500, RGB((unsigned char)r, (unsigned char)g, (unsigned char)b));
		gravar(&img3, "exer3.ppm");

		destruir(&img3);

		cout << "\nImagem criada com sucesso! Ver 'exer3.ppm'.\n";
		cout << "Pressione qualquer tecla para continuar...";
		getchar();
		system("cls");

	// ###########################################################################

	// Exercicio 4: setar linha
	PPM img4;
	int linha;

	criar_com_cor(&img4, 500, 500, RGB((unsigned char)r, (unsigned char)g, (unsigned char)b));

	do
	{
		cout << "#     Exercicio 4 - setar linha     #\n";

		do
		{
			cout << "\nInsira a linha: ";
			cin >> linha;
			fflush(stdin);
			if (linha < 0 || linha > img4.alt - 1)
			{
				cout << "Valor inválido!\n";
			}
		} while (linha < 0 || linha > img4.alt - 1);

		// Validação para o valor de R
		do
		{
			cout << "\nInsira o valor para R (0-255): ";
			cin >> r;
			fflush(stdin);
			if (r < 0 || r > 255)
			{
				cout << "Valor inválido! O valor de R deve estar entre 0 e 255.\n";
			}
		} while (r < 0 || r > 255);

		// Validação para o valor de G
		do
		{
			cout << "\nInsira o valor para G (0-255): ";
			cin >> g;
			fflush(stdin);
			if (g < 0 || g > 255)
			{
				cout << "Valor inválido! O valor de G deve estar entre 0 e 255.\n";
			}
		} while (g < 0 || g > 255);

		// Validação para o valor de B
		do
		{
			cout << "\nInsira o valor para B (0-255): ";
			cin >> b;
			fflush(stdin);
			if (b < 0 || b > 255)
			{
				cout << "Valor inválido! O valor de B deve estar entre 0 e 255.\n";
			}
		} while (b < 0 || b > 255);

	} while (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || linha < 0 || linha > img4.alt - 1);

	setLinha(&img4, linha, RGB((unsigned char)r, (unsigned char)g, (unsigned char)b));
	gravar(&img4, "exer4.ppm");

	cout << "\nLinha " << linha << " alterada com sucesso! Ver 'exer4.ppm'.\n";
	destruir(&img4);

	cout << "\nPressione qualquer tecla para continuar...";
	getchar();
	system("cls");

// ########################################################################################

	PPM img5;
	int x, y;
	char resposta=' ';

	criar_com_cor(&img5, 500, 500, RGB((unsigned char)r, (unsigned char)g, (unsigned char)b));

	do
	{
		cout << "#     Exercicio 5 - validar coordenadas     #\n";

		cout << "x: ";
		cin >> x;
		fflush(stdin);

		cout << "y: ";
		cin >> y;
		fflush(stdin);

		if (coordValida(&img5, x, y))
			cout << "\nCoordenada valida!\n";
		else
			cout << "\nCoordenada invalida!\n";

		do{
		// Pergunta ao usuário se deseja informar outra coordenada
		cout << "Deseja informar outra coordenada? (s/n): ";
		cin >> resposta;
		fflush(stdin);

		if (tolower(resposta) != 'n' && tolower(resposta) != 's')
			cout << "\nResposta invalida!\n";

		} while(tolower(resposta) != 'n' && tolower(resposta) != 's');
		system("cls");

	} while (tolower(resposta) != 'n' || tolower(resposta) == 's');

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");
// ########################################################################

	PPM img6;


	ler(&img6, "img-base.ppm");

	cout << "#     Exercicio 6 - marcar area     #\n";

	cout << "x1: ";
	cin >> x1;
	fflush(stdin);

	cout << "y1: ";
	cin >> y1;
	fflush(stdin);

	cout << "x2: ";
	cin >> x2;
	fflush(stdin);

	cout << "y2: ";
	cin >> y2;
	fflush(stdin);

	marcarArea(&img6, x1, y1, x2, y2, RGB(r,g,b));
	gravar(&img6, "exer6.ppm");

	destruir(&img6);

	cout << "\nArea marcada com sucesso!\n";

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");



	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");
// #################################################################

	cout << "#     Exercicio 7 - linhas aleatorias     #\n";

	PPM img7;

	criar_com_cor(&img7, 500, 500, RGB(0,0,0));
	linhasAleatorias(&img7);
	gravar(&img7, "exer7.ppm");

	cout << "\nLinhas aleatorias inseridas com sucesso!\n\n";

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");

	destruir(&img7);
// ###################################################################

	cout << "#     Exercicio 8 - copiar regiao     #\n";

	PPM imgBase;
	PPM img8;

	ler(&imgBase, "spider.ppm");

	cout << "x1: ";
	cin >> x1;
	fflush(stdin);

	cout << "y1: ";
	cin >> y1;
	fflush(stdin);

	cout << "\nx2: ";
	cin >> x2;
	fflush(stdin);

	cout << "y2: ";
	cin >> y2;
	fflush(stdin);

	copiarRegiao(&imgBase, &img8, x1, y1, x2, y2);
	gravar(&img8, "exer8.ppm");

	cout << "\nRegiao copiada com sucesso!\n";

	destruir(&imgBase);
	destruir(&img8);

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");
// #####################################################################

	cout << "#     Exercicio 9 - conversao de PPM para PGM     #\n";

	PPM imgBase9;
	PPM img9;

	ler(&imgBase9, "spider.ppm");
	converterPGM(&imgBase9, &img9);

	gravar(&img9, "exer9.ppm");

	cout << "\nImagem convertida para PGM com sucesso!\n\n";

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");

	destruir(&img9);
	destruir(&imgBase9);
// #####################################################################

	cout << "#     Exercicio 10 - inverter imagem horizontalmente     #\n";

	PPM img10;

	ler(&img10, "spider.ppm");
	flipHorizontal(&img10);

	gravar(&img10, "exer10.ppm");

	cout << "\nImagem invertida horizontalmente com sucesso!\n\n";

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");

	destruir(&img10);
// #####################################################################

	cout << "#     Exercicio 11 - marcar area definindo borda     #\n";

	PPM img11;

	ler(&img11, "numeros.ppm");
	marcarAreaComBorda(&img11, 391, 327, 574, 575, 10, RGB(255,0,0));

	gravar(&img11, "exer11.ppm");

	cout << "\nArea marcada com sucesso!\n\n";

	cout << "Pressione qualquer tecla para continuar...";
	getchar();
	system("cls");

	destruir(&img11);

	cout << "Pressione uma tecla para encerrar o programa.\n";
	getchar();
	return EXIT_SUCCESS;
}
