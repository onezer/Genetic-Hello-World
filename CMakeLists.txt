cmake_minimum_required (VERSION 3.15)
project (EvolutionaryRobotSwarm)

set(srcs 
	Source/FileWriter.cpp
	Source/Main.cpp
	Source/Map.cpp 
	Source/MapHandler.cpp 
	Source/Robot.cpp 
	Source/Simulation.cpp 
	
	Header/Node.hpp 
	Header/Position.hpp 
	Header/e_collision.hpp
	Header/Telemetry.hpp
	)
	
set(headers
	Header/FileWriter.h 
	Header/Map.h 
	Header/MapHandler.h 
	Header/Robot.h 
	Header/Simulation.h 
	Header/iBehaviour.h
	Header/iBehaviourFactory.h
	Header/iCost.h 
)

add_executable(EvolutionaryRobotSwarm ${srcs} ${headers})

target_include_directories(EvolutionaryRobotSwarm PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Header)

set(CMAKE_SUPPRESS_REGENERATION true)