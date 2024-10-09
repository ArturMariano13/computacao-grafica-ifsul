#include <iostream>
#include "trans2d.hpp"
#include "PGM.hpp"
#include <vector>
#include <string>
#include <sstream>

using namespace std;



void lista3_exer2()
{
	cout << "## Exercício 2 - Lista 3 ##" << endl;
	
	Matrix3f S = getScale(1.5f, 0.5f);
	Matrix3f R = getRotation(90.0f);
	Matrix3f T = getTranslation(-6, 0);
	Matrix3f T_ = getTranslation(4, 4);
	Matrix3f T_Inv = getTranslation(-4, -4);

	Matrix3f M = T_ * T * R * S * T_Inv;
	//Matrix 3f M2 = getTranslation(4, 4) * getTranslation(-6, 0);

	vector <Vector3f> pontos;

	pontos.push_back(Vector3f(2, 2, 1));
	pontos.push_back(Vector3f(6, 2, 1));
	pontos.push_back(Vector3f(6, 6, 1));
	pontos.push_back(Vector3f(2, 6, 1));

	for (size_t i = 0; i < pontos.size(); i++)
	{
		Vector3f resposta = M * pontos[i];
		cout << i + 1 << ": " << resposta.hnormalized().transpose() << endl;
	}
}

void lista3_exer3()
{
	cout << "## Exercício 3 - Lista 3 ##" << endl;
	
	Matrix3f S = getScale(1.5f, 0.5f);
	Matrix3f R = getRotation(90.0f);
	Matrix3f T = getTranslation(-6, 0);
	Matrix3f T_ = getTranslation(4, 4);
	Matrix3f T_Inv = getTranslation(-4, -4);

	Matrix3f M = T_ * T * R * S * T_Inv;
	//Matrix 3f M2 = getTranslation(4, 4) * getTranslation(-6, 0);

	vector <Vector3f> pontos;

	pontos.push_back(Vector3f(2, 2, 1));
	pontos.push_back(Vector3f(6, 2, 1));
	pontos.push_back(Vector3f(6, 6, 1));
	pontos.push_back(Vector3f(2, 6, 1));

	for (size_t i = 0; i < pontos.size(); i++)
	{
		Vector3f resposta = M * pontos[i];
		cout << i + 1 << ": " << resposta.hnormalized().transpose() << endl;
	}
}

void lista4_exer2()
{
	string entrada = "T 4 2 4 1 7 3 5 2";

	stringstream strBuffer(entrada);
	string op;

	strBuffer >> op;
	Matrix3f M = Matrix3f::Identity();

	if (op == "T")
	{
		float tx, ty;
		strBuffer >> tx;
		strBuffer >> ty;
		M = getTranslation(tx, ty);
	}

	vector<Vector3f> pontos;
	float x, y;

	while(strBuffer >> x && strBuffer >> y)
	{
		pontos.push_back(Vector3f(x, y, 1));
	}

	for (size_t i = 0; i < pontos.size(); i++)
	{
		Vector3f resposta = M * pontos[i];
		cout << i + 1 << ": " << resposta.hnormalized().transpose() << endl;
	}
}

void lista4_exer3()
{
	vector<Vector3f> pontos;

	pontos.push_back(Vector3f(2,2,1));
	pontos.push_back(Vector3f(6,2,1));
	pontos.push_back(Vector3f(4,6,1));

	float xorigem = 4.0f, yorigem = 4.0f;


	Matrix3f Tinv = getTranslation(xorigem * (-1.0f), yorigem * (-1.0f));
	Matrix3f R = getRotation(90.0f);
	Matrix3f T = getTranslation(xorigem, yorigem);

	Matrix3f M = T * R * Tinv;

	for (size_t i = 0; i < pontos.size(); i++)
	{
		Vector3f resposta = M * pontos[i];
		cout << i + 1 << ": " << resposta.hnormalized().transpose() << endl;
	}
}

void transformaImagem2D(PGM *pgm, PGM *novapgm, Matrix3f M)
{
	if (pgm->larg != novapgm->larg || pgm->alt != novapgm->alt)
	{
		cout << "\nErro TransformaImagem2D! Imagens com dimensoes diferentes!\n";
		return;
	}
	//Matrix3f R = getRotation(45.0f);

	for (size_t i = 0; i < pgm->larg; i++)
    {
        for (size_t j = 0; j < pgm->alt; j++)
        {
            Vector3f ponto(i, j, 1);
			Vector3f pontoSaida = M * ponto;
			Vector2f pSNorm = pontoSaida.hnormalized();

			int xS = round(pSNorm.x());
			int yS = round(pSNorm.y());

			if (coordValida(novapgm, xS, yS))
			{
				setPixel(novapgm, xS, yS, getPixel(pgm, i, j));
			}
        }
    }
	cout << "\nTransformação aplicada com sucesso!\n";
}

void transformaImagem2DInv(PGM *pgm, PGM *novapgm, Matrix3f Minv)
{
	if (pgm->larg != novapgm->larg || pgm->alt != novapgm->alt)
	{
		cout << "\nErro TransformaImagem2D! Imagens com dimensoes diferentes!\n";
		return;
	}
	//Matrix3f R = getRotation(45.0f);

	for (size_t i = 0; i < novapgm->larg; i++)
    {
        for (size_t j = 0; j < novapgm->alt; j++)
        {
            Vector3f pS(i, j, 1);
			Vector3f pE = Minv * pS;
			Vector2f pENorm = pE.hnormalized();

			int xE = round(pENorm.x());
			int yE = round(pENorm.y());

			if (coordValida(pgm, xE, yE))
			{
				setPixel(novapgm, i, j, getPixel(pgm, xE, yE));
			}
        }
    }
	cout << "\nTransformação Inversa aplicada com sucesso!\n";
}

