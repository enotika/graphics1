Приложение разработано для лабораторной работы №1 по учебному предмету "Программирование компьютерной графики".

Использованные языки и среды программирования:

C++
Qt Creator 4.11.1 Использовался комплект "Desktop Qt 5.14.2 MinGW 32-bit"
Основные объекты приложения:

Одноцветный прямоугольник(отображает выбранный цвет)
семь полей ввода(для каждой цветовой модели)
семь кнопок для изменения цвета
кнопка вызова палитры
Реализованный функционал:

В поле ввода для кажой цветовой модели можно ввести данные и по нажатию на кнопку применить изменения.
Можно нажать на кнопку show Palette и пофвится цветовая палитра, где можно авыбрать цвет на градиентном прямоугольнике, также там есть ползунок отвечающий за насыщенность цвета.


Используемые библиотеки:
<QColorDialog>(вызов цветовой палитры)
<qmath.h>(для использования математических функций)
<QPainter>(для отрисовки цветного прямоугольника)
<QMessageBox>(для вывода сообщений об ошибках)
<QWidget>(основное поле приложения)
<QWidgets>(библиотека, которая содержит большое количество подбиблиотек)
<QLabel>(надписи около полей ввода)
<QTextEdit>(поля ввода)
<QColor>(основная библиотека в среде разработки Qt для работы с цветом)
<QPushButton>(библиотека для использования кнопок)

Работа с репозиторием:

В папке репозитория содержатся несколько исходных файлов. Основные файлы:
mainwindow.h
mainwindow.cpp
main.cpp
mainwindow.ui

Остальные файлы являются вспомогательными.

В папке Executable содержится сборка приложения, его .exe и все необходимые библиотеки и файлы для корректного запуска.