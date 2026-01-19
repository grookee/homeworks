#include <graphics.h>
#include <iostream>

using namespace std;

const int WIDTH = 1000;
const int HEIGHT = 1000;
const int size = 729;

void negyzet(int x, int y, int size, int depth)
{
    if (size < 3 || depth <= 0)
        return;

    int newSize = size / 3;

    int color = (depth % 16) + 1;
    setfillstyle(SOLID_FILL, color);
    bar(x + newSize, y + newSize, x + 2 * newSize - 1, y + 2 * newSize - 1);

    for (int dx = 0; dx < 3; dx++)
    {
        for (int dy = 0; dy < 3; dy++)
        {
            if (dx == 1 && dy == 1)
                continue;
            negyzet(x + dx * newSize, y + dy * newSize, newSize, depth - 1);
        }
    }
}

int main()
{
    int depth;
    cin >> depth;

    initwindow(WIDTH, HEIGHT, "szonyeg!!", 0, 0, false);

    setfillstyle(SOLID_FILL, WHITE);
    bar(0, 0, size, size);

    negyzet(0, 0, size, depth);

    getch();

    closegraph();

    return 0;
}
