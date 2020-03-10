/*Перед попыткой понять, что здесь вообще происходит, прочитай queueTheory.cpp (доступ слева, ага)*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include <queue> //Для работы с контейнерным классом queue
#include <deque> //Для работы с контейнерным классом deque
#include <iterator>

using namespace std;

void queueExample()
{
  srand(time(0));
  queue <int> digits;   //очередь типа int
  queue <char> letters; //очередь типа char
  queue <string> words; //очередь типа string

  for (int i = 0; i < 10; i++) digits.push(i);

  while (!digits.empty())
  {
    cout << digits.front() << ' ';
    digits.pop();
  } cout << endl;

  priority_queue <int> prDigits; //Расставляй приоритеты

  for (int i = 0; i < 15; i++)
  {
    int t = rand() % 1001;
    cout << t << ' ';
    prDigits.push(t);
  }

  cout << "\n===\n";

  while(!prDigits.empty())
  {
    cout << prDigits.top() << ' ';
    prDigits.pop();
  }
}

void dequeExample()
{
  deque <int> digits; //Дек типа int

  for (int i = 0; i < 10; i++)
  {
    int t = rand() % 1001;
    cout << t << ' ';
    digits.push_front(t);
  }
  
  int temp;
  cout << "Шо в начало добавить? "; cin >> temp;
  digits.push_front(temp);

  cout << "А в конец что запихнём? "; cin >> temp;
  digits.push_back(temp);

  deque <int> tDigits = digits;

  while (!tDigits.empty())
  {
    cout << tDigits.front() << ' ';
    tDigits.pop_front();
  } cout << "\n===\n";

  tDigits = digits;

  copy(tDigits.begin(), tDigits.end(), ostream_iterator<int>(cout, " ")); cout << "\n===\n";

  while (!tDigits.empty())
  {
    cout << tDigits.back() << ' ';
    tDigits.pop_back();
  } cout << "\n===\n";
}