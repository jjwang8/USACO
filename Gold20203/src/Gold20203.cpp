#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;
struct cord{
	int x;
	int y;
};
int n;
cord a[50];
int pas[40] = {};
int us[40] = {};
bool onSegment(cord p, cord q, cord r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}
int orientation(cord p, cord q, cord r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}
bool doIntersect(cord p1, cord q1, cord p2, cord q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}
bool ins(int f1, int f2, int f3, int l){
	int lf = max(a[f1].x, max(a[f2].x, a[f3].x));
	int rf = min(a[f1].x, max(a[f2].x, a[f3].x));
	if (a[l].x >= lf || a[l].x <= rf){
		return 0;
	}
	int tf = max(a[f1].y, max(a[f2].y, a[f3].y));
	int bf = min(a[f1].y, max(a[f2].y, a[f3].y));
	if (a[l].y >= tf || a[l].y <= bf){
		return 0;
	}
	int tot = 0;
	cord temp;
	temp.y = a[l].y;
	temp.x = 1000000;
	tot += doIntersect(a[l],temp, a[f1], a[f2]);
	tot += doIntersect(a[l],temp, a[f2], a[f3]);
	tot += doIntersect(a[l],temp, a[f3], a[f1]);
	if (tot == 0 || tot > 1){
		return 0;
	}
	return 1;
}
int one(int f1, int f2, int f3, int l){
	int tot = 0;
	int ma = 0;
	bool t;
	cord temp;
	//cout << l << endl;
	temp = a[f1];
	tot += doIntersect(a[l],temp, a[f2], a[f3]);
	//cout << tot << endl;
	if (pow((a[l].y-temp.y),2) + pow((a[l].x-temp.x),2) > ma){
		ma = pow((a[l].y-temp.y),2) + pow((a[l].x-temp.x),2);
		t = 1;
	}

	temp = a[f2];
	tot += doIntersect(a[l],temp, a[f3], a[f1]);
	if (pow((a[l].y-temp.y),2) + pow((a[l].x-temp.x),2) > ma){
		ma = pow((a[l].y-temp.y),2) + pow((a[l].x-temp.x),2);
		t = 2;
	}
	//cout << tot << endl;
	temp = a[f3];
	tot += doIntersect(a[l],temp, a[f1], a[f2]);
	if (pow((a[l].y-temp.y),2) + pow((a[l].x-temp.x),2) > ma){
		ma = pow((a[l].y-temp.y),2) + pow((a[l].x-temp.x),2);
		t = 2;
	}
	//cout << tot << endl;
	if (tot == 0){
		return t;
	}
	return 0;
}
int f(int f1, int f2, int f3, int si){
	if (si == n){
		return 1;
	}
	int ans = 0;
	for (int i = 0; i < n;i++){
		if (pas[i] == 1){
			continue;
		}
		pas[i] = 1;
		bool t = one(f1,f2,f3,i);
		//cout << t << " " << ins(f1,f2,f3, i) << endl;
		if (ins(f1,f2,f3, i)){
			ans += f(f1, f2, f3, si+1);
		} else if (t){
			if (t == 1){
				ans += f(i, f2, f3, si+1);
			} else if (t == 2){
				ans += f(f1,i,f3, si+1);
			} else {
				ans += f(f1,f2,i, si+1);
			}
		}
		pas[i] = 0;
	}

	return ans;
}
int main() {
	ifstream fin("lost.in");
	ofstream fout("lost.out");
	cin >> n;
	for (int i = 0; i < n;i++){
		cord temp;
		cin >> temp.x;
		cin >> temp.y;
		a[i] = temp;
	}
	int ans = 0;
	for (int i = 0; i < n;i++){
		pas[i] = 1;
		for (int l = i+1; l < n;l++){
			pas[l] = 1;
			for (int j = l+1; j < n;j++){
				//cout << i << l << j << endl;
				pas[j] = 1;
				ans += 6*f(i, l, j, 3);
				pas[j] = 0;
			}
			pas[l] = 0;
		}
		pas[i] = 0;
	}
	cout << ans;
	return 0;
}
