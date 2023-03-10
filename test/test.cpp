#include "gtest/gtest.h"
#include "../header/Subtask.hpp"

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
}