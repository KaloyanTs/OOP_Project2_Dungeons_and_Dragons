@mainpage DND Project Documentation
@subpage Bibliography
<br>@subpage Commands
@tableofcontents

@section Overview
This project is a MMO game in which the main character moves around a map, kills enemies (dragons), collects items and progresses into new maps. The program runs in console mode. Keyboard keys are used for playing. The main goal is to pass all the levels without your health falling below 0.<br>
The main character can be one of 3 types: human, mage or hero, starting at level 1 with fixed stats and being given 30 points to distribute over his stats on level up<br>
The player can equip up to 1 weapon, armor and spell, each of which gives him some bonus.

@subsection cl Supporting classes
For the purposes of the project I have developed:
* class String, representing sequence of characters with any length
* class Vector, representing container of objects of the same type
* class Stack, representing LIFO data structure
* class Grammar, representing context-free grammar, used to generate random names and quotes, based on grammar rules;
* class Image, representing ascii art picture, which can be printed on the console

@section files File organization
![Organization](..\assets\main_8cpp__incl.png)

@section hierarchy Class hierarchy
![Hierarchy0](..\assets\inherit_graph_0.png)
![Hierarchy1](..\assets\inherit_graph_1.png)
![Hierarchy2](..\assets\inherit_graph_2.png)
![Hierarchy3](..\assets\inherit_graph_3.png)
![Hierarchy4](..\assets\inherit_graph_4.png)
![Hierarchy5](..\assets\inherit_graph_5.png)
![Hierarchy6](..\assets\inherit_graph_6.png)
![Hierarchy7](..\assets\inherit_graph_7.png)
![Hierarchy8](..\assets\inherit_graph_8.png)
![Hierarchy9](..\assets\inherit_graph_9.png)
![Hierarchy10](..\assets\inherit_graph_10.png)
![Hierarchy11](..\assets\inherit_graph_11.png)
![Hierarchy12](..\assets\inherit_graph_12.png)
![Hierarchy13](..\assets\inherit_graph_13.png)

@subsection exmpl Example
![Hierarchy11](..\assets\example1.png)
![Hierarchy12](..\assets\example2.png)
![Hierarchy13](..\assets\example3.png)

@section idea Ideas for future developments
There are many concepts and extensions to be developed in the game such as:
* More enemy monsters types
* Some quests giving XP and equipment
* Portals leading to another maps
* More interactive battles
* The main character is not alone, he can lead his own party
* The enemies are not alone, they are in a party
* Options for different difficulty
* Enemies can move on the map, not standing still