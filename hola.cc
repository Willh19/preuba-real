#include <iostream>
#include <random>
#include <conio.h>
#include <vector>

//Gestion cupones de premio

struct InformacionCupon{
    int cant_cupones;
    std::string nombre_persona;
    std::vector <std::pair<std::string, std::string>> cupon_premio;
};

int Randomizer(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100, 999);
    int Randomnumber = dis(gen);
    return Randomnumber;  
}

void ShowReward(int numeros){

    if (numeros % 2 == 0)
    {
        std::cout << " Tienes premio!";
    }
    else if (numeros % 2 != 0)
    {
        std::cout << " No tienes premio :c";
    }

}

void ShowCupon(std::string letras){

    int Random_numbers[5];
    std::string numbers_str = "";

    for (int i = 0; i < 5; i++)
    {
        Random_numbers[i] = Randomizer();
        numbers_str += std::to_string(Random_numbers[i]);
        if (i < 4) numbers_str += " ";
    }

    std::cout << letras << " " << numbers_str << std::endl;

    ShowReward(Random_numbers[4]);

}

std::string ValidacionLetra(std::string letra){
    if (letra.length() == 3)
    {
        return letra;
    }
    else
    std::cout << "Malas letras papu!";
    exit(0);
}

int main(){
    std::string Letras;
    std::cout << "Hola papu pon las letras para el boleto: (recuerda q deben ser 3) \n";
    std::cin >> Letras;
    std::string letra_validada = ValidacionLetra(Letras);
    ShowCupon(letra_validada);


  return 0;
}
