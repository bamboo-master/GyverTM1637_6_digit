Основы работы читаем тут! https://github.com/GyverLibs/GyverTM1637#readme

Все тоже самое, добавлена работа еще двух цифр. Отличная опция для самодельных часовых индикаторов. Также вы можете подпаять к своему китайскому модулю еще дву цифры или двойной семисегмент естественно с общим анодом.
![2022-12-25_13-01-22](https://user-images.githubusercontent.com/81521477/209787767-5a4e231b-c0ad-41c2-912a-146e05808b18.png)

Особенности:

Новые разряды я предусмотрел для показаний с микросхемы lm75a (впрочем можете брать свое, хоть секунды или показания другого датчика), в примерах для часов я указал как degs (degrees). 

Примеры естественно пришлось немного изменить иначе просто неработало.

Все ништяки (скроллы, твисты) работают на 4 разряда, остальные 2 не должно.

Инты 4 цифры как минимум выводятся, все 6 не проверял (там довольно мудреные формулы были, не охото разбиратся).

Если у вас модуль с двумя двоеточиями, то проще всего соединить вместе. 

Если у вас модуль tm1637 с 4 или 6 разрядами куплинный и дробной точкой, то лучше пользоватся другой библиотекой она как раз выводит флоаты, так же размещу ее у себяю.
