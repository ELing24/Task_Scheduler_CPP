#include "gtest/gtest.h"
#include "../header/Subtask.hpp"
#include "../header/Project.hpp"
#include "../header/Task.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}
TEST(TaskTest, Constructor){
    Task task("", "" , 1 , 1 , false);
    EXPECT_EQ(task.getName(), "");
    EXPECT_EQ(task.getDescription(), "");
    EXPECT_EQ(task.getStatus(), false);
    EXPECT_EQ(task.getDeadline(), 1);
    EXPECT_EQ(task.getPriority(), 1);
}

TEST(TaskTest, AddSubs) {
    Task p("test", "description", 1, 1, false);
    p.addSubtask("Sub 1", "Sub 1 description", false);
    EXPECT_EQ(p.getStatus(), 0);
}

TEST(TaskTest, SetAndGetPriorDeadline){
    Task task;
    task.setPriority(1);
    task.setDeadline(1);
    EXPECT_EQ(task.getPriority(), 1);
    EXPECT_EQ(task.getDeadline(), 1);
}

TEST(TaskTest, changePriority){
    Task task("Test Task Class", "1", 1, 1, true);
    task.changePriority(2);
    EXPECT_EQ(task.getPriority(),2);
    task.undoPriority();
    EXPECT_EQ(task.getPriority(), 1);
}

TEST(TaskTest, GetSubtask){
    Task t("test", "description", 1, 1, false);
    t.addSubtask("subtask", "newdescription",true);
    Subtask* s = t.getSubtask("subtask");
    EXPECT_EQ(s->getName(), "subtask");
}

TEST(TaskTest, deleteSubtask){
    Task t("test", "description", 1, 1, false);
    t.addSubtask("subtask", "newdescription",true);
    t.deleteSubtask("subtask");
    EXPECT_EQ(t.outputsubs(), "");
}

TEST(TaskTest, outputsubs){
    Task task("test", "description", 1, 1, false);
    task.addSubtask("subtask1", "newdescription1",false);
    task.addSubtask("subtask2", "newdescription2",true);
    task.addSubtask("subtask3", "newdescription3",false);
    string expectedOutput1 = "Name: subtask2\nDescription: newdescription2\nStatus: Complete\n----------------------\n"
                                 "Name: subtask3\nDescription: newdescription3\nStatus: Incomplete\n----------------------\n"
                                 "Name: subtask1\nDescription: newdescription1\nStatus: Incomplete\n----------------------\n";
    ASSERT_EQ(expectedOutput1, task.outputsubs(true));
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

TEST(SubTaskTests, DefaultConstructor) {
    Subtask subtask;
    EXPECT_EQ(subtask.getName(), "");
    EXPECT_EQ(subtask.getDescription(), "");
    EXPECT_EQ(subtask.getStatus(), false);
}

TEST(SubTaskTests, ConstructorWithParameters) {
    Subtask subtask("Test Subtask Class", "Write multiple tests to see if every method works as according to plan", true);
    EXPECT_EQ(subtask.getName(), "Test Subtask Class");
    EXPECT_EQ(subtask.getDescription(), "Write multiple tests to see if every method works as according to plan");
    EXPECT_EQ(subtask.getStatus(), true);
}

TEST(SubTaskTests, SetThenGet) {
    Subtask subtask;
    subtask.setName("Test Subtask Class");
    subtask.setDescription("Write multiple tests to see if every method works as according to plan");
    subtask.setStatus(true);
    EXPECT_EQ(subtask.getName(), "Test Subtask Class");
    EXPECT_EQ(subtask.getDescription(), "Write multiple tests to see if every method works as according to plan");
    EXPECT_EQ(subtask.getStatus(), true);
}

TEST(SubTaskTests, ChangeName) {
    Subtask subtask("Test Subtask Class", "Write multiple tests to see if every method works as according to plan", true);
    subtask.changeName("Subtask Class");
    EXPECT_EQ(subtask.getName(), "Subtask Class");
    subtask.undoName();
    EXPECT_EQ(subtask.getName(), "Test Subtask Class");
}

TEST(SubTaskTests, ChangeDescription) {
    Subtask subtask("Test Subtask Class", "Write multiple tests to see if every method works as according to plan", true);
    subtask.changeDescription("Write at least 6 test for the subtask class");
    EXPECT_EQ(subtask.getDescription(), "Write at least 6 test for the subtask class");
    subtask.undoDescription();
    EXPECT_EQ(subtask.getDescription(), "Write multiple tests to see if every method works as according to plan");
}

TEST(SubTaskTests, ChangeStatus) {
    Subtask subtask("Test Subtask Class", "Write multiple tests to see if every method works as according to plan", true);
    subtask.changeStatus(false);
    EXPECT_EQ(subtask.getStatus(), false);
    subtask.undoStatus();
    EXPECT_EQ(subtask.getStatus(), true);


