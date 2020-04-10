#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}

// USE CASES FOR CALCULATOR'S WIDGET

// #1: 12 + 3 =
// 1. User runs widget;
// 2. At beginning, widget is clean (means, line edit has 0 only, edit flag is 'APPEND');
// 3. User pressed '1' on the widget;
// 4. Widget appends '1' to its content;
// 5. User pressed '2' on the widget;
// 6. Widget appends '2' to its content;
// 7. User pressed '+' on the widget;
// 8. Set edit flag to 'REPLACE';
// 9. User pressed '3' on the widget;
// 10. Widget replaced its content by '3';
// 11. Set edit flag to 'APPEND';
// 12. User pressed '=' on the widget;
// 13. Set edit flag to 'REPLACE';

// #2: 12 + - 3 =
// 9.1. User pressed '-' on the widget;
// 10.1. Set edit flag to 'REPLACE';
// 11.1. User pressed '3' on the widget;
// 12.1. Widget replaced its content by '3';
// 13.1. Set edit flag to 'APPEND';
// 14.1. User pressed '=' on the widget;
// 15.1. Set edit flag to 'REPLACE';

// #3: 12 + 3 - 7 =
// 12.1. User pressed '-' on the widget;
// 13.1. Set edit flag to 'REPLACE';
// 14.1. Widget replaced its content by '7';
// 15.1. Set edit flag to 'APPEND';
// 16.1. User pressed '=' on the widget;
// 17.1. Set edit flag to 'REPLACE';

// #4: - 7 + 3 =
// 3.1. User pressed '-' on the widget;
// 4.1. Set edit flag to 'REPLACE';
// 5.1. User pressed '7' on the widget;
// 6.1. Widget replaced its content by '7';
// 7.1. Set edit flag to 'APPEND';
// 8.1. User pressed '+' on the widget;
// 9.1. Set edit flag to 'REPLACE';
// 10.1. User pressed '3' on the widget;
// 11.1. Widget replaced its content by '3';
// 12.1. Set edit flag to 'APPEND';
// 13.1. User pressed '=' on the widget;
// 14.1. Set edit flag to 'REPLACE';

// #5: * 7 + 3 =
// 3.1.1. User pressed '*' on the widget;
// 4.1.1. Set edit flag to 'REPLACE';
// 5.1.1. User pressed '7' on the widget;
// 6.1.1. Widget replaced its content by '7';
// 7.1.1. Set edit flag to 'APPEND';
// 8.1.1. User pressed '+' on the widget;
// 9.1.1. Set edit flag to 'REPLACE';
// 10.1.1. User pressed '3' on the widget;
// 11.1.1. Widget replaced its content by '3';
// 12.1.1. Set edit flag to 'APPEND';
// 13.1.1. User pressed '=' on the widget;
// 14.1.1. Set edit flag to 'REPLACE';



// USE CASES FOR CALCULATOR

// #1: 12 + 3 = ... (15)
// 1. At begining, redirect input from the widget to the calculator's left operand;
// 2. User pressed '1' on the widget;
// 3. Write content from the widget to the calculator's operand (left);
// 4. User pressed '2' on the widget;
// 5. Write content from the widget to the calculator's operand (left);
// 6. User pressed '+' on the widget;
// 7. Set the calculator's current operator to '+';
//     7.1. If expression can evaluate;
//     8.1. Evaluate it;
//     9.1. Store result in left operand;
//     10.1. Set the calculator's current operator to '+';
// 8. Redirect input from the widget to the calculator's right operand;
// 9. User pressed '3' on the widget;
// 10. Write content from the widget to the calculator's operand (right);
// 11. User pressed '=' on the widget;
// 12. If expression can evaluate;
// 13. Evaluate it;
// 14. Store result in left operand;
// 15. Set the calculator's current operator to empty state;

