// Convex hull
#include<iostream>
#include<algorithm>
#include<vector>
#define dis(x1, x2, y1, y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
using namespace std;

struct S{
	S(int _x, int _y){
		x = _x;
		y = _y;
	}
	int x;
	int y;
};
vector<S> v;
vector<S> hull;

int cross(S& target, S& a, S& b){
	return (a.x-target.x )*(b.y-target.y)-(a.y-target.y)*(b.x-target.x);
}
bool cmp(S& a, S&b){
	int i = cross(v[0], a, b);
	if(i == 0)
		return dis(v[0].x, a.x, v[0].y, a.y) < dis(v[0].x, b.x, v[0].y, b.y);
	else return i > 0;
}
void Convex_hull(){
	int SIZE = v.size();
	for(int i=0 , n = -1; i<SIZE; ++i){
		hull.push_back(v[i]);
		++n;
		while(n>=2 && cross(hull[n-2], hull[n-1], hull[n])<=0){
			hull.erase(hull.begin() + n-1);
			--n;
		}
	}
}
int main(){
	int n, m, input, min = 0;
	cin >> n >> m;

	for(int j=m; j>0; --j)
	for(int i=1; i<=n; ++i){
		scanf("%1d", &input);
		if(input == 1){
			S s(i, j);
			v.push_back(s);
			if(v.size()>1 && (j < v[min].y || (j==v[min].y && i<v[min].x)))
				min = v.size()-1;
		}
	}

	swap(v[0], v[min]);
	sort(v.begin()+1,v.end(),cmp);
	Convex_hull();

	int SIZE = hull.size(), max_dis = 0, cur_max = 0;
	for(int i=0; i < SIZE;++i){
		cur_max = 0;
		for(int j=i+1; j < SIZE; ++j){
			int d = dis(hull[i].x, hull[j].x, hull[i].y, hull[j].y);
			if( d < cur_max) break;
			cur_max = d;
		}
		if(cur_max > max_dis) max_dis = cur_max;
	}
	cout<<pow(max_dis, 0.5)<<endl;
	return 0;
}

/*
input:
	5 5
	10100
	00100
	01101
	00010
	10100
output:
	4.47214
*/
