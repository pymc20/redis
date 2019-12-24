CMAKE_MINIMUM_REQUIRED ( VERSION 3.10 )

PROJECT ( "redis" )

SET ( CMAKE_BUILD_TYPE Debug )

SET ( OUTPUT_FILE a.out )

SET ( SRC_FILES
        ./src/Main.cpp
        ./src/Connect/Connect.cpp
        ./src/Redis/Redis.cpp
        ./src/Create/Create.cpp
        ./src/Validation/Validation.cpp
        )

SET ( CMAKE_CXX_COMPILER "clang++" )

ADD_COMPILE_OPTIONS ( -g -Wall )
SET ( CMAKE_EXE_LINKER_FLAGS "-static -Wl,--gc-sections" )

ADD_EXECUTABLE ( ${OUTPUT_FILE} ${SRC_FILES} )