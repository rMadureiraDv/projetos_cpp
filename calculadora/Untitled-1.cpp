#include "header.hpp"



int main ()
{
    while(true)
    {

         do
         {
                system("cls");
                std::cout << "CALCULADORA EXTREMAMENTE SIMPLES APERTE [S] PARA SAIR\n>>>";
                std::cin >> calc;
                if(toupper(calc[0]) == 'S')
                {
                    false;
                    break;
                }
                
         } while (!isdigit(calc[0]));
         if(toupper(calc[0]) == 'S')
                {
                    false;
                    break;
                }
         std::cout << ">>>" << calculo() << std::endl;
         (void)getch();
         system("cls");
    }
    return 0;
}


float calculo()
{
    float mem1,mem2;
    char op; //operator
    mem1 = std::stof(calc);//string to float

    for (int i = 0; i <= calc.length() ; i++)
    {
        if ((calc[i] == '+')||(calc[i] == '-')||(calc[i] == '*')||(calc[i] == '/'))
        {
            op = calc[i];
            calc[i] = ' ';
            i++;
            if (!isdigit(calc[i]))
            {
                return mem1;
            }
            mem2 = stof(calc);
            
            break;
        }
        calc[i] = ' ';
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
                throw "Erro, divisão por 0";
            }
            return mem1 / mem2;
            break;
        default:
            return -1;
            break;
    }
    return mem1;
}