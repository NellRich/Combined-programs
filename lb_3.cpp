// Вариант 21
// Программа, в которой создается два числовых массива одинакового размера.
// Вычисляет сумму попарных произведений элементов этих массивов.

#include <iostream>
#include <ctime>

using namespace std;

// Константа для указания максимальной длинны массивов
constexpr unsigned int ARR_SIZE = 10;
constexpr unsigned int MAX = 15;
constexpr unsigned int MIN = -5;

void task()
{
    // Объявление переменных
    int result = 0;
    unsigned int counter = 0;
    int arr_a[ARR_SIZE], arr_b[ARR_SIZE];

    cout << "a b\n";

    // Инициализация массивов случайными значениями
    for (int i = 0; i < ARR_SIZE; i++)
    {
        arr_a[i] = MIN + rand() % MAX;
        arr_b[i] = MIN + rand() % MAX;

        cout << arr_a[i] << " " << arr_b[i] << endl;
    }

    // Ассемблерная вставка
    _asm {
            BEGIN:
            mov eax, 4 // перемещение указателя с шагом 4 байта
            mul counter
            mov ebx, eax

            mov eax, dword ptr arr_a[ebx]
            imul dword ptr arr_b[ebx]
            add result, eax
            inc counter
            mov eax, counter
            cmp eax, ARR_SIZE
            jne BEGIN
    }

    // Вывод результатов вычислений на ассемблере
    cout << "result: " << result << endl;

    // Проверка вычислений на корректность с помощью С++
    int cpp_result = 0;

    for (int i = 0; i < ARR_SIZE; i++)
    {
        cpp_result += arr_a[i] * arr_b[i];
    }

    // Вывод результатов вычислений на С++
    cout << "cpp_result: " << cpp_result << endl;
}

int main()
{
    // Случайное зерно для генератора
    srand((unsigned int)time(NULL));

    // Основной код
    task();
}
