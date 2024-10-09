#include <iostream>
#include "trans2d.hpp"
#include "PPM.hpp"
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

void transformaImagem2DInv(PPM *ppm, PPM *novappm, Matrix3f Minv)
{
    if (ppm->larg != novappm->larg || ppm->alt != novappm->alt)
    {
        cout << "\nErro TransformaImagem2D! Imagens com dimensoes diferentes!\n";
        return;
    }
    // Matrix3f R = getRotation(45.0f);

    for (size_t i = 0; i < novappm->larg; i++)
    {
        for (size_t j = 0; j < novappm->alt; j++)
        {
            Vector3f pS(i, j, 1);
            Vector3f pE = Minv * pS;
            Vector2f pENorm = pE.hnormalized();

            int xE = round(pENorm.x());
            int yE = round(pENorm.y());

            if (coordValida(ppm, xE, yE))
            {
                setPixel(novappm, i, j, getPixel(ppm, xE, yE));
            }
        }
    }
    cout << "\nTransformacao Inversa aplicada com sucesso!\n";
}

void menu(PPM *imgBase, PPM *imgSaida)
{
    criar(imgSaida, imgBase->larg, imgBase->alt);
    static int transformCount = 0; // Contador para gerar nomes únicos de arquivos
    Matrix3f M = Matrix3f::Identity();

    string escolha = " ";

    // Centro da imagem como origem
    Matrix3f Tcent = getTranslation((imgBase->larg - 1) / 2.0f, (imgBase->alt - 1) / 2.0f);
    Matrix3f Tcentinv = getTranslation(-(imgBase->larg - 1) / 2.0f, -(imgBase->alt - 1) / 2.0f);

    do
    {
        cout << "Transformacao Geometrica (R, T, S, RE ou CI): ";
        cin >> escolha;
        fflush(stdin);

        // Converte a escolha para maiúscula
        for (size_t i = 0; i < escolha.size(); i++)
        {
            escolha[i] = toupper(escolha[i]);
        }

        if (escolha == "R")
        {
            float angulo;
            cout << "Angulo: ";
            cin >> angulo;
            fflush(stdin);

            // Aplica rotação
            Matrix3f R = getRotation(angulo);
            M = Tcent * R * Tcentinv * M;  // Acumula a transformação
        }
        else if (escolha == "T")
        {
            float tx, ty;
            cout << "Informe Tx: ";
            cin >> tx;
            fflush(stdin);

            cout << "Informe Ty: ";
            cin >> ty;
            fflush(stdin);

            // Aplica translação
            Matrix3f T = getTranslation(tx, ty);
            M = Tcent * T * Tcentinv * M;
        }
        else if (escolha == "S")
        {
            float sx, sy;
            cout << "Informe Sx: ";
            cin >> sx;
            fflush(stdin);

            cout << "Informe Sy: ";
            cin >> sy;
            fflush(stdin);

            // Aplica escala
            Matrix3f S = getScale(sx, sy);
            M = Tcent * S * Tcentinv * M;
        }
        else if (escolha == "RE")
        {
            char axis = ' ';
            do
            {
                cout << "Informe o eixo (x ou y): ";
                cin >> axis;
                fflush(stdin);

                axis = tolower(axis);

                if (axis != 'x' && axis != 'y')
                {
                    cout << "Erro! Eixo invalido!\n";
                    cout << "Pressione ENTER para continuar...";
                    getchar();
                    system("cls");
                }
            } while (axis != 'x' && axis != 'y');

            // Aplica reflexão
            Matrix3f RE = getReflection(axis);
            M = Tcent * RE * Tcentinv * M;
        }
        else if (escolha == "CI")
        {
            float s;
            cout << "Valor: ";
            cin >> s;
            fflush(stdin);

            char modo = ' ';
            do
            {
                cout << "Modo (H - horizontal | V - vertical): ";
                cin >> modo;
                fflush(stdin);

                modo = tolower(modo);

                if (modo != 'v' && modo != 'h')
                {
                    cout << "Erro! Modo invalido!\n";
                    cout << "Pressione ENTER para continuar...";
                    getchar();
                    system("cls");
                }
            } while (modo != 'v' && modo != 'h');

            // Aplica cisalhamento
            Matrix3f CI = getShear(s, modo);
            M = Tcent * CI * Tcentinv * M;
        }
        else
        {
            cout << "Opcao Invalida!\n\n";
            continue;
        }

        // Aplica a transformação inversa à imagem original
        transformaImagem2DInv(imgBase, imgSaida, M.inverse());

        cout << "\nPressione ENTER para continuar...";
        getchar();
        system("cls");

    } while (escolha != "R" && escolha != "T" && escolha != "S" && escolha != "RE" && escolha != "CI");

    // Não destrói a imgBase no final, pois ela ainda pode ser reutilizada
}


int main(void)
{
    setlocale(LC_ALL, "Portuguese");
    string imagem = " ";

    cout << "########## PROGRAMA DE TRANSFORMACOES 2D ##########\n";

    cout << "Informe a imagem desejada: ";
    cin >> imagem;
    fflush(stdin);

    PPM imgEntrada, imgSaida;

    // Lê a imagem de entrada
    ler(&imgEntrada, imagem);

    cout << "Imagem criada com sucesso!\n";
    cout << "\nPressione ENTER para continuar...";
    getchar();
    system("cls");

    int opcao = -1;
    int cont = 0;

    do
    {
        cout << "Digite 1 para aplicar uma transformacao ou 0 para sair: ";
        cin >> opcao;
        fflush(stdin);

        if (opcao == 1)
        {
            // Primeira vez, criar imgSaida com dimensões de imgEntrada
            if (cont > 0)
                ler(&imgEntrada, "saida.ppm");

            cout << "\nPressione ENTER para aplicar uma transformacao\n";
            getchar();
            system("cls");

            // Aplica a transformação na imagem
            menu(&imgEntrada, &imgSaida);

            // Salva a imagem transformada após cada transformação
            gravar(&imgSaida, "saida.ppm");
            cont++;
        }
        else if (opcao == 0)
        {
            cout << "Opção sair escolhida!\nPressione ENTER para continuar...\n";
            getchar();
            system("cls");
            break;
        }
        else
        {
            cout << "Opção inválida!\nPressione ENTER para continuar...\n";
            getchar();
            system("cls");
        }
        destruir(&imgEntrada);
        destruir(&imgSaida);
    } while (opcao != 0);

    // Destrói as imagens criadas
    destruir(&imgEntrada);
    destruir(&imgSaida);

    cout << "\nPressione uma tecla para encerrar o programa.\n";
    getchar();
    return EXIT_SUCCESS;
}

