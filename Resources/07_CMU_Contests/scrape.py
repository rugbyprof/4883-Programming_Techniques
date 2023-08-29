import requests

years = [16,23]
semesters = {
    's':'sem0',
    'f':'sem1'
}
letters = ['s','f']

url = 'https://contest.cs.cmu.edu/295/'

x = 0

for i in range(years[0],years[1]+1):
    for j in letters:
        print(url+str(i)+j)
        r = requests.get(url+j+str(i))
        with open("./docs/"+str(x)+"-"+j+str(i)+".html", "wb") as code:
            code.write(r.content)
            x += 1
            
            
            
	 
 
# counting.mark
# games1-spring-2014-6up.pdf	 
# games2-spring-2014-6up.pdf 
# kmp.java
# kmp.txt
# min-cost-flow.txt	 
# range_tree.txt 
# seg_tree.cc
# seg_tree.txt 
# sets.cpp
# stdin-out-in-all-languages.txt
# union-find.txt
# z-string-matching.pdf

