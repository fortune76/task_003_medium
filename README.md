# Задача 3. Уровень Medium. 

Добрый день, коллеги. Сегодня мы продолжаем решать задачи в нашем peer to peer канале Peer Education!

Правила: первое сообщение в канале.

#### Задание

Файл — именованная область данных на носителе информации, используемая как базовый объект взаимодействия с данными в операционных системах.

Работа с файлами реализуется как правило с применением файловых систем, обеспечивающих организацию работы с файлами и абстракцию над носителями информации. Обычно выделяют исполняемые файлы (программы) и собственно файлы данных (например, текстовые файлы или медиаконтейнеры). Формат файла — способ организации данных внутри файла, позволяющий записывать в него информацию в соответствии с её смыслом и интерпретировать записанное. Многие операционные системы приравнивают к файлам и обрабатывают сходным образом и другие ресурсы; наиболее широкое использование понятия файла характерно для Unix-подобных операционных систем, реализующих концепцию «всё есть файл» (англ. everything is a file). В них файлами считаются не только области данных на томе, но и, в частности, физические устройства (порты или принтеры), виртуальные устройства (/dev/null, /dev/random, /dev/urandom и другие), потоки данных (например, именованные каналы), сетевые ресурсы, сокеты.

[Продолжение в википедии](https://ru.wikipedia.org/wiki/%D0%A4%D0%B0%D0%B9%D0%BB)

 <image src="images/shop.jpg" alt="pascal_triangle" width=600px>

> Предисловие: представьте что вы находитесь в такой точке земного шара, в которой нет интернета. Вам поставили задачу разработать очень простую базу данных, для хранения информации о покупках в местном магазине.

###### Задача 1. Необходимо реализовать программу для учета покупок в магазине. В качестве базы данных - текстовый файл database.txt, расположенный в папке ./data относительно корня репозитория. Так же при запуске должна быть возможность передать альтернативный путь к файлу с данными через параметр командной строки (напр.: simple_db ./data/db.txt) Программа циклически должна принимать на ввод одно из ключевых слов. SHOW - показать все записи в файле (после отображения каждой записи включая последнюю - перенос строки), ADD - добавить запись в файл, EXIT - выход из программы. При введении команды ADD, на ввод подается строка с товаром и ценой. Дата должна подставляться автоматически. Записи должны хранится в формате "Дата время товар цена", например: 01.01.2000 12:12:12 Milk 100. Если файл не существует, при первом запуске программа должна создать его. Необходимо проверить корректность введенных команд, данные проверять не нужно. В случае любой ошибки выводить на экран "Puck you, Verter!". Cборка проекта должна осуществляться с использованием Makefile, стадия сборки simple_db. Бинарник должен располагаться в папке bin и называться simple_db. 

> Заказчику так понравилась ваша работа, что он просит вас усовершенствовать программу.

###### Задача 2. Необходимо дополнить предыдущую программу новой командой FIND. При введении этой команды, программа должна выводить на экран все продажи за определенную дату. Дата вводится следом за командой. Если продаж нет, вывести на экран NO DATA. Необходимо проверить корректность введенных команд, данные проверять не нужно. В случае любой ошибки выводить на экран "Puck you, Verter!". Cборка проекта должна осуществляться с использованием Makefile, стадия сборки simple_db_find. Бинарник должен располагаться в папке bin и называться simple_db_find. 

> Заказчик в восторге и разрешает вам отправиться домой, но при одном условии: нужно реализовать последнюю команду.

###### Бонус. Задача 3. Необходимо дополнить предыдущую программу новой командой MAX. При введении этой команды, программа должна посчитать какого товара было продано больше всего и вывести на экран наименование товара и сумму его покупок, например: Milk 1500. Если продаж нет, вывести на экран NO DATA. Если встречаются некорректные строки, то их не учитывать. Необходимо проверить корректность введенных команд. В случае любой ошибки выводить на экран "Puck you, Verter!". Cборка проекта должна осуществляться с использованием Makefile, стадия сборки not_simple_db. Бинарник должен располагаться в папке bin и называться not_simple_db.

> "Я был бы рад тебя оставить, такой работник на вес золота! Но уговор дороже денег, вот твой билет, удачи!" 
