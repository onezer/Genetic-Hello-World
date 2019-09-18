

cmake_minimum_required (VERSION 3.15)
project (GeneticHelloWorld)

set(srcs 
	src/main.cpp
	src/entity.cpp
	src/genetic.cpp
	src/population.cpp
	)
	
set(headers
	header/entity.h
	header/genetic.h
	header/population.h
	header/parameters.hpp
)

add_executable(${PROJECT_NAME} ${srcs} ${headers})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/header)

set(CMAKE_SUPPRESS_REGENERATION true)