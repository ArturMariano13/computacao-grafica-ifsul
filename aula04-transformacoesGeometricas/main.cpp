#include <iostream>
#include "PPM.hpp"
#include "trans2d.hpp"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

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
}

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

	lista3_exer2();


	cout << "\nPressione uma tecla para encerrar o programa.\n";
	getchar();
	return EXIT_SUCCESS;
}
