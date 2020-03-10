/*Перед попыткой понять, что здесь вообще происходит, прочитай stackTheory.cpp (доступ слева, ага)*/

#include <iostream>
#include <string>

#include <stack> //Для работы с контейнерным классом stack

using namespace std;

template <class TYPE>
void sortStack(stack <TYPE>& stk)
{
 //Тут был код вашего ДЗ
 //А ещё тут могла быть ваша реклама
}

template <class TYPE>
void addInStack(stack <TYPE>& stk, int N, int k)
{ //Функция добавления в стек k элементов после N-го
    stack <TYPE> hStack;
    TYPE temp;

    while (N != 0)
    {
        hStack.push(stk.top());
        stk.pop();
        N--;
    }

    while (k != 0)
    {
        cin >> temp; cin.ignore(32767, '\n');
        stk.push(temp);
        k--;
    }

    while (!hStack.empty())
    {
        stk.push(hStack.top());
        hStack.pop();
    }

    while (!stk.empty())
    {
        cout << stk.top() << ' ';
        stk.pop();
    }

    cout << endl;
}

void stackExample()
{
    stack <int> digits;   //Стек типа int
    stack <char> letters; //Стек типа char
    stack <string> words; //Стек типа string

    cout << "Введите int стек, 0 как конец стека: ";

    int temp = 0;
    cin >> temp;
    while (temp != 0)
    {
        digits.push(temp);
        cin >> temp;
    } cin.ignore(32676, '\n');

    for (int i = 40; i < 50; i++) letters.push(i); //производится приведение типов int -> char

    cout << "Введите пять слов в string стек: ";
    for (int i = 1; i <= 5; i++)
    {
        string temp;
        cin >> temp; cin.ignore(32767, '\n');
        words.push(temp);
    }

    cout << endl;

    /*
                    СУПЕР МЕГА ЗАДАЧА НА ИСПОЛЬЗОВАНИЕ СТЕКА
        Отсортировать введённый с клавиатуры стек, используя вспомогательные
    */

    sortStack(digits);  //Да-да, шаблон функции

    sortStack(words);  //Ага, шаблон и со строками работает. Потому что шаблон!

    if (digits.empty()) cout << "\ndigits пуст\n";
    if (words.empty()) cout << "words пуст\n";

    /*
            Просто задача на стек
        Добавить k элементов после N-го сверху.
        Она перед СУПЕР МЕГА ЗАДАЧЕЙ должна быть, но какая разница?
    */

    cout << "Введи int стек, конец – 0: "; cin >> temp;
    while (temp != 0)
    {
        digits.push(temp);
        cin >> temp;
    }

    int N = digits.size() + 1, k = -1;
    cout << "Введи, после какого СВЕРХУ элемента добавить k других: ";
    while (N > digits.size() || N < 0)
    {
        cin >> N; if (N > digits.size() || N < 0) cout << "Введи нормально, ок? ";
    }

    cout << "Молодец! Теперь введи k (не забывай, тебе ручками потом вводить каждый (КАЖДЫЙ) из этих элементов: ";
    while (k < 0)
    {
        cin >> k; if (k < 0) cout << "Ты как собрался отрицательное количество элементов вводить, уважаемый? Введи нормально: ";
    }

    if (k == 0)
    {
        cout << "Ну ок, 0 тоже число, вот и сиди теперь, ничего не вводи!\n";
        addInStack(digits, N, k); //чисто распечатать
    }
    else addInStack(digits, N, k);
}