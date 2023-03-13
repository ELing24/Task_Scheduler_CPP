CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

ADD_SUBDIRECTORY(test/googletest)

ADD_EXECUTABLE(testRun
    test/test.cpp
    src/Project.cpp
    src/ProjectManager.cpp
    src/Task.cpp
    src/Subtask.cpp
)
ADD_EXECUTABLE(runAllFiles
    src/Project.cpp 
    src/Subtask.cpp 
    src/ProjectManager.cpp 
    src/Task.cpp 
    main.cpp
)


TARGET_LINK_LIBRARIES(testRun gtest)
TARGET_COMPILE_DEFINITIONS(testRun PRIVATE gtest_disable_pthreads=ON)