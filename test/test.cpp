#include "gtest/gtest.h"
#include "../header/Project.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

TEST(ProjectTest, AddTask) {
    Project p("test", "description");
    p.addTask("Task 1", "Task 1 description", Deadline(20230213), 3, false);
    EXPECT_EQ(p.completedTasks(), 0);
}

TEST(ProjectTest, CompletedTasks) {
    Project p("test", "description");
    p.addTask("Task 1", "Task 1 description", Deadline(20230213), 3, false);
    p.addTask("Task 2", "Task 2 description", Deadline(20230213), 1, true);
    EXPECT_EQ(p.completedTasks(), 1);
}

TEST(ProjectTest, EditProjectDescription) {
    Project p("test", "description");
    p.editProject_Description("new description");
    EXPECT_EQ(p.outputTasks(), "");
    p.undo_Description();
    EXPECT_EQ(p.description, "description");
}

TEST(ProjectTest, EditProjectName) {
    Project p("test", "description");
    p.editProjectName("new name");
    EXPECT_EQ(p.outputTasks(), "");
    p.undo_Names();
    EXPECT_EQ(p.name, "test");
}

TEST(ProjectTest, GetTask) {
    Project p("test", "description");
    p.addTask("Task 1", "Task 1 description", Deadline(20230213), 3, false);
    Task* t = p.getTask("Task 1");
    EXPECT_EQ(t->getName(), "Task 1");
}

TEST(ProjectTest, SortByPriority) {
    Project p("test", "description");
    p.addTask("Task 1", "Task 1 description", Deadline(20230213), 3, false);
    p.addTask("Task 2", "Task 2 description", Deadline(20230213), 1, false);
    p.sortByPriority();
    EXPECT_EQ(p.outputTasks(), "Name: Task 2\nDescription: Task 2 description\nDeadline: 20230213\nPriority: 1\nStatus: Incomplete\n----------------------\nName: Task 1\nDescription: Task 1 description\nDeadline: 20230213\nPriority: 3\nStatus: Incomplete\n----------------------\n");
}

TEST(ProjectTest, DeleteTask) {
    Project p("test", "description");
    p.addTask("Task 1", "Task 1 description", Deadline(20230213), 3, false);
    p.deleteTask("Task 1");
    EXPECT_EQ(p.outputTasks(), "");
}

TEST(ProjectTest, DoesTaskExist) {
    Project p("test", "description");
    p.addTask("Task 1", "Task 1 description", Deadline(20230213), 3, false);
    bool exists = p.doesTaskExist("Task 1");
    EXPECT_TRUE(exists);
    exists = p.doesTaskExist("Task 2");
    EXPECT_FALSE(exists);
}