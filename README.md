To summarise: Some polynomials with their roots all given by a magic square's row, column or diagonal share the same third term's coefficient, this is the called the magic coefficient. Mind you, both the polynomial and magic square must be of the same order. 

ORGANISATION (Rows, Columns, Diagonals)
```
Rows
a,b,c,...z
a,b,c,...z
a,b,c,...z

Columns
a,a,a
b,b,b
c,c,c
...,...,...
z,z,z

Diagonals
        z
      .
a,x,e,
x,b,x
d,x,c,
       .
         z
```

FORMULAS
Apply to each row, column, or diagonal to calculate the second shared term's coefficient or cross sum:
```
m3=c+b+a
m4=d+c+b+a
m5=e+d+c+b+a
...
mn=z+...+b+a
```

apply to each row, column, or diagonal to calculate the third shared term's coefficient kx^(n-2) or just k:
```
k3=ca+cb+ab
k4=dc+db+cb+da+ca+ab
k5=ed+ec+dc+eb+db+cb+ea+da+ca+ab
...
kn=zy+zx+yx+...+ab
```

NOTE: There is no max for magic squares, z is just the last letter in the alphabet.

PARKER SQUARE
```
|_______________|_______________|_______________| ^ 2
| /----) |----| |       /|      | |    | |----| |
|    /   |----| |      / |      | |----|    -/- |
|  /---|      | |        |      |      |    /   |
|_______________|_______________|_______________|
| |    |    /|  | /----) |----| |       /|      |
| |----|   / |  |    -(     -/- |      / |      |
|      |     |  | \----)    /   |        |      |
|_______________|_______________|_______________|
| /----) /----) | |    |    /|  | /----) |----| |
|    /      -(  | |----|   / |  |    /   |----| |
|  /---| \----) |      |     |  |  /---|      | |
|_______________|_______________|_______________|
+=================Parker=Square=================+
```