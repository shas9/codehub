#define nsz 100010
#define tsz 6000010 //take 4n + qlogn

ll a[nsz];
ll NEXT_FREE;
ll version[nsz];
ll val[tsz], Left[tsz], Right[tsz];

void build(ll node, ll l, ll r)
{
    if(l == r) // leaf node
    {
        val[node] = 0;
        return;
    }
    Left[node] = NEXT_FREE++;
    Right[node] = NEXT_FREE++;
    ll mid = (l + r) >> 1;
    build(Left[node], l, mid);
    build(Right[node], mid+1, r);
    val[node] = val[Left[node]] + val[Right[node]];
}

ll update(ll node, ll l, ll r, ll idx, ll v)
{
    if(idx < l || r < idx)
        return node; // Out of range, use this node.
    ll nnode = NEXT_FREE++; //Creating a new node, as idx is in [l, r]
    if (l == r) // Leaf Node, create new node and return that.
    {
        val[nnode] = val[node]; //cloning current old leaf node's value to new leaf node
        val[nnode] += v; // adding or subtracting or replacing as needed
        return nnode;
    }
    ll mid = (l + r) >> 1;
// Left[nnode] is new node's Left child, it might end up being the old one too
// Left[node] is current old node's Left child.
// So we call to update idx in Left child of old node.
// And use it's return node as new node's Left child. Same for Right.
    Left[nnode] = update(Left[node], l, mid, idx, v);
    Right[nnode] = update(Right[node], mid+1, r, idx, v);
    val[nnode] = val[Left[nnode]] + val[Right[nnode]]; // Update value.
    return nnode; // Return the new node to parent.
}

ll query(ll lnode, ll rnode, ll pnode, ll l, ll r, ll k)
{
    if (l == r)
        return l;
    ll cnt = val[Left[rnode]] + val[Left[lnode]] - 2*val[Left[pnode]];
    if (k <= cnt)
        return query(Left[lnode], Left[rnode], Left[pnode], l, (l+r)>>1, k);
    else return query(Right[lnode], Right[rnode], Right[pnode], ((l+r)>>1)+1, r, k-cnt);
}
