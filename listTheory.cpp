/*
list построены на двусвязных списках
Каждый элемент знает о следующем и предыдущем
H -> A1 <-> A2 <-> A3 <- A4

Добавление и удаление элементов происходит за константное время, т.к. для этого нужно лишь манипулировать указателями
Например, чтобы добавить элемент в массив необходимо изменить его структуру, освободив место под элемент.
В списках же нужно лишь направить указатели
*/

//Работа через библиотеку
#include <list>
//И класс list <type>

/*
Синтаксис
list <тип_данных> имя;

Тип – любой необходимый: int, char, string и т.д.
*/

/*
Работа со списком
имя_списка.front() – возврат значения первого элемента;
имя_списка.back() – возврат значения последнего элемента;

имя_списка.push_front([значение]) – добавление элемента в начало;
имя_списка.push_back([значение]) – добавление элемента в конец;

имя_списка.insert([итератор], [значение]) – добавить элемент в определённое место;

имя_списка.pop_front() – удаление первого элемента;
имя_списка.pop_back() – удаление последнего элемента;

имя_списка.remove([X]) – удаление всех элементов со значением X;
имя_списка.erase([начало_интервала], [конец_интервала]) – удалить элементы в интервале

имя_списка.size() – вывести количество элементов в списке;
имя_списка.clear() – очистка списка;

имя_списка.unique() – очистка списка от дубликатов;
имя_списка.merge([другой_список]) – добавить элементы одного списка в другой; //Список в скобках станет пустым

copy([начало], [конец], [итератор]) – вывод (и не только) элементов списка. Работает при подключённой библиотеке <iterator>

Для вывода: copy(имя_списка.begin(), имя_списка.end(), ostream_iterator<тип_списка>(cout, ' '));
*/

/*
Итератор используется для работы с list
*/

//Работа через библиотеку
#include <iterator>

/*
Синтаксис
<(list, map, vector, set)> <тип> :: iterator имя;
*/

/*
В итератор можно передать начало или конец контейнера методами .begin() и .end() соответственно

имя_итератора = имя_контейнера.begin(); //можно при инициализации
имя_итератора = имя_контейнера.end(); //указывает на 1 больше, чем последний элемент

Для итераторов на list нельзя использовать арифметические операции и операции сравнения > <
Но можно:
инкремент и декремент: имя++; имя--;
разыменование: cout << *имя; *имя += 5;
сравнение на равенство: имя1 == имя2; имя1 != имя2;

Через инкремент и декремент мы можем перемещаться только на один элемент
Для перемещения на несколько используется фукнция
advance([итератор], [+- значение])
advance(имя, +5);
advance(имя, -2)

Итератор это НЕ УКАЗАТЕЛЬ
list <int> Name;
Name <int> :: iterator iName;

int c = 10, *pC = &c;

iName = pC; //Ошибка
*/