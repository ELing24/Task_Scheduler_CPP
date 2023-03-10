#include "gtest/gtest.h"
#include "../header/Task.hpp"
#include <iostream>
using namespace std;

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