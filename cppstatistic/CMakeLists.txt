# CMakeList.txt: projekt CMake dla elementu cppstatistic, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (cppstatistic "cppstatistic.cpp" "cppstatistic.h" "ctx.cpp" "ctx.h")

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.
