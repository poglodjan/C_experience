#include <iostream>
using namespace std;
#include "color.h"
#define STAGE1 1
#define STAGE2 1
#define STAGE3 1
#define STAGE4 1
#define STAGE5 1
#define STAGE6 1
#define STAGE7 1

int main()
{
    cout << "----------   Part 1    -------------------------" << endl;
#if STAGE1
    cout << "CONSTRUCTING RGB COLORS" << endl << endl;

    cout << "Black (0, 0, 0) color in RBG color representation:" << endl;
    Color black;
    cout << black << endl;

    cout << "Magenta (255, 0, 255) color in RBG color representation:" << endl;
    Color magenta(255, 0, 255);
    cout << magenta << endl;

    cout << "Green (0, 1, 0) color in RBG color representation:" << endl;
    Color green(0.0f, 1.0f, 0.0f);
    cout << green << endl;
#endif
    cout << endl << "----------   Part 2    -------------------------" << endl;
#if STAGE2
    cout << "CONSTRUCTING RGB COLORS FROM HEX" << endl << endl;

    cout << "White color defined by #ffffff hex, should be (1, 1, 1) in RBG:" << endl;
    Color whiteHexColor("ffffff");
    cout << whiteHexColor << endl;

    cout << "Random color defined by #023B5e hex, should be (0.00784314, 0.231373, 0.368627) in RBG:" << endl;
    Color randomHexColor("023B5e");
    cout << randomHexColor << endl;

    cout << "Wrong hex value:" << endl;
    Color wrongHexColor("A45aj0");
    cout << wrongHexColor << endl;
#endif
    cout << endl << "----------   Part 3    -------------------------" << endl;
#if STAGE3
    cout << "CONSTRUCTING HSV COLORS" << endl << endl;

    cout << "Magenta in HSV, should be (300, 1, 1):" << endl;
    Color magentaHsvColor(300, 1, 1, false);
    cout << magentaHsvColor << endl;

    cout << "Overflow HSV values (400, 1.2f, -0.2f), should be clamped to (360, 1, 0):" << endl;
    Color anotherHsvColor(400, 1.2f, -0.2f, false);
    cout << anotherHsvColor << endl;
#endif
    cout << endl << "----------   Part 4    -------------------------" << endl;
#if STAGE4
    cout << "COLOR FORMAT" << endl << endl;

    cout << "Without format, should be (1, 0, 1) and (360, 1, 0)" << endl;
    cout << magenta << endl;
    cout << anotherHsvColor << endl;

    cout << "With format, should be (255, 0, 255) and (360, 100%, 0%)" << endl;
    magenta.SetFormat() = true;
    anotherHsvColor.SetFormat() = true;

    cout << magenta << endl;
    cout << anotherHsvColor << endl;

    //Clear format
    magenta.SetFormat() = false;
    anotherHsvColor.SetFormat() = false;
#endif
    cout << endl << "----------   Part 5    -------------------------" << endl;
#if STAGE5
    cout << "CONVERSION TO RGB" << endl << endl;

    cout << "Both colors should be magenta (1, 0, 1):" << endl;
    Color rgbConvertedToRgb = magenta.toRGB();
    cout << magenta << " -> " << rgbConvertedToRgb << endl;

    Color hsvConvertedToRgb = magentaHsvColor.toRGB();
    cout << magentaHsvColor << " -> " << hsvConvertedToRgb << endl;
#endif
    cout << endl << "----------   Part 6    -------------------------" << endl;
#if STAGE6
    cout << "CONVERSION TO HSV" << endl << endl;

    cout << "HSV color (360, 1, 0) should not be changed: " << endl;
    Color hsvConvertedToHsv = anotherHsvColor.toHSV();
    cout << anotherHsvColor << " -> " << hsvConvertedToHsv << endl;

    cout << "Magenta RGB (1, 0, 1) should be converted to (300, 1, 1): " << endl;
    Color rgbConvertedToHsv = magenta.toHSV();
    cout << magenta << " -> " << rgbConvertedToHsv << endl;

#endif
    cout << endl << "----------   Part 7    -------------------------" << endl;
#if STAGE7
    cout << "ADDING COLORS" << endl << endl;

    cout << "Adding magenta + green" << endl;
    cout << "Output should be RGB (1, 1, 1) and HSV (0, 0, 1):" << endl;
    cout << magenta.addColor(green) << endl;
    cout << magentaHsvColor.addColor(green) << endl;
#endif
}
