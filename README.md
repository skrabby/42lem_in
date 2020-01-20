# 42Lem_in
#### Disclaimer:

For this specific project only those functions were allowed:
read, write, malloc, free, perror. Memory leaks, "for" loops, > 25 line functions as well as complicated ternary operations (ternary inside ternary) are prohibited, makefile has to be linked and smooth.

#### Task:
[link]

Example of the input that could be given and how does it look:

<img src="https://i.imgur.com/lLRIG8C.png" width="900" title="Pieces">

#### Approach:
First of all, it took a while for me to actually understand what is required to do.
Once I've got the abstract picture and the purpose of this project I started googling about the disjoint path finding algorithms. I found myself interested in the **Bhandari** algorithm (modification of Suurballe), which, to my opinion, had the similar time-cost with its former algorithm, but was much simplier to implement in code.
Once everything was done, even though the time efficiency was quite decent, I wanted to upgrade the way we store our data.

Initially, we did not store our nodes in a list, but rather in an array of pointers and it was available to access to them through their indexes. But that, actually, did not benefit us much as we still have to iterate through them during the parsing process in order to link them with each other. It is quite painful to do, that is why we have implemented a **Hashtable**, which has significatly improved the searching process, and decided to arrange a gap of 100 cells for each node to reduce the number of possible collisions.

#### Algorithm:
In a nutshell, Bhandari algorithm requires us to do the following:
1) Find the shortest path (with the **Dijkstra** algorithm, for instance)
2) Make this graph directed (if it wasn't) and eliminate the shortest path we've found earlier.
4) Allocate negative weights for the deleted edges.
3) Find the shortest path in a new graph, return the previous shortest path to the graph and eliminate their intersections. Those steps have to be repeated as long as there are available paths.
5) Eliminate all unused edges.

This may sound a little confusing without a visual representation. Please, follow [this link](http://www.macfreek.nl/memory/Disjoint_Path_Finding) for a more dettailed explanation 
Once the graph is updated, you can finally find your solution paths and lead your ants to their homes safe and sound :)

#### Bonus:
As for the bonus part, it was proposed to create a visualizer.

#### Usage:

./lem-in < [map]

Without visualizer:
```shell
make && ./lem_in < maps/felixmap.map 
```

With visualizer:
```shell
make && make visual && ./lem_in < maps/felixmap.map | ./visual/visual
```

#### Example with visualizer

<img src="https://i.imgur.com/cOZKMVX.gif" width="900" title="Example">

#### Afterword:

It was incredibly challenging and interesting to do this project. In comparison with previous projects, me and my colleague this time did our best not just to make the programm work ignoring the efficiency cost, but rather make it work as fast as possible. Many things were changed throughout the process, including the parsing process, algorithm implementation, and the way we stored and accessed the data.

#### Credits:

Many thanks to [Eviber](https://github.com/Eviber) for sharing his lem-in visualization in Youtube, which had greatly assisted me in understanding of this project, and for a pack of useful and interesting maps. And, of course, my homie and partner in this project [zloirucar](https://github.com/zloirucar/).