// #2: 12 + - 3 = ... (9)
// 6.1. User pressed '-' on the widget;
// 7.1. Set the calculator's current operator to '-';
//     7.1.1. If expression can evaluate;
//     8.1.1. Evaluate it;
//     9.1.1. Store result in left operand;
//     10.1.1. Set the calculator's current operator to '-';
// 8.1. Redirect input from the widget to the calculator's right operand;
// 9.1. User pressed '3' on the widget;
// 10.1. Write content from the widget to the calculator's operand (right);
// 11.1. User pressed '=' on the widget;
// 12.1. If expression can evaluate;
// 13.1. Evaluate it;
// 14.1. Store result in left operand;
// 15.1. Set the calculator's current operator to empty state;

// #3: 12 + 3 - 7 = ... (8)
// 11.1. User pressed '-' on the widget;
// 12.1. Set the calculator's current operator to '-';
//     12.1.1. If expression can evaluate;
//     13.1.1. Evaluate it;
//     14.1.1. Store result in left operand;
//     15.1.1. Set the calculator's current operator to '-';
// 13.1. Redirect input from the widget to the calculator's right operand;
// 14.1. User pressed '7' on the widget;
// 15.1. Write content from the widget to the calculator's operand (right);
// 16.1. User pressed '=' on the widget;
// 17.1. If expression can evaluate;
// 18.1. Evaluate it;
// 19.1. Store result in left operand;
// 20.1. Set the calculator's current operator to empty state;

// #4: - 7 + 3 = ... (-4)
// 2.1. User pressed '-' on the widget;
// 3.1. Set the calculator's current operator to '-';
//     3.1.1. If expression can evaluate;
//     4.1.1. Evaluate it;
//     5.1.1. Store result in left operand;
//     6.1.1. Set the calculator's current operator to '-';
// 4.1. Redirect input from the widget to the calculator's right operand;
// 5.1. User pressed '7' on the widget;
// 6.1. Write content from the widget to the calculator's operand (right);
// 7.1. User pressed '+' on the widget;
// 8.1. Set the calculator's current operator to '+';
//     8.1.1. If expression can evaluate;
//     9.1.1. Evaluate it;
//     10.1.1. Store result in left operand;
//     11.1.1. Set the calculator's current operator to '+';
// 9.1. Redirect input from the widget to the calculator's right operand;
// 10.1. User pressed '3' on the widget;
// 11.1. Write content from the widget to the calculator's operand (right);
// 12.1. User pressed '=' on the widget;
// 13.1. If expression can evaluate;
// 14.1. Evaluate it;
// 15.1. Store result in left operand;
// 16.1. Set the calculator's current operator to empty state;

// #5: * 7 + 3 = ... (3)
// 2.1.1. User pressed '*' on the widget;
// 3.1.1. Set the calculator's current operator to '*';
//     3.1.1.1. If expression can evaluate;
//     4.1.1.1. Evaluate it;
//     5.1.1.1. Store result in left operand;
//     6.1.1.1. Set the calculator's current operator to '*';
// 4.1.1. Redirect input from the widget to the calculator's right operand;
// 5.1.1. User pressed '7' on the widget;
// 6.1.1. Write content from the widget to the calculator's operand (right);
// 7.1.1. User pressed '+' on the widget;
// 8.1.1. Set the calculator's current operator to '+';
//     8.1.1.1. If expression can evaluate;
//     9.1.1.1. Evaluate it;
//     10.1.1.1. Store result in left operand;
//     11.1.1.1. Set the calculator's current operator to '+';
// 9.1.1. Redirect input from the widget to the calculator's right operand;
// 10.1.1. User pressed '3' on the widget;
// 11.1.1. Write content from the widget to the calculator's operand (right);
// 12.1.1. User pressed '=' on the widget;
// 13.1.1. If expression can evaluate;
// 14.1.1. Evaluate it;
// 15.1.1. Store result in left operand;
// 16.1.1. Set the calculator's current operator to empty state;
