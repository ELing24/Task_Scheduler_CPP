#include "gtest/gtest.h"
#include "../header/Project.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}

TEST(ProjectTest, Constructor) {
    Project project("TestProject", "This is a test project.");
    EXPECT_EQ(project.getProjectName(), "Test Project");
    EXPECT_EQ(project.getProjectDescription(), "This is a test project.");
}

TEST(ProjectTest, AddTask) {
    Project project("TestProject", "This is a test project.");
    project.addTask("Task1", "This is task 1.", 3, 1, false);
    EXPECT_EQ(project.sizeOfTasksVector(), 1);
    project.addTask("Task2", "This is task 2.", 5, 2, true);
    EXPECT_EQ(project.sizeOfTasksVector(), 2);
}

TEST(ProjectTest, CompletedTasks) {
    Project project("TestProject", "This is a test project.");
    project.addTask("Task1", "This is task 1.", 3, 1, false);
    project.addTask("Task2", "This is task 2.", 5, 2, true);
    project.addTask("Task3", "This is task 3.", 2, 3, true);
    EXPECT_EQ(project.completedTasks(), 2);
}

TEST(ProjectTest, EditProjectDescription) {
    Project project("TestProject", "This is a test project.");
    project.editProject_Description("This is a new project description.");
    EXPECT_EQ(project.getProjectDescription(), "This is a new project description.");
    project.undo_Description();
    EXPECT_EQ(project.getProjectDescription(), "This is a test project.");
}

TEST(ProjectTest, EditProjectName) {
    Project project("TestProject", "This is a test project.");
    project.editProjectName("New Test Project");
    EXPECT_EQ(project.getProjectName(), "New Test Project");
    project.undo_Names();
    EXPECT_EQ(project.getProjectName(), "Test Project");
}

TEST(ProjectTest, GetTask) {
    Project project("TestProject", "This is a test project.");
    project.addTask("Task1", "This is task 1.", 3, 1, false);
    project.addTask("Task2", "This is task 2.", 5, 2, true);
    Task* task1 = project.getTask("Task1");
    EXPECT_EQ(task1->getName(), "Task1");
    Task* task3 = project.getTask("Task3");
    EXPECT_EQ(task3, nullptr);
}

TEST(ProjectTest, SortByDeadline) {
    Project project("TestProject", "This is a test project.");
    project.addTask("Task1", "This is task 1.", 3, 1, false);
    project.addTask("Task2", "This is task 2.", 5, 2, true);
    project.addTask("Task3", "This is task 3.", 2, 3, true);
    string expectedOutput = "Name: Task3\nDescription: This is task 3.\nDeadline: 2\nPriority: 3\nStatus: Complete\n----------------------\nName: Task1\nDescription: This is task 1.\nDeadline: 3\nPriority: 1\nStatus: Incomplete\n----------------------\nName: Task2\nDescription: This is task 2.\nDeadline: 5\nPriority: 2\nStatus: Complete\n----------------------\n";
    EXPECT_EQ(project.outputTasks(true), expectedOutput);
}
TEST(ProjectTest, sortByPriorityTest) {
    // Create a new project and add some tasks
    Project project("ProjectA", "Description A");
    project.addTask("TaskA", "Description A", 20220214, 1, false);
    project.addTask("TaskB", "Description B", 20220215, 3, false);
    project.addTask("TaskC", "Description C", 20220216, 2, false);
    project.addTask("TaskD", "Description D", 20220217, 2, false);

    // Call sortByPriority function
    project.sortByPriority();

    // Check if the tasks are sorted by priority
    EXPECT_EQ("TaskA", project.getTask(0)->getName());
    EXPECT_EQ("TaskC", project.getTask(1)->getName());
    EXPECT_EQ("TaskD", project.getTask(2)->getName());
    EXPECT_EQ("TaskB", project.getTask(3)->getName());
}
TEST(ProjectTest, OutputTasksSortedByDeadline) {
  Project project("TestProject", "A project for testing");
  project.addTask("Task1", "Description 1", 20230215, 1, false);
  project.addTask("Task2", "Description 2", 20230216, 2, false);
  project.addTask("Task3", "Description 3", 20230214, 3, false);
  std::string expected_output =
    "Name: Task3\n"
    "Description: Description 3\n"
    "Deadline: 20230214\n"
    "Priority: 3\n"
    "Status: Incomplete\n"
    "----------------------\n"
    "Name: Task1\n"
    "Description: Description 1\n"
    "Deadline: 20230215\n"
    "Priority: 1\n"
    "Status: Incomplete\n"
    "----------------------\n"
    "Name: Task2\n"
    "Description: Description 2\n"
    "Deadline: 20230216\n"
    "Priority: 2\n"
    "Status: Incomplete\n"
    "----------------------\n";
  EXPECT_EQ(project.outputTasks(true), expected_output);
}
TEST(ProjectTest, DeleteExistingTask) {
  Project p("Project1", "Description 1");
  p.addTask("Task1", "Description 1", 20230228, 3, false);
  p.addTask("Task2", "Description 2", 20230301, 2, false);

  p.deleteTask("Task1");

  EXPECT_FALSE(p.doesTaskExist("Task1"));
  EXPECT_TRUE(p.doesTaskExist("Task2"));
  EXPECT_EQ(p.sizeOfTasksVector(), 1);
}
TEST(ProjectTest, DoesTaskExist)
{
    // Initialize Project and add some tasks
    Project project("TestProject", "This is a test project");
    project.addTask("Task1", "This is task 1", 20230228, 2, false);
    project.addTask("Task2", "This is task 2", 20230215, 1, true);
    project.addTask("Task3", "This is task 3", 20230220, 3, false);

    // Test that a task exists in the Project
    EXPECT_TRUE(project.doesTaskExist("Task1"));

    // Test that a task doesn't exist in the Project
    EXPECT_FALSE(project.doesTaskExist("Task4"));
}
TEST(ProjectTest, SizeOfTasksVectorTest) {
    // create a new project and add tasks
    Project project("Project 1", "Description 1");
    project.addTask("Task 1", "Task description 1", 20230220, 1, false);
    project.addTask("Task 2", "Task description 2", 20230215, 2, true);
    project.addTask("Task 3", "Task description 3", 20230225, 3, false);

    // check the size of the tasks vector
    EXPECT_EQ(project.sizeOfTasksVector(), 3);
}

TEST(ProjectTest, GetProjectNameTest) {
    // create a new project
    Project project("Project 2", "Description 2");

    // check the project name
    EXPECT_EQ(project.getProjectName(), "Project 2");
}

TEST(ProjectTest, GetProjectDescriptionTest) {
    // create a new project
    Project project("Project 3", "Description 3");

    // check the project description
    EXPECT_EQ(project.getProjectDescription(), "Description 3");
}