cmake_minimum_required(VERSION 4.0.3 FATAL_ERROR)

file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/compiled)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/compiled/read_write_file)
file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR}/compiled/read_write_file/generated_files)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/compiled)

if(DEFINED CMAKE_TOOLCHAIN_FILE)
	get_filename_component(toolchain ${CMAKE_TOOLCHAIN_FILE} NAME_WE)

	if(${toolchain} STREQUAL "toolchain-mingw64")
		add_link_options(-static -static-libstdc++)
	endif()
endif()

project (garbage_code
	VERSION 0.1
	LANGUAGES CXX
)

file(GLOB CPP_SOURCES *.cpp)

foreach (sourcefile ${CPP_SOURCES})
	get_filename_component(filename ${sourcefile} NAME_WE)

	if(DEFINED CMAKE_TOOLCHAIN_FILE)
		if(${toolchain} STREQUAL "toolchain-mingw64" AND ${filename} STREQUAL "rps")
			continue()
		endif()
	elseif(${filename} STREQUAL "rps_win")
		continue()
	endif()

	add_executable(${filename} ${sourcefile})

	if(${filename} STREQUAL "read_write_file" OR ${filename} STREQUAL "read_write_file.exe")
		set_target_properties(read_write_file PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/compiled/read_write_file)
	endif()

endforeach(sourcefile ${CPP_SOURCES})
