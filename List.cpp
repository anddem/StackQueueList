/*Перед попыткой понять, что здесь вообще происходит, прочитай listTheory.cpp (доступ слева, ага)*/

#include <iostream>
#include <string>

#include <list> //Для работы с контейнерным классом list
#include <iterator> //Работа с итераторами

using namespace std;

void listExample()
{
  list <int> digits;   //Список типа int
  //list <int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  //Так можно инициализировать список, начиная с C++ 11
  list <string> words; //Список типа string

  for (int i = 0; i < 10; i++) digits.push_back(i); //digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}

  cout << digits.front() << ' ' << digits.back() << ' ' << digits.size() << endl; // 0 9 10

  digits.pop_back(); digits.pop_front(); //Убираем 0 и 9

  cout << digits.front() << ' ' << digits.back() << ' ' << digits.size() << endl; // 1 8 8

  digits.clear(); //digits пуст

  if (digits.empty()) cout << "ПУСТОЙ!\n"; //метод .empty() – true если список пустой

  list <int> digits2;

  for (int i = 0; i < 10; i++) {digits.push_back(i); digits2.push_back(2*i);}
  //digits  = {0,  1,  2,  3,  4,  5,  6,  7,  8,  9}
  //digits2 = {0,  2,  4,  6,  8, 10, 12, 14, 16, 18}

  digits.merge(digits2); //Повторы пойдут подряд, но порядок первого не изменится | digits2 стал пустым
  digits2 = digits; //Опять не пуст

  cout << "d2 size: " << digits2.size() << endl; //20
  while (!digits2.empty())
  { //вывод списка
    cout << digits2.front() << ' ';
    digits2.pop_front();
  } cout << endl;

  digits2 = digits; //Not so fast, d2!
  digits2.unique(); //Убрали дубликаты
  cout << "d2 size: " << digits2.size() << endl; //Как видишь, размер изменился на 15
  while (!digits2.empty())
  { //вывод списка
    cout << digits2.front() << ' ';
    digits2.pop_front();
  } cout << endl;

  for (int i = 0; i < 5; i++) digits2.push_back(0); //digits2 = {0, 0, 0, 0, 0}

  list <int> :: iterator it = digits2.begin(); //it указывает "перед" первым нулём

  digits2.insert(it, -10); //digits2 = {-10, 0, 0, 0, 0, 0}
  it = digits2.begin(); //it указывает "перед" -10
  digits2.insert(it, -5); //digits2 = {-5, -10, 0, 0, 0, 0, 0}

  advance(it, +5); //it указывает между последним и предпоследним 0
  digits2.insert(it, -20); //digits2 = {-5, -10, 0, 0, 0, 0, -20, 0} | it между -20 и 0

  advance(it, -2); //it между 0 и -20
  digits.insert(it, -30); //digits2 = {-5, -10, 0, 0, 0, 0, -30, -20, 0}

  copy(digits2.begin(), digits2.end(), ostream_iterator<int>(cout, " ")); cout << endl; //распечатали список, не потеряв его
  
  digits2.remove(0); //digits2 = {-5, -10, -30, -20}
  copy(digits2.begin(), digits2.end(), ostream_iterator<int>(cout, " ")); cout << endl; //опять печатаем




  list <int> :: iterator iEnd = digits2.end(); //iEnd указывает ПОСЛЕ -20
  iEnd--; //Теперь между -30 и -20 

  list <int> :: iterator iBegin = digits2.begin(); //iBegin ПЕРЕД -5
  iBegin++; //Теперь между -5 и -10

  digits2.erase(iBegin, iEnd); //digits2 = {-5, -20}

  //it = digits2.erase(it);  //Удаляя один элемент необходимо обновить итератор

  copy(digits2.begin(), digits2.end(), ostream_iterator<int>(cout, " "));
  
  cout << endl;
}