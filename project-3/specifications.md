# Guild Management System

## Project Requirements

### Goal

Create a console-based RPG Guild Management System using only:

* Modern C++
* STL containers
* STL algorithms
* Smart pointers
* File I/O

No external libraries.

No GUI.

No networking.

No databases.

No design patterns are required.

The objective is to practice OOP, inheritance, polymorphism, STL, file handling, exceptions, lambdas, and operator overloading in one cohesive project.

---

# Functional Overview

The application manages a guild of adventurers.

The user can:

* Load guild data from a text file
* View all guild members
* View all quests
* Assign quests to members
* Complete quests
* Recruit new members
* Remove members
* Search for members
* Generate guild statistics
* Save a report to a text file

---

# Required Language Features

The project must contain:

## Classes

Multiple classes with clear responsibilities.

## Inheritance

A base GuildMember class with multiple derived classes.

## Polymorphism

Virtual functions must be used.

## Smart Pointers

Use:

```cpp
std::unique_ptr
```

for member ownership.

## STL Containers

At minimum:

```cpp
std::vector
std::map
```

## STL Algorithms

Use several of:

```cpp
std::sort
std::find_if
std::count_if
std::for_each
std::max_element
std::min_element
```

## Lambdas

Required with STL algorithms.

## Operator Overloading

Required.

## Exceptions

Required.

## File I/O

Required.

## Enums

Required.

---

# Class Hierarchy

## Base Class

GuildMember

Purpose:

Represents any member of the guild.

### Fields

* id
* name
* level
* health
* goldEarned

### Methods

#### Virtual

calculatePower()

Returns member combat power.

display()

Displays member information.

getClassName()

Returns class name.

#### Non-Virtual

getId()

getName()

getLevel()

getGoldEarned()

addGold()

levelUp()

---

# Derived Classes

## Warrior

Additional Field

* armor

Overrides

* calculatePower()
* display()
* getClassName()

Power Formula

Level * 10 + Health + Armor

---

## Mage

Additional Field

* mana

Overrides

* calculatePower()
* display()
* getClassName()

Power Formula

Level * 15 + Mana

---

## Ranger

Additional Field

* accuracy

Overrides

* calculatePower()
* display()
* getClassName()

Power Formula

Level * 12 + Accuracy + Health / 2

---

## Healer

Additional Field

* healingPower

Overrides

* calculatePower()
* display()
* getClassName()

Power Formula

Level * 11 + HealingPower + Health / 3

---

# Quest Class

Represents a quest.

## Fields

* id
* name
* difficulty
* rewardGold
* requiredPower
* status

Optional

* assignedMemberId

## Methods

display()

complete()

assign()

getters

setters

---

# Enum Types

## MemberClass

```text
Warrior
Mage
Ranger
Healer
```

---

## QuestStatus

```text
Available
Assigned
Completed
Failed
```

---

## Difficulty

```text
Easy
Medium
Hard
Extreme
```

---

# Guild Class

Purpose:

Central manager of the application.

This class owns all members and quests.

## Fields

### Members

```cpp
vector<unique_ptr<GuildMember>>
```

### Quests

```cpp
vector<Quest>
```

### Optional Fast Lookup

```cpp
map<int, size_t>
```

for member IDs.

---

# Guild Methods

## Loading

loadFromFile()

Reads all data from file.

---

## Saving

saveReport()

Creates report file.

---

## Member Management

addMember()

removeMember()

findMemberById()

searchMemberByName()

displayMembers()

---

## Quest Management

displayQuests()

assignQuest()

completeQuest()

findQuestById()

---

## Statistics

showStatistics()

getStrongestMember()

getAverageLevel()

getCompletedQuestCount()

---

# Operator Overloading

Required

## Stream Output

```cpp
cout << member
```

Displays member information.

---

## Equality

```cpp
memberA == memberB
```

Compare IDs.

---

## Greater Than

