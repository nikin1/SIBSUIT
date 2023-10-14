
#include <stdlib.h>

// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom, int *cnt_C, int *cnt_M)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done)) 
  {
    *cnt_C = *cnt_C + 1;
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    *cnt_C = *cnt_C + 3;
    *cnt_M = *cnt_M + 1;
    // если элемент вершины меньше максимального потомка
    *cnt_C = *cnt_C + 1;
    if (numbers[root] < numbers[maxChild]) 
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
      *cnt_M = *cnt_M + 4;
    }
    else {
      done = 1; // пирамида сформирована
      *cnt_M = *cnt_M + 1;
    }
  }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size, int *cnt_C, int *cnt_M) 
{
    *cnt_C = 0;
    *cnt_M = 0;
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2); i >= 0; i--)
    siftDown(numbers, i, array_size - 1, cnt_C, cnt_M);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    *cnt_M = *cnt_M + 3;
    siftDown(numbers, 0, i - 1, cnt_C, cnt_M);
  }
}