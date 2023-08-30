## Assignment 5 - Traffic Lights
#### Due: 09-07-2023 (Wednesday @ 1:00 p.m.)

### Overview

[PDF](p161.pdf)

TL;DR: Griffin rambling on about problem solving. Probably needs some editing and a grammar check.

### Traffic Lights

The book categorizes this as a "real life problem". It's listed under **ad-hoc problems**, and this typically means it is not categorized as a problem in which a specific data structure (tree, graph, heap, etc.) or algorithm (binary search, greedy, dynamic programming, etc.) would be beneficial in solving the problem. It doesn't mean you cannot use them, it just means there is no obvious first choice.

So with no disrespect to *Hashmat*, `Traffic Lights` is a good problem to "actually" start with. This problem is really about implementing a set of specific and unambiguous steps as defined in its problem statement. This is also known as: "implementing an algorithm." So, read the problem and go through your steps for solving it. Be cognizant of how you approach the problem, and what steps you take to break it down and solve it. Everyone thinks differently, thats why groups can be helpful when solving problems. In this case the solution is pretty straight forward and I don't foresee any problems, but lets talk about a couple things first. 

>I won't ever do a long writeup like this again. So don't think this is a weekly occurrence.

### Speed or Organization

I've mentioned competitive programming in class. I've mentioned problem solving. I'm starting to think of this course as gaining experience solving problems, while using competitive programming materials and problem sets. Speed matters, but can me more effected by data structure and algorithm choices than by style of writing code. Of course there are compiler flags, and other tricks to speed up your code, but none more effective than discovering a linear time solution to your previous n<sup>2</sup> solution. Having said that, lets talk about some things.

#### Functions

We want our solution to be fast, but we also want to write a good and organized solution. So, do we use functions to organize our code? Do function calls slow down performance? The short answer is: yes. The informed answer is: some times, it depends, and barely :) Heck, the compiler may blow up most of your code to make it more efficient anyway, so you might as well put repetitive logical chunks of code in a function, make sure they work, and forget about them. We can discuss this more in class.

#### Cache Size

If you have prior knowledge of the exact architecture you will run your code on, you may be able to leverage some of that knowledge into speeding up your code. Solutions for problems like this one have such a small footprint, all of the instructions fit entirely in cache, so we can't really influence cache hits and misses. We have less information about the size of the input file, so lets not worry about cache size. Again we can discuss this more in class.

#### Variable Names

Do short variable names run faster than long descriptive ones? You guessed it ... yes .....NO!! The compiler can't even remember what you called your long descriptive variables because it cares so little. It renamed them to something else. So, really big variable names may influence compile time (infinitesimally) but not execution (run) time.

## Breaking Down a Problem

It is really hard to quantify a universal approach to solving problems. So, let me at least list out my high level approach to the types of problems on OnlineJudge.

#### Read Entire Problem

Duh. Obviously. But I read the problem once ... very quickly. I do this to identify .... who knows. Maybe its similar to another problem I've already solved. I'm hoping it will trigger something: an algorithm ("this looks like a shortest path problem"), a type of data structure (vectors ... its always vectors), anything. Your just hoping to glean anything obvious in the once over. Obviously we must read the problem again. A once over won't suffice, but it gives you some highlights to mull over.

#### Read Problem Only

I go back and read it again, carefully this time, and concentrate on the top section: what the problem is asking. To me its like reading a multiple choice question but covering up the answers to see if you know the answer before you actually see it. I say this because the input (the next section) may influence your understanding. And as you saw in class with "Rails" I bought into a belief about a part of the problem, and it threw me off in a really big way. Not sure where I went wrong, but to program something, you must understand it fully! So, I try and read the problem statement a couple times in hopes of getting it, but almost always need the input and output to fully understand whats being asked.

#### Input

So you've read the problem. You are somewhere on the spectrum of understanding, but you're not one hundred percent. You may be hesitant, but you need to start solving this problem, and processing input is a great place to start. While you're deciding how to tackle reading input, and then actually doing it, you're giving yourself time to multi-process. Reading the input correctly forces at least a rudimentary understanding of the problem. It gives the opportunity to:

- Discover the upper and lower bounds of the input values (if those are given). This will help you determine data types to use for variables.
- Also determine (hopefully) if there are any particular data structures that may either help or be a necessity in solving the problem (vectors ... always use vectors :)).

#### Output

If your still struggling with solving the problem, you can start on the output. You don't need to have a full solution to work on formatting your output. And by the time you get your output formatted you may have some ideas ?!? Hopefully anyway, as it's only delaying the inevitable. On a good note, at least you're at a point where you have all of the busy work done, and you can concentrate on ~~Googling~~ solving the problem.

Obviously, if you already have a solid idea for solving the problem, then get at it! Just don't discount the importance of the output. It could simply be a trivial matter of writing data to stdout. Or the specified output could totally change your approach to solving the problem! I've had more than one problem do this to me. It was a problem where cars arrived at time `x, x+1, x+2 ...` and queued up. They were processed, and then left. However they didn't leave in the same order that they arrived! It wasn't an easy fix, and I had to rethink my whole approach. The moral is don't make hasty assumptions. Before totally committing to a solution, make sure you've gone through the whole problem. 


#### Is There A Magic Solution?

When you figure out the solution to solving all problems, let me know! 

There really isn't one solitary approach. And figuring out what works for you is the crux of this course. Each problem will have its own intricacies and nuances, but I can say with confidence that there are two major factors in solving problems:

1. Understanding the problem
2. Experience in solving problems

The first one can be improved upon, but initially it's based a lot on intelligence. For example how many of you can write a recursive algorithm to sum up the digits of an integer? Almost all of you (and hopefully without Google). Of course when I pose that question in 1063 I expect nearly all of the class to **not** see a clear solution. There are only a couple of individuals, in my time teaching, that almost immediately figured it out with zero prior knowledge.  However, once I tell the class that we will use `Div 10` and `Mod 10`, then show them how to apply them, it's like a collective AHA! accompanied with a feeling of "Why didn't I think of that?" It seems obvious ... **after you see it** ... or more specifically after you "**experience**" it. 

There are no known ways to significantly increase mental capacity. But if you expose yourself to problem after problem and solution after solution, you may not technically be "smarter", but you can bet you sure will come off as smart with all the cool stuff you've got crammed in your head. It won't happen in a single semester, but you can give it one heck of a start in the next 15 weeks. 

**Go solve Traffic Lights!**

### Deliverables

- Create a folder called `P161` in your `assignments` folder.
- Place the pdf, your solution code, and any input files you used in this folder.
- Make sure you create an acceptable [README](../../Resources/03-Readmees/README.md) file for this project
- Commit this content to your github repo by the due date.
