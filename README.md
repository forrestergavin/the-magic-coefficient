Summary: Some polynomials with their roots all given by a magic square's row, column or diagonal share the same third term's coefficient, this is the called the magic coefficient. Mind you, both the polynomial and magic square must be of the same order and the magic square's range of numbers must match the polynomial's second term's coefficient. 

```
Magic Square order 3 X 3
2, 7, 6,
9, 5, 1
4, 3, 8

Reasoning for the concept:
(x + 2)(x + 7)(x + 6) Top
(x + 4)(x + 3)(x + 8) Bottom
=>
(x + 2)(x + 7)(x + 6) Top
(x + 8)(x + 3)(x + 4) Bottom
=
(x + 2)(x + 7)(x + 6) Top
(    +)(    +)(    +) Plus
(x + 8)(x + 3)(x + 4) Bottom
=
(x + 10)(x + 10)(x + 10) Sum

The concept itself:
k3=ca+cb+ab

a = 2, b = 7, c = 6
k3=(6)(2)+(6)(7)+(2)(7)=68

a = 4, b = 3, c = 8
k3=(8)(4)+(8)(3)+(4)(3)=68
```

ORGANISATION (Rows, Columns, Diagonals):
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

FORMULAS:
Apply to each row, column, or diagonal to calculate the second shared term's coefficient or cross sum:
```
m3=c+b+a
m4=d+c+b+a
m5=e+d+c+b+a
...
mn=z+...+b+a
```

Apply to each row, column, or diagonal to calculate the third shared term's coefficient kx^(n-2) or just k, this is formula for the magic coefficients in the corresponding magic square:
```
k3=ca+cb+ab
k4=dc+db+cb+da+ca+ab
k5=ed+ec+dc+eb+db+cb+ea+da+ca+ab
...
kn=zy+zx+yx+...+ab
```

IMPORTANT: The second term's coefficient must be the same for all polynomials in the corresponding magic square, so that they belong to that magic square's range of numbers and not another's, in order to get the correct magic coefficient. <br/>
NOTE: There is no max for magic squares, z is just the last letter in the alphabet.

PARKER SQUARE:
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
```