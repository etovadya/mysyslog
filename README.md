# Функция `log_function`: Запись лог-сообщений в текстовый файл

Эта функция записывает сообщения в лог-файл в простом текстовом формате. Она предназначена для использования в системах логирования.

## Заголовочные файлы

* `<stdio.h>`: Предоставляет функции для работы с вводом/выводом, такие как `fopen`, `fprintf`, `fclose`, `perror`.
* `<time.h>`: Предоставляет функции для работы со временем, в частности `time`.
* `"libmysyslog.h"`: Пользовательский заголовочный файл. Предположительно, в нем определен тип данных или перечисление, используемое для `level` (вероятно, `int`).

## Объявление функции

Функция `log_function` не возвращает значения (`void`). Она принимает следующие аргументы:

* `const char* msg`: Указатель на строку с текстом лог-сообщения.
* `int level`: Целое число, представляющее уровень логирования (например, 0 - DEBUG, 1 - INFO, 2 - WARNING и т.д.). Значение зависит от определения в `"libmysyslog.h"`.
* `const char* process`: Указатель на строку с именем процесса, генерирующего сообщение.
* `const char* path`: Указатель на строку с путем к лог-файлу.

## Тело функции

1. *Получение текущего времени:* `time_t now = time(NULL);` Получает текущее время в секундах с начала эпохи (1 января 1970 года) и сохраняет его в переменной `now`.

2. *Открытие файла:* `FILE *file = fopen(path, "a");` Пытается открыть файл, указанный в `path`, в режиме добавления (`"a"`). Если файл не существует, он будет создан.

3. *Запись в файл (если открытие прошло успешно):* `fprintf(file, ...);` Записывает строку в файл. Формат строки: `<timestamp> <level> <process> <message>\n`.

4. *Закрытие файла:* `fclose(file);` Закрывает файл после записи.

5. *Обработка ошибок:* `else { perror("Failed to open log file"); }` Если файл не удалось открыть (`fopen` вернул `NULL`), выводится сообщение об ошибке с помощью `perror`.
