## **Alternative Competitive Programming Platforms with APIs**

#### **Codeforces**

- **API**: Codeforces has a well-documented API that allows for retrieving problem statements, user submissions, and results.
- **Usage**: You can track student submissions and generate stats by querying the API for user handles.
- **Considerations**: It's widely used, and students may find solutions easily, but the API is useful for tracking performance.

**Link**: [Codeforces API Documentation](https://codeforces.com/apiHelp)

#### **HackerRank**

- **API**: HackerRank has an API for their enterprise and education versions that can be used to automate submissions, track student progress, and generate reports.
- **Usage**: You can create private tests, custom problems, and use the API to track student progress.
- **Considerations**: HackerRank is a paid solution for education, but it provides robust tools for assessments.

**Link**: [HackerRank for Education](https://www.hackerrank.com/work/solutions/university)

#### **Kattis**

- **API**: Kattis offers an API that allows instructors to create their own contests, view submissions, and track progress.
- **Usage**: This platform is commonly used in universities and has good competitive programming problems.
- **Considerations**: It’s another common platform where students can find pre-existing solutions.

**Link**: [Kattis API Documentation](https://open.kattis.com/help/)

#### **LeetCode (Premium Education Features)**

- **API**: LeetCode offers an API through its premium education package that allows teachers to track progress and submissions.
- **Usage**: LeetCode has a huge repository of problems, but many solutions are available online.
- **Considerations**: Solutions are widely available, but the API could be used for specific assignments or challenges.

**Link**: [LeetCode Premium](https://leetcode.com/subscribe/)

## **Libraries for Creating Your Own Site**

### **Sphere Engine**:

Provides a robust API for compiling, running, and grading code submissions. It supports many programming languages and can be integrated into your own platform.

### **Judge0**:

An open-source online code execution system that supports various languages. It provides an API to compile and run code, and you can integrate it into your site to automate assessment.

### **CMS (Contest Management System)**:

An open-source system used for organizing programming competitions. It includes features like problem definition, automated grading, and scoreboard generation. While more complex, it's highly customizable.

### **HackerRank API or Codeforces API**:

If you prefer to integrate an existing platform, using the API from HackerRank or Codeforces could allow you to build a custom interface that suits your needs while leveraging their backend for execution and evaluation.

## **Alternative Competitive Programming Platforms with APIs**

If you want to build your own platform that compiles, runs, and accepts/rejects solutions, you can use the following tools:

### **Sphere Engine**

- **What it is**: Sphere Engine is a set of APIs that allows you to create an online judge system with compilation, execution, and validation of code in over 80 languages.
- **Usage**: You can use their API to build a custom platform, submit code for execution, and get the results programmatically.
- **Considerations**: Sphere Engine offers robust infrastructure but is a paid service.

**Link**: [Sphere Engine API](https://sphere-engine.com/)

### **Judge0**

- **What it is**: An open-source online code execution system that supports 40+ programming languages.
- **Usage**: You can deploy Judge0 locally or in the cloud and use its API to compile, run, and return results from student submissions.
- **Considerations**: It's an excellent option for building your own platform and can be integrated into custom systems for assessments.

**Link**: [Judge0 GitHub](https://github.com/judge0/judge0)

### **CMS (Contest Management System)**

- **What it is**: CMS is an open-source system designed to manage programming contests. It includes features for compiling, running, and scoring solutions.
- **Usage**: You can use it to create custom problems, manage contests, and automatically evaluate submissions.
- **Considerations**: This is more focused on managing contests, but it can be adapted for classroom use.

**Link**: [CMS GitHub](https://github.com/cms-dev/cms)

### **Mooshak**

- **What it is**: An open-source system for managing programming contests. It supports problem creation, automatic grading, and reporting.
- **Usage**: Mooshak is used in academia for programming contests and can be adapted for classroom assessments.
- **Considerations**: It's an older system, but still functional for basic use cases.

**Link**: [Mooshak Official Site](https://mooshak.dcc.fc.up.pt/)

## **Ideas for Objective Student Assessment**

Given the issue of students finding solutions online, you may want to implement additional strategies to assess their understanding and effort.

#### **Custom Problem Sets**

- Create your own problems instead of using publicly available ones. This reduces the likelihood of students finding solutions online.
- You can use platforms like Judge0 or Sphere Engine to automate the evaluation of these custom problems.

#### **Randomized Inputs and Hidden Test Cases**

- Design problems with random inputs or hidden test cases that students cannot predict.
- Use random input generators and evaluate how their solutions handle edge cases or stress test scenarios.

#### **Code Quality and Efficiency Metrics**

- Go beyond correctness and assess the efficiency and style of their solutions. For example, you can track:
  - Time complexity
  - Space complexity
  - Readability and modularity
- You could use automated tools to analyze code complexity and even check for plagiarism.

#### **Oral Examinations or Code Walkthroughs**

- After students submit their solutions, conduct brief code walkthroughs or oral examinations where they have to explain their approach and thought process.
- This ensures they understand their solution and didn't just copy it.

#### **Peer Reviews and Group Projects**

- Encourage collaborative learning through peer reviews or group projects where students assess each other's code. You can manage this through platforms like GitHub with peer review features.
- This can also foster better learning experiences and discussion.

#### **Time-limited Assessments**

- Conduct assessments where students must solve problems within a strict time limit.
- Use platforms that log submission times, and factor this into the grading to reward efficient problem-solving.

#### **Automated Plagiarism Detection**

- Use tools like **MOSS** (Measure of Software Similarity) to detect plagiarism in code submissions.
- Integrate plagiarism checks into your system to automatically flag suspicious submissions.

**Link**: [MOSS](https://theory.stanford.edu/~aiken/moss/)

### Summary

- **APIs**: Platforms like Codeforces, HackerRank, and Kattis provide APIs to help you monitor student performance automatically.
- **Building Your Own System**: Sphere Engine, Judge0, and CMS are great tools for building your own judging platform.
- **Assessment Strategies**: Custom problems, hidden test cases, oral examinations, and code quality metrics can help you assess your students more fairly and objectively.
