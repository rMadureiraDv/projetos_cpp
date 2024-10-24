#include <iostream>
#include <string>
#include <stdlib.h>

float calculo (std::string &c);

int main ()
{
    std::string calc;
    while (true)
    {
        system("cls");
        std::cout << "CALCULADORA EXTREMAMENTE SIMPLES (REFATORADO) v2.0\nAPERTE [S] PARA SAIR\n>>>";
        try
        {
            std::getline(std::cin,calc);
            if ((calc[0] == 's')||(calc[0] == 'S'))
            {
                break;
            }  
            std::cout << calculo(calc) << std::endl;
            system("pause");
        }
        catch(const std::exception& e)
        {
            system("cls");
            std::cout << "Voce digitou uma letra, digite um numero para calcular\n";
            system("pause");
        }
    }
    
    return EXIT_SUCCESS;
}

float calculo (std::string &c)
{
    float mem1,mem2;
    char op;
    mem1 = std::stof(c);
    for (int i = 0; i <= c.length(); i++)
    {
        if ((c[i] == '+')||(c[i] == '*')||(c[i] == '-')||(c[i] == '/'))
        {
            op = c[i];
            c[i] = ' ';
            i++;
            
            mem2 = std::stof(c);
        }
        c[i] = ' ';
    }
    switch (op)
    {
        case '+':
        return mem1 + mem2;
        break;

        case '-':
        return mem1 - mem2;
        break;

        case '*':
        return mem1 * mem2;
        break;

        case '/':
            if (mem2 == 0)
            {
                throw "Erro, divisao por 0";
            }
            return mem1/mem2;
        break;
    
        default:
            return -1;
        break;
    }
    return EXIT_FAILURE;
}