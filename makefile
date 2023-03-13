#output: valgrindTest.o
#valgrindTest.o: src/Project.cpp src/Subtask.cpp src/ProjectManager.cpp src/Task.cpp main.cpp
#	g++ -g -O0 -fno-inline src/Project.cpp src/Subtask.cpp src/ProjectManager.cpp src/Task.cpp main.cpp -o runAllFiles