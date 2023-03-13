CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(test/googletest)

ADD_EXECUTABLE(test
    test/test.cpp
    src/Project.cpp
    src/Base.cpp
    src/ProjectManager.cpp
    src/Task.cpp
)
ADD_EXECUTABLE(runAllFiles
    src/Project.cpp 
    src/Base.cpp 
    src/ProjectManager.cpp 
    src/Task.cpp 
)

ADD_EXECUTABLE(Base
    src/Base.cpp
)

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)