void lista4_exer4()
{
	PGM imgBase;
	PGM exer4;
	ler(&imgBase, "numeros.pgm");
	criar_com_cor(&exer4, imgBase.larg, imgBase.alt, 0);

	Matrix3f rotacao = getRotation(45.0f);

	transformaImagem2D(&imgBase, &exer4, rotacao);
	gravar(&exer4, "exercicio4.pgm");

	destruir(&exer4);
	destruir(&imgBase);
}

void lista4_exer4_inv()
{
	PGM imgBase;
	PGM exer4;
	ler(&imgBase, "numeros.pgm");
	criar_com_cor(&exer4, imgBase.larg, imgBase.alt, 0);

	Matrix3f rotacao = getRotation(45.0f);

	transformaImagem2DInv(&imgBase, &exer4, rotacao.inverse());
	gravar(&exer4, "exercicio4-correto.pgm");

	destruir(&exer4);
	destruir(&imgBase);
}

void rotacaoCentral()
{
	PGM imgBase;
	PGM imgSaida;

	ler(&imgBase, "numeros.pgm");
	criar(&imgSaida, imgBase.larg, imgBase.alt);

	Matrix3f R = getRotation(45.0f);
	Matrix3f T = getTranslation(imgBase.larg/2.0f, imgBase.alt/2.0f);
	Matrix3f Tinv = getTranslation(- imgBase.larg/2.0f, - imgBase.alt/2.0f);

	Matrix3f M = T * R * Tinv;

	transformaImagem2D(&imgBase, &imgSaida, M);

	gravar(&imgSaida, "rotacaoCentral.pgm");

	destruir(&imgBase);
	destruir(&imgSaida);

}

void lista5_exer1()
{
	cout << "### LISTA 5 - EXERCICIO 1 ###\n";
	PGM imgBase, imgSaida;

	ler(&imgBase, "numeros.pgm");
	criar(&imgSaida, imgBase.larg, imgBase.alt);

	Matrix3f T = getTranslation(((imgSaida.larg - 1)/2.0f), ((imgSaida.alt - 1)/2.0f));
	Matrix3f TInv = getTranslation(- ((imgSaida.larg - 1)/2.0f), - ((imgSaida.alt - 1)/2.0f));
	Matrix3f C = getShear(0.9f, 'H');
	Matrix3f Ref = getReflection('y');

	Matrix3f M = T * Ref * C * TInv;

	transformaImagem2D(&imgBase, &imgSaida, M);

	gravar(&imgSaida, "lista5-exercicio1.pgm");

	destruir(&imgBase);
	destruir(&imgSaida);
}

void lista5_exer2()
{
	cout << "### LISTA 5 - EXERCICIO 2 ###\n";
	PGM imgBase, imgSaida;

	ler(&imgBase, "numeros.pgm");
	criar(&imgSaida, imgBase.larg, imgBase.alt);

	Matrix3f T = getTranslation(((imgSaida.larg - 1)/2.0f), ((imgSaida.alt - 1)/2.0f));
	Matrix3f TInv = getTranslation(- ((imgSaida.larg - 1)/2.0f), - ((imgSaida.alt - 1)/2.0f));
	Matrix3f R15 = getRotation(15.0f);
	Matrix3f S = getScale(0.5f, 0.5f);
	Matrix3f R20 = getRotation(20.0f);
	Matrix3f C = getShear(0.7f, 'V');

	Matrix3f M = T * C * R20 * S * R15 * TInv;

	transformaImagem2D(&imgBase, &imgSaida, M);
	//transformaImagem2DInv(&imgBase, &imgSaida, M.inverse());

	// NESSA QUESTAO, NÃO HÁ NECESSIDADE DE UTILIZAR MAPEAMENTO INVERSO = RESPOSTA IGUAL

	gravar(&imgSaida, "lista5-exercicio2.pgm");

	destruir(&imgBase);
	destruir(&imgSaida);
}

void lista5_exer3()
{
	cout << "### LISTA 5 - EXERCICIO 3 ###\n";

	PGM imgBase, imgSaida;
	ler(&imgBase, "numeros.pgm");
	criar(&imgSaida, imgBase.larg, imgBase.alt);

	Matrix3f R = getRotation(45.0f);
	Matrix3f T = getTranslation((imgBase.larg - 1)/2.0f, (imgBase.alt - 1)/2.0f);
	Matrix3f Tinv = getTranslation(- (imgBase.larg - 1)/2.0f, - (imgBase.alt - 1)/2.0f);

	Matrix3f M = T * R * Tinv;

	transformaImagem2DInv(&imgBase, &imgSaida, M.inverse());

	gravar(&imgSaida, "lista5-exercicio3.pgm");

	destruir(&imgBase);
	destruir(&imgSaida);
}

int main(void)
{
	setlocale(LC_ALL, "portuguese");

/*
	Matrix3f T = Matrix3f::Identity();

	T(0,2) = 3;
	T(1,2) = -2;

	cout << T << endl;

	Vector3f ponto1(10, 12, 1);

	Vector3f resposta = T * ponto1;
	Vector2f respostaCartesiana = resposta.hnormalized();
	cout << endl << respostaCartesiana << endl;
*/

	//lista3_exer2();
	//lista4_exer2();

	//lista4_exer3();
	
	//lista4_exer4();
	//lista4_exer4_inv();

	//rotacaoCentral();

// ############################################
// LISTA 5

	//lista5_exer1();

	//lista5_exer2();

	//lista5_exer3();

	cout << "\nPressione uma tecla para encerrar o programa.\n";
	getchar();
	return EXIT_SUCCESS;
}
