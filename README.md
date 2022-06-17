# Тестовое задание для компании ООО "РИТМ"

## Зависимости

1. `g++` с поддержкой C++17
1. `cmake`
1. `make`, `ninja` или любой другой генератор для `CMake`
1. `pdflatex`
1. `gnuplot` --- для составления графиков

## Генерация отчёта

Для автоматической сборки и генераци отчёта необходимо из корневой папки проекта
выполнить команду

```console
$ make report
```

После этого отчёт можно будет найти в папке `docs/` под именем `report.pdf`.
Данные можно будет сравнить с
[отчётом, созданным на моём компьютере](docs/report.default.pdf).

## Сборка

Для сборки программы можно воспользоваться правилом в `Makefile`:

```console
$ make ode-num
```

либо напрямую через `CMake`:

```console
$ cmake -G <Unix Makefiles|Ninja> -S . -B build
$ cmake --build build
```
