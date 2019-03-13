## wayout_solver

An algorithm for automatically solving Wayout and Wayout 2 puzzles (games based on the Lights Out mechanic). 
I did not aim to implement a user-friendly interface, the only goal was the algorithm.

### Required

* C++17
* Boost Test Library

### Installing

```
> cmake CMakeLists.txt
> make
> ctest                      # testing
> ./bin/WayOut1Solver FILE   # solve a WayOut level from FILE
> ./bin/WayOut2Solver FILE   # solve a WayOut2 level from FILE
> ./bin/WayOut1Solver        # enter the level you want to solve
```

<img align="center" width="500" src="../assets/images/screencapture.gif">

Also, you can make the special version of the program, which log algorithm decisions in the console output:

```
> make WayOut1Logging
> make WayOut2Logging
> ./bin/WayOut1Loggin ...
```

---

### Level format

You can see the format for representing WayOut levels, just run the program without arguments:

<img align="center" width="500" src="../assets/images/coding_rules.png">

The positions of the coordinate axes for both games are shown below.

<img align="left" width="400" height="200" src="../assets/images/wo1_s4_20.png">

Solver coding:

```
.X.X..
.yyyy.
XYYYY.
.YYyy.
XyyyYX
.X.X.X
```
 
<img align="left" width="400" height="240" src="../assets/images/wo2_s2_02.png">

Solver coding:

```
..o.___
.O__.__
._.XO._
._._._O
_o.Oo_.
__.__.o
___..O.
```
