#include <iostream>
#include <random>
#include <limits>

// generamos un aleatorio con los minimos y maximos ingresados
int numeroAleatorio(int min, int max) {
    std::random_device rd;  //proporciona numeros aleatorios
    std::mt19937 gen(rd()); // genera numeros aleatorios
    std::uniform_int_distribution<> dis(min, max); // distribuye los numeros entre el minimo y maximo
    return dis(gen);
}

// revisa que los numeros ingresados sean validos, sin decimales. 
int leerEntero() {
    int numero;
    while (true) {
        std::cin >> numero;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear(); // Limpiar el estado de error, para evitar problemas
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignorar la entrada invalida
            std::cout << "Numero no valido, ingrese un numero entero: ";
        } else {
            break;
        }
    }
    return numero;
}

int main() {
    int num1, num2;

    // Pedir al usuario dos numeros, no deben ser consecutivos
    while (true) {
        std::cout << "Ingrese el primer numero entero: ";
        num1 = leerEntero();
        std::cout << "Ingrese el segundo numero entero: ";
        num2 = leerEntero();
        //revisamos que no sean consecutivos
        if (abs(num1 - num2) == 1) {
            std::cout << "Los numeros no deben ser consecutivos. Por favor, intente nuevamente.\n";
        } else {
            break;
        }
    }

    // Determinar el minimo y el maximo para el rango
    int min = std::min(num1, num2);
    int max = std::max(num1, num2);

    // Generar y mostrar el numero aleatorio
    int aleatorio = numeroAleatorio(min, max);
    std::cout << "El numero aleatorio generado es: " << aleatorio << std::endl;

    return 0;
}
