#include <stdio.h>
#include <math.h>
int main()
{
    int testcase, i;
    scanf("%d", &testcase);

    int ax, ay, bx, by, cx, cy, dx, dy;

    int a, b, c, d;

    int res;

    for(i = 1; i <= testcase; i++)
    {
        scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy);

        dx = ax + cx - bx;
        dy = ay + cy - by;

        /*a = (ax - bx);
        b = (ay - by);
        c = (bx - cx);
        d = (by - cy);*/

        res = abs((cy-by)*(ax-bx)-(ay-by)*(cx-bx));

        printf("Case %d: %d %d %d\n", i, dx, dy, res);
    }

    return 0;
}
