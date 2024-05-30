#include <iostream>// Команда препроцессора начинается #
#include "foo.hpp"

#define PI 3.14 //Константа препроцессора 
#define forever for (unsigned long long i = 0;; i++) //Структуры и конструкции
#define begin {
#define end }

#define sum(a, b) (a + b) //Макрос получается нужно ставит ()
#define var(name) std::cout << #name" = " << name << std::endl // # оператор преобразование в строку

#define print_arr(arr, length)\
	std::cout << "{ ";\
	for (int i = 0; i < length; i++)\
		std::cout << arr[i] << ", ";\
	std::cout << "\b\b }\n"


#define test 0

#if test == 1 
void foo() {
	std::cout << "Тест №1\n";
}

#elif test == 2
void koo() {
	std::cout << "Тест №2.\n";
}

#elif test == 0 
void poo() {
	std::cout << "Нет активных тестов. \n";
}
#else 
#error "Неверный код теста!" //принудительная ошибка
#endif

#define FLAG
#ifdef FLAG
void func() {
	std::cout << "Я есть func!\n";
}
#endif
#ifndef FLAG
#error Флаг не объявлен
#endif



int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
#if test == 0
	poo();
#endif


	// Константы и конструкции.
	std::cout << "PI = " << PI << std::endl;
	double radius = 3;
	double area = PI * radius * radius;
	std::cout << "Area = " << area << std::endl;

	forever begin //forove подставляется цикл, begin меняется {;
		std::cout << '.';
		if (i > 1000)
			break;
		end// заменяется };
		std::cout << std::endl;
#undef PI 	// удаление константы
			//std::cout << "PI = " << PI << std::endl;

#define PI 3 
		std::cout << "PI = " << PI << std::endl;

	//Макросы препроцессора. \-перенос 
	n = 7; m = 15;
	std::cout << n << " + " << m << " = " << sum(n, m) << std::endl;
	
	var(n);
	var(m);

	const int size = 3;
	int arr[size]{ 42, 7, 15 };
	print_arr(arr, size);
#if test == 1
	foo();
#elif test == 2
	koo();
#endif




	return 0;
}