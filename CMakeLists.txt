cmake_minimum_required(VERSION 3.10)
project(test_c_plusplus)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "-pg") - use only with GCC 's own profiler

list (APPEND CMAKE_PREFIX_PATH "/media/trk/DATA/OpenSourceLibraries/Qt/5.13.1/gcc_64")

message($CMAKE_PREFIX_PATH)

set(CMAKE_AUTOMOC ON)

SET( _SOURCES_

        ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
)

SET( _HEADER_

        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/add_2_no_to_get_val.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/altonomy.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/bbm_interview_questions.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/bfs_binarytree.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/boost_asio.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/build_binary_tree.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/command.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/cond_variable_lock.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/find_common_elemnt.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/generate_test_data.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/jump_trading.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/learn_atomics.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/learn_variadic_templates.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/move_schematics.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/practice.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/qt_network.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/razer_interview.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/smiths.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/try_cplusplus_17.h
        ${CMAKE_CURRENT_SOURCE_DIR}/hdr/visa_interview.h
)

######################
#Include Definitions #
######################
add_definitions(-DUSING_BOOST_IPC)
add_definitions(-DUSING_LOCK_FREE_CODE)

######################
#Include Directories #
######################
include_directories(

        /media/trk/DATA/OpenSourceLibraries/Qt/5.13.1/gcc_64/include
)

######################
#link Directories    #
######################
link_directories(

        /media/trk/DATA/OpenSourceLibraries/Qt/5.13.1/gcc_64/lib
)

######################
# Create executable  #
######################
find_package(Qt5 COMPONENTS Network REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(${PROJECT_NAME} ${_SOURCES_} ${_HEADER_})

target_link_libraries(${PROJECT_NAME}
        -latomic -lboost_system -pthread -lssl -lcrypto
        -lpthread -Wl,--no-as-needed
        -lprofiler -ltcmalloc
        -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free
        Qt5::Network Qt5::Core Qt5::Widgets
)
