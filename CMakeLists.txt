cmake_minimum_required(VERSION 3.2)

project(travis_coredump)
message("Building travis_coredump.")

if(MSVC)
	set(CMAKE_CXX_FLAGS
		"${CMAKE_CXX_FLAGS} /std:c++latest"
	)
else()
	set(CMAKE_CXX_FLAGS
		"${CMAKE_CXX_FLAGS} -std=gnu++1z -g"
	)
endif()

add_executable(travis_coredump 
	"might_crash.cpp"
)