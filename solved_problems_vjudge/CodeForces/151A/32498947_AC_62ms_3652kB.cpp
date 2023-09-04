#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, l, c, d, p, nl, np; // friends, bottles, ml/bottle, limes, slices/limes, g of salt,
    // needed: ml of drink (nl), 1 slice, g of salt (np) // for each toast
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int dr = k*l, lm = c*d; // total drink, total slices, toast count

    //cuantos toasts se pueden hacer por cada condicion?
    int td = dr/nl, tsl = lm, tsa = p/np; // drink, slice, salt
    //cout << td << " " << tsl << " " << tsa << endl;
    cout << min(td, min(tsl, tsa))/n << endl;
}