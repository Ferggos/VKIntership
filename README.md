## Тестовое задание для стажера на позицицю "Разработчик C++"

#### Необходимо написать программу на C++, которая будет считать кратчайшее расстояние от переданной вершины (номер) до всех остальных вершин в ненаправленном графе. Расстояние до каждый вершины от переданной необходимо вывести на экран.

Структура графа должна считываться из файла. Пример файла graph.txt:

5

4

0 1

0 4

1 2

1 3

4

Файл имеет фиксированную структуру.

  - Первая строка - количество вершин графа.
  - Вторая строка - количество ребер в графе.
  - Далее идут ребра графа ("0 1" означает, что существует путь от вершины с номером 0 до вершины с номером 1).
  - Длина каждого ребра равна 1.
  - Последняя строка - номер вершины, от которой необходимо посчитать расстояние до всех остальных.
  - Нумерация вершин всегда начинается с нуля.
  - Допускаем, что точно существует путь до каждой вершины от каждой.

Вывод для тестовых данных выше:
1

2

3

3

0
