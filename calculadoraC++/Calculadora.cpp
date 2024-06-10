#include "header.hpp"

#ifdef _WIN64
    const char* set = "cls";
    const char* set2 = "pause";
#elif __linux__
    const char* set = "clear";
    const char* set2 = "read";
#else
    const char* set = "error";
#endif

int main ()
{
    while(true)
    {

         do
         {
                #ifdef __linux__
                    std::cout << "linux" << std::endl;
                #endif
                [[nodiscard]]system(set);
                std::cout << "CALCULADORA EXTREMAMENTE SIMPLES PARA UTILIZAR (X+Y) \nPARA SAIR DO PROGRAMA APERTE [S]\n>>>";
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
         
         [[nodiscard]]system(set2);

         [[nodiscard]]system(set);
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