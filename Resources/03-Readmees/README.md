## README - How You Should Format Them
#### Due: None

## General Idea

Every single folder on your repo should contain a `README.md`. This is because when I or someone else looks at your repo (or project), and clicks on a folder, they will see not just a directory listing, but an explanation and description of what that folder contains. This adds credibility to your repo or project, and makes you not only look like you know what your doing, but also care about how your code is perceived. I understand that a lot (if not most) probably don't want anyone looking at your repos or projects, but you should still put your best foot forward. When I browse repos on Github, I not only rely on the README files for information, but find myself judging the software or library based on how organized and descriptive the README's are. And after talking to other developers, I found that I'm not the only one.

## README's For UVA Assignments

We will use the README's that you will create in every assignment folder to do the following:

- Top of the README:
  - Project Title and problem number (if there is one)
  - Your name
  - Project Description (It needs to be "descriptive". You can take text straight from the assignment / requirements or the pdf. I don't care.)
- After description:
  - List all the files and or folders in that current project in a tabular format with a small description of each file.
  - The filename in that table should link to the actual code file or folder.
- After table:
  - Instructions (not usually necessary for UVA assignments)
    - Any and all information needed to run your code.
    - These instructions will be used for others in the class to run your project on their machine. I PROMISE: you will learn very fast how not to assume things just work. Because they DON'T. When your code doesn't run on anyone else's system and you get a zero, I bet you start to let "assumptions" go out the window.
- Lastly:
  - List any books, sites, message boards where you received help.
  - Describe what help you received. 
  - Help is ok, cut and paste solutions are not.


## Example Assignment README

```
## 111734 - Hectic Pyranomax Syndicated Hexogram
### Peggy Sue 
### Description:

Bacon ipsum dolor amet pork loin kielbasa pork, drumstick leberkas shankle strip steak fatback beef ribs ham hock.
Pork short ribs doner andouille cupim pastrami picanha landjaeger pig. Salami swine capicola spare ribs boudin
leberkas. Capicola ground round pork meatloaf, ham jowl swine prosciutto bacon alcatra pancetta burgdoggen pig
spare ribs leberkas. Shankle fatback ground round, porchetta frankfurter cupim venison strip steak pig meatball
biltong filet mignon. Shoulder chislic ground round pork burgdoggen hamburger.

### Files

|   #   | File                       | Description                                                |
| :---: | -------------------------- | ---------------------------------------------------------- |
|   1   | [main.cpp](./main.cpp)     | solution file.                                             |
|   2   | [input](./input)           | Test input file from problem statement                     |
|   3   | [input2](./input2)         | Larger test input from udebug                              |
|   4   | [input_hex](./input_hex)   | Test file for hexograms to make sure they were right size. |
|   5   | [input_even](./input_even) | Test file to see if any hexograms were even.               |

>I made this stuff up, so don't go reading into it to deeply


### Instructions

- This project was compiled using C++ 17

### Sources

- Stack overflow:
  - https://stackoverflow.com/questions/56710282/how-to-efficiently-write-6-line-hexagrams-horizontally-at-a-capped-width
- Stack Overflow: 
  - https://stackoverflow.com/questions/56692821/how-to-print-hexagram-in-perl
- Book: 
  - 64 hexagrams and 60 Jia Zi pillars for BAZI, Feng Shui, Date selection, Xuan Kong Da Gua and Yi Jing 

I used the sources to help me understand what a hexogram is, and then I used that knowledge to solve the posed problem. 
```

The above markdown will produce a README that looks like:

<img src="https://cs.msutexas.edu/~griffin/zcloud/zcloud-files/example_uva_readme2020.png" width="600">
