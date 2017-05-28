[![Travis-CI][travis-badge]][travis-builds]

[travis-badge]: https://travis-ci.org/firefly114/lab8.svg?branch=master
[travis-builds]: https://travis-ci.org/firefly114/lab8/builds
### Lab8

Створити TCP-сервер, що слухає запити на підключення TCP клієнтів і взаємодіє з ними за допомогою протоколу __HTTP__. 
Сервер повинен обробляти лише HTTP __GET__ запити і повертати коректно-сформовані HTTP-відповіді. 
Інтерфейс сервера дозволяє звертатися до нього по HTTP-шляхах:

* `/` - відправити у відповідь JSON-об'єкт із інформацією про сервер: 
    ```json
    {
        "title": "%SERVER_NAME%", 
        "developer": "%YOUR_NAME_SURNAME%", 
        "time": "%SERVER_TIME%"
    }
    ```
* `/favorites` - JSON-список із об'єктів, що позначають список ваших улюблених акторів. 
Кожен такий об'єкт має мати декілька полів, серед яких обов'язково має бути числове поле `id` 
із унікальним для кожного об'єкта значенням.
* `/favorites?{key}={value}` - JSON-підсписок тих об'єктів зі списку `/favorites`, 
у яких поле `{key}` має значення `{value}`. Ключ `{key}`, по якому відбувається фільтрація списку, обрати довільно.
* `/favorites/{id}` - JSON-об'єкт зі списку `/favorites` за ідентифікатором з числовим значенням `{id}`. 
Якщо об'єкта із таким значенням `id` не було знайдено, повертати у відповідь HTTP статус `404 Not Found`.
* `/file` - зчитати вміст файлу `data.txt`, який попередньо розмістити у директорії `data/` проекту. 
Відправити клієнту JSON-об'єкт, що містить у собі інформацію про назву, розмір (у байтах) і текстовий вміст файлу.
* `/file/data` - у відповідь клієнту відправити JSON-список всіх чисел на парній позиції у файлі (файл `data.txt`).

### Modules:
* actor.h - Data about favorite actor
* response.h - Server response 
* request.h - Client request
* jsonconverter.h - Converts data to Json string

