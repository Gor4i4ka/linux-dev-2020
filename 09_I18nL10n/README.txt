Оригинал "программы" лежит в src, на английском.
Перевод осуществлен на русский.

1)Для сборки:
cd build
cmake ../
make

Русский язык программы запускается:
LANG=ru_RU.utf8 ./task9

Английский язык программы запускается:
LANG=en_US.utf8 ./task9

 (может разниться в различии от установленных диалекторв)

2) Чистка делается:
make allclean

3) Изменение pot и po в случае изменения кода производится в build:
make update_po

(После изменения, чтобы создать mo надо еще раз сделать make)

PS: Обмазывать LANG таргетом не стал, так красивей. 
