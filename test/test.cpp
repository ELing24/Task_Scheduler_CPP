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
TEST(ProjectTest, SortByPriority) {
    Project p("Test Project", "Test Description");
    p.addTask("Task 1", "Task Description 1", 20220501, 2, false);
    p.addTask("Task 2", "Task Description 2", 20220601, 1, false);
    p.addTask("Task 3", "Task Description 3", 20220701, 3, false);

    p.sortByPriority();

    ASSERT_EQ(p.outputTasks(false), 
              "Name: Task 2\nDescription: Task Description 2\nDeadline: 20220601\nPriority: 1\nStatus: Incomplete\n----------------------\n"
              "Name: Task 1\nDescription: Task Description 1\nDeadline: 20220501\nPriority: 2\nStatus: Incomplete\n----------------------\n"
              "Name: Task 3\nDescription: Task Description 3\nDeadline: 20220701\nPriority: 3\nStatus: Incomplete\n----------------------\n");
}

TEST(ProjectTest, SortByDeadline) {
    Project p("Test Project", "Test Description");
    p.addTask("Task 1", "Task Description 1", 20220501, 2, false);
    p.addTask("Task 2", "Task Description 2", 20220601, 1, false);
    p.addTask("Task 3", "Task Description 3", 20220701, 3, false);

    p.sortByDeadline();


    ASSERT_EQ(p.outputTasks(true), 
              "Name: Task 1\nDescription: Task Description 1\nDeadline: 20220501\nPriority: 2\nStatus: Incomplete\n----------------------\n"
              "Name: Task 2\nDescription: Task Description 2\nDeadline: 20220601\nPriority: 1\nStatus: Incomplete\n----------------------\n"
              "Name: Task 3\nDescription: Task Description 3\nDeadline: 20220701\nPriority: 3\nStatus: Incomplete\n----------------------\n");
}
TEST(ProjectTest, outputTasksTest) {
    Project project("Test Project", "This is a test project");
    project.addTask("Task 1", "This is task 1", 20230314, 2, false);
    project.addTask("Task 2", "This is task 2", 20230312, 1, true);
    project.addTask("Task 3", "This is task 3", 20230313, 3, false);

    string expectedOutput1 = "Name: Task 2\nDescription: This is task 2\nDeadline: 20230312\nPriority: 1\nStatus: Complete\n----------------------\n"
                                 "Name: Task 3\nDescription: This is task 3\nDeadline: 20230313\nPriority: 3\nStatus: Incomplete\n----------------------\n"
                                 "Name: Task 1\nDescription: This is task 1\nDeadline: 20230314\nPriority: 2\nStatus: Incomplete\n----------------------\n";
    ASSERT_EQ(expectedOutput1, project.outputTasks(true));

    string expectedOutput2 = "Name: Task 2\nDescription: This is task 2\nDeadline: 20230312\nPriority: 1\nStatus: Complete\n----------------------\n"
                                 "Name: Task 1\nDescription: This is task 1\nDeadline: 20230314\nPriority: 2\nStatus: Incomplete\n----------------------\n"
                                 "Name: Task 3\nDescription: This is task 3\nDeadline: 20230313\nPriority: 3\nStatus: Incomplete\n----------------------\n";
    ASSERT_EQ(expectedOutput2, project.outputTasks(false));
}