```cpp
memberA > memberB
```

Compare power.

---

# Exception Requirements

Throw exceptions for:

## Member Not Found

Invalid member ID.

---

## Quest Not Found

Invalid quest ID.

---

## Invalid Menu Choice

User enters invalid selection.

---

## Quest Already Assigned

Cannot assign again.

---

## Corrupted File Data

Invalid file format.

---

# STL Algorithm Requirements

## Sort Members By Level

Using:

```cpp
sort()
```

---

## Search Member By Name

Using:

```cpp
find_if()
```

---

## Count Completed Quests

Using:

```cpp
count_if()
```

---

## Find Strongest Member

Using:

```cpp
max_element()
```

---

## Generate Statistics

Using:

```cpp
for_each()
```

or similar.

---

# Lambda Requirements

Use lambdas with:

* sorting
* searching
* counting
* statistics

Examples:

Sort by level.

Sort by power.

Find by name.

Count completed quests.

---

# Menu Structure

```text
==================================
GUILD MANAGEMENT SYSTEM
==================================

1. Load Data
2. View Members
3. View Quests
4. Assign Quest
5. Complete Quest
6. Recruit Member
7. Remove Member
8. Search Member
9. Guild Statistics
10. Save Report
0. Exit
```

---

# Input File

Filename

guild_data.txt

Format

#MEMBERS

101|Warrior|Aria|12|150|40|800
102|Mage|Merlin|15|90|120|1200
103|Ranger|Sylvan|10|110|65|650
104|Healer|Luna|13|100|70|500
105|Warrior|Ragnar|18|200|60|1700
106|Mage|Elric|9|85|95|400
107|Ranger|Nyx|11|120|70|700
108|Healer|Seraphina|14|105|80|950
109|Warrior|Darius|16|190|55|1450
110|Mage|Aurelia|20|95|150|2200
111|Ranger|Kael|8|100|55|350
112|Healer|Mira|7|90|60|280
113|Warrior|Thorne|13|175|45|950
114|Mage|Zephyr|17|88|135|1600
115|Ranger|Rowan|12|125|72|850

#QUESTS

501|Goblin Camp|Easy|200|50|Available
502|Lost Caravan|Easy|250|60|Available
503|Ancient Ruins|Medium|500|90|Available
504|Bandit Fortress|Medium|650|110|Available
505|Dragon Cave|Hard|1500|180|Available
506|Haunted Forest|Medium|550|100|Available
507|Necromancer Tower|Hard|1800|200|Available
508|Royal Escort|Easy|300|70|Available
509|Spider Nest|Medium|450|95|Available
510|Demon Rift|Extreme|3000|300|Available
511|Sunken Temple|Hard|1600|190|Available
512|Crystal Mine|Easy|220|55|Available
513|Wyvern Hunt|Hard|1400|175|Available
514|Ancient Library|Medium|600|105|Available
515|Titan Awakening|Extreme|4000|350|Available

---

# Output File

Filename

guild_report.txt

Must contain:

* Total Members
* Total Quests
* Completed Quests
* Strongest Member
* Average Level
* Total Gold Earned
* Members Per Class
* Completed Quest List

Format is your choice.

---

# Suggested Folder Structure

```text
src/

main.cpp

Guild.h
Guild.cpp

GuildMember.h
GuildMember.cpp

Warrior.h
Warrior.cpp

Mage.h
Mage.cpp

Ranger.h
Ranger.cpp

Healer.h
Healer.cpp

Quest.h
Quest.cpp

Enums.h

data/

guild_data.txt

output/

guild_report.txt
```

---

# Definition of Done

The project is complete when:

* Data loads from file
* Members are created dynamically
* Polymorphism works through base pointers
* Quests can be assigned
* Quests can be completed
* Statistics are generated
* STL algorithms are used
* Lambdas are used
* Exceptions are handled
* Report file is generated
* No external libraries are used

```
```
