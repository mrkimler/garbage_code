cmake_minimum_required(VERSION 4.0.3 FATAL_ERROR) #Минимальная версия CMake

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/compiled) #Создание директории
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/compiled/read_write_file)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/compiled/read_write_file/generated_files)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/compiled) #Установка директории для билда

if(DEFINED CMAKE_TOOLCHAIN_FILE) #Проверка на прописку в командной строке переменной
    get_filename_component(toolchain ${CMAKE_TOOLCHAIN_FILE} NAME_WE) #Получение имени файла без пути и расширения

    if(${toolchain} STREQUAL "toolchain-mingw64") #Строки одинаковы? Если да выполнить код ниже
        add_link_options(-static -static-libstdc++) #Указывание, что библиотеки должны быть статическими
    endif()
endif()

project (garbage_code #Имя проекта
 VERSION 0.1 #Версия проекта
 LANGUAGES CXX #Языки в проекте
)

file(GLOB CPP_SOURCES *.cpp) #Создание листа файлов
list(REMOVE_AT CPP_SOURCES 18;1;51;48;31) #Убираем ненужные файлы

file(GLOB PERSON_SOURCES for_compilation/person/*.cpp)

foreach (sourcefile ${CPP_SOURCES}) #Перебирание листа файла
    get_filename_component(filename ${sourcefile} NAME_WE)

    if(DEFINED CMAKE_TOOLCHAIN_FILE)
        if(${toolchain} STREQUAL "toolchain-mingw64" AND ${filename} STREQUAL "rps")
            continue()
        endif()
    elseif(${filename} STREQUAL "rps_win")
        continue()
    endif()

    add_executable(${filename} ${sourcefile}) #Добавить исполняемый файл

    if(${filename} STREQUAL "read_write_file" OR ${filename} STREQUAL "read_write_file.exe")
        set_target_properties(read_write_file PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/compiled/read_write_file) #После добавления исполняемого файла можно уточнить его путь.
    endif()

endforeach(sourcefile ${CPP_SOURCES}) #Конец цикла

foreach(personSourceFile ${PERSON_SOURCES})
    get_filename_component(personFileName ${personSourceFile} NAME_WE)

    add_executable(${personFileName} ${personSourceFile};for_compilation/person.cpp) #Объединение файлов в один
endforeach(personSourceFile ${PERSON_SOURCES})

add_executable(manyfile_proj manyfile_proj.cpp;for_compilation/Foo.cpp;for_compilation/Bar.cpp;for_compilation/myclass.cpp;for_compilation/sum.cpp)
