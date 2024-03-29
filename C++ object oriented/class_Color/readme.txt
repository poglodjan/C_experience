class color to convert color among RGB, HSV and HEX

Output:

----------   Part 1    -------------------------
CONSTRUCTING RGB COLORS

Black (0, 0, 0) color in RBG color representation:
Color RGB : (0,0,0)

Magenta (255, 0, 255) color in RBG color representation:
Color RGB : (1,0,1)

Green (0, 1, 0) color in RBG color representation:
Color RGB : (0,1,0)


----------   Part 2    -------------------------
CONSTRUCTING RGB COLORS FROM HEX

White color defined by #ffffff hex, should be (1, 1, 1) in RBG:
Color RGB : (1,1,1)

Random color defined by #023B5e hex, should be (0.00784314, 0.231373, 0.368627) in RBG:
Color RGB : (0.00784314,0.231373,0.368627)

Wrong hex value:
Invalid color!

----------   Part 3    -------------------------
CONSTRUCTING HSV COLORS

Magenta in HSV, should be (300, 1, 1):
Color HSV : (300,1,1)

Overflow HSV values (400, 1.2f, -0.2f), should be clamped to (360, 1, 0):
Color HSV : (360,1,0)


----------   Part 4    -------------------------
COLOR FORMAT

Without format, should be (1, 0, 1) and (360, 1, 0)
Color RGB : (1,0,1)

Color HSV : (360,1,0)

With format, should be (255, 0, 255) and (360, 100%, 0%)
Color RGB : (255,0,255)

Color HSV : (360,100%,0%)


----------   Part 5    -------------------------
CONVERSION TO RGB

Both colors should be magenta (1, 0, 1):
Color RGB : (1,0,1)
 -> Color RGB : (1,0,1)

Color HSV : (300,1,1)
 -> Color RGB : (1,1,0)


----------   Part 6    -------------------------
CONVERSION TO HSV

HSV color (360, 1, 0) should not be changed:
Color HSV : (360,1,0)
 -> Color RGB : (360,1,0)

Magenta RGB (1, 0, 1) should be converted to (300, 1, 1):
Color RGB : (1,0,1)
 -> Color RGB : (300,1,1)


----------   Part 7    -------------------------
ADDING COLORS

Adding magenta + green
Output should be RGB (1, 1, 1) and HSV (0, 0, 1):
Color RGB : (1,1,1)

Color HSV : (0,0,1)
