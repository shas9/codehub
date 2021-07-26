#include <stdio.h>

int main()
{
    char A = 1, B = 2, C = 3, D = 4, E = 5, F = 6, G = 7, H = 8, I = 9, J = 10, K = 11, L = 12, M = 13, N = 14, O = 15, P = 16, Q = 17, R = 18, S = 19, T = 20, U = 21, V = 22, W = 23, X = 24, Y = 25, Z = 26;

    char a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    a = A;
    b = B;
    c = C;
    d = D;
    e = E;
    f = F;
    g = G;
    h = H;
    i = I;
    j = J;
    k = K;
    l = L;
    m = M;
    n = N;
    o = O;
    p = P;
    q = Q;
    r = R;
    s = S;
    t = T;
    u = U;
    v = V;
    w = W;
    x = X;
    y = Y;
    z = Z;

    char arr[200];

    read:

    scanf("%s", arr);

    int ln;

    for(ln = 0; arr[ln] != 0; ln++);

int sum;
    sum = arr[0] + arr[1] + arr[2];

    printf("%d\n", sum);

    goto read;

    return 0;
}
