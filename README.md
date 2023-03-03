[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=9905209&assignment_repo_type=AssignmentRepo)

# Task Scheduler
 
 > Authors: [Abel Challa](https://github.com/abelchalla), [Ethan Lingad](https://github.com/EthanL0224), [Anjali Daryani](https://github.com/adary001), [Siyu Li](https://github.com/slialex)

> ### Project Description
> * Description: In this application, a user can create tasks including a title, description,
classification (e.g. personal, work, study), priority, duration and due date. Some of these
features can also be optional. Users can also create task lists where each list includes
multiple tasks. Task lists can represent larger tasks that have subtasks within them.
Users can display, edit, and delete tasks and task lists. Users should also be able to
undo these operations. 


> ### Important or interesting to us
> * As a college student there are many assignments and projects every week. To complete these assignments efficiently and on time, we need to have a proper planning for these projects. Therefore, a task scheduler is necessary for us. This application can help us to schedule our time properly. This way, we can avoid missing or not being able to finish our assignments due to lack of time. It also helps us to prioritize our assignments according to their complexity and deadline, so that we don't have too many assignments to start with.

> ### Tools and Languages
> * C++ - Programming Language Used
> * Github - Tool used for host of remote repository
> * CMake - Tool used to compile and run code
> * Googletest - Tool for writing and running unit tests
> * Make - Tool to build executables 
> * Draw.io - Tool used to make UML diagrams
> * Valgrind - Tool used for memory access error and leak detections

> ### Inputs:
>Creating a new task: The task's title, description, categorization, priority, duration, and due date would all be values that the user would supply. Some of these parameters might not be required.
Creating a new task list: The task list would be given a name by the user.
Adding a task to a task list: The task and task list would be specified by the user.
Removing a task from a task list: The task and task list to be removed from would be specified by the user.
Editing a task: The job to update and the new values for its characteristics would be specified by the user.
Deleting a task: The job to remove would be specified by the user.
Displaying a task list: The task list to display would be chosen by the user.
Undoing an operation: The action to undo would be specified by the user.

> ### Outputs:
>The task lists and their tasks would be displayed as the application's outputs. The application might, for instance, output the name of the task list together with the title, description, classification, priority, duration, and due date of each item in the list when showing a task list. In addition, the program would provide any necessary confirmations or error messages, such as "Task successfully added to task list."

> ### Features
> * The user of the program will be able to enter subtasks integrated inside of the task. As an example, if the user creates a task that's called "Clean Kitchen", then the user can also create subtasks within that task such as "Wash Dishes", "Take Out Trash", "Clean Out Refrigerator", or "Wipe Counters". Users will be prompted to enter the name of the task, a description of the task, the status of the task, and the deadline for the task. Users can prioritize tasks by ranking them in order of importance. Depending on each task's priority, the program would output the tasks in a particular format. The user can evaluate whether task is more significant than the other by viewing it in a specific manner. Users can be able to edit and delete tasks. The user has the flexibility to alter the name, description, due date, and status whenever they want. A user has the option to delete a task if they decide they no longer want it to be visible. Users have the option to undo their activity if they accidentally edit tasks in the wrong way. The user won't have to delete and start a brand-new task as a result.

## Class Diagram
 ![](images/UML_CS100P.png)
 > Our class diagram consists of five classes. The Base class are the traits that the classes subtask and Task will inherit. Common traits that subtask and Task will have is having a name, description, and status. The difference that the class Task has that subtask does not have is the priority and deadline since it's more signficant than a subtask. The Task class will consist of a vector that stores several subtasks which is means there is a composition relationship between the two. The class Project is another class that will have vector that stores multiples task in one place in case the user would like to group task together and have subtasks within it. The last class, ProjectManager, is the class that would control multple projects if the user wants to make multple tasks and subtasks. It serves to organize the amount projects if the user want to make plenty of ones. We also incorporated a SOLID principle in our project, which is the single responsibility principle. Our Deadline class is responsible for making sure the user enters a correct date and that the date gets stored within the Deadline class. The Task class will have an object of Deadline for each task that exists so that it ensures the user validity in entering the correct date. Another instance of where we have the single responsibility principle present in our program is the ProjectManager class. This class also serves as a single responsibility role, since its job is to help manage and control keeping tracks of several projects the user has. It would make sure to know how to track the projects, delete projects, initialization, etc.
 
 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
