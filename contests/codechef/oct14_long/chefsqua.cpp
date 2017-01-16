#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
#include <limits>
#define INF numeric_limits<double>::infinity()
using namespace std;

#define dbg 0

class Point
{
	public:
		int x,y;
	void display()
	{
		printf("%d,%d\n",x,y);
	}
	Point() {}
	Point(int x, int y) : x(x),y(y) {}
	Point(const Point &p)
	{
		x = p.x;
		y = p.y;
	}
	friend bool operator<(const Point &p1, const Point &p2);
	bool operator==(const Point &p) { return x == p.x && y == p.y; }
	Point& operator=(const Point &p)
	{
		if((void*)this == (void*)&p) return *this;
		x = p.x; y = p.y;
		return *this;
	}
	
	inline double slope(Point p)	// assuming slope is not INF
	{
		return ((double)p.y - y) / (p.x - x);
	}
	inline void swap(Point &p)
	{
		int tmp = p.x; p.x = x; x = tmp;
		tmp = p.y; p.y = y; y = tmp;
	}
};

inline bool operator<(const Point &p1, const Point &p2)
{
	if(p1.x < p2.x) return true;
	else if(p1.x == p2.x && p1.y < p2.y) return true;
	else return false;
}

inline bool checkint(double d)
{
	return d-abs(d) < 0.000000001;
}

inline void f_parallel(Point p1, Point p2, Point pts[3][2], bool sq[3])
{
	bool slopeINF = 0;
	double m,d;
	if(p1.x - p2.x == 0) slopeINF = 1;
	else m = p1.slope(p2);
	if(slopeINF)
	{
		d = abs(p1.y - p2.y);
		pts[0][0] = Point(p1.x + d, p1.y);
		pts[0][1] = Point(p2.x + d, p2.y);
	
		pts[1][0] = Point(p1.x - d, p1.y);
		pts[1][0] = Point(p2.x - d, p2.y);
		
		if((int)d % 2 != 0) sq[2] = false;
		else
		{
			pts[2][0] = Point(p1.x - d/2, max(p1.y,p2.y)-d/2);
			pts[2][1] = Point(p1.x + d/2, max(p1.y,p2.y)-d/2);
		}
	}
	else
	{
		d = abs(p1.x - p2.x);
		pts[0][0] = Point(p1.x, p1.y + d);
		pts[0][1] = Point(p2.x, p2.y + d);
		
		pts[1][0] = Point(p1.x, p1.y - d);
		pts[1][1] = Point(p2.x, p2.y - d);
		
		if((int)d % 2 != 0) sq[2] = false;
		else
		{
			pts[2][0] = Point(min(p1.x,p2.x) + d/2, p1.y + d/2);
			pts[2][1] = Point(min(p1.x,p2.x) + d/2, p1.y - d/2);
		}
	}
}

inline void f_other(Point p1, Point p2, Point pts[3][2], bool sq[3])
{
	//System.out.printf("for %s and %s:\n",p1,p2);
	double d,m1,m2;
	d = sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y) );
	m1 = p1.slope(p2);
	if((m1 > 0 && p1.x > p2.x) || (m1 < 0 && p1.x < p2.x)) p1.swap(p2);
	m2 = INF;
	double x1,y1,x2,y2;
	if(m1 == 1)
	{
		x1 = p2.x;
		y1 = p1.y;
	}
	else
	{
		m2 = tan(atan(m1)+M_PI/4.0);
		if(m1 > 0)
			x1 = (double)p1.x + d/sqrt(2*(1+m2*m2));
		else
			x1 = (double)p1.x - d/sqrt(2*(1+m2*m2));
		y1 = m2*(x1-p1.x) + p1.y;
	}
	if(!checkint(x1) || !checkint(y1))
		sq[0] = false;
	else
	{
		pts[0][0] = Point(x1,y1);
		m2 = -1/m1;
		if(m1 > 0)
			x2 = x1 - d/sqrt(1+(long)m2*m2);
		else
			x2 = x1 + d/sqrt(1+(long)m2*m2);
		y2 = m2*(x2 - x1) + y1;
		if(!checkint(x2))
			sq[0] = false;
		else
			pts[0][1] = Point(x2,y2);
	}
	// diagonal square complete
	m2 = -1/m1;
	x1 = p1.x - d/sqrt(1 + m2*m2);
	if(!checkint(x1))
	{
		sq[1] = sq[2] = false;
		return;
	}
	else
	{
		y1 = m2*(x1 - p1.x) + p1.y;
		pts[1][0] = Point(x1,y1);
		
		x2 = p2.x - d/sqrt(1 + m2*m2);
		y2 = m2*(x2 - p2.x) + p2.y;
		if(!checkint(x2) || !checkint(y2))
			sq[1] = false;
		else
			pts[1][1] = Point(x2,y2);
		// next square
		x1 = p1.x + d/sqrt(1 + m2*m2);
		y1 = m2*(x1 - p1.x) + p1.y;
		if(!checkint(x1) || !checkint(y1))
		{
			sq[2] = false;
			return;
		}
		else
			pts[2][0] = Point(x1,y1);
		
		x2 = p2.x + d/sqrt(1 + m2*m2);
		y2 = m2*(x2 - p2.x) + p2.y;
		
		if(!checkint(x2) || !checkint(y2))
			sq[2] = false;
		else
		{
			pts[2][1] = Point(x2,y2);
		}
	}
	/*
	for(int a=0;a<3;a++)
	{
		if(!sq[a]) printf("null null");
		else { pts[a][0].display(); pts[a][1].display(); }
	}
	*/
}

int main()
{
	int n; scanf("%d",&n);
	set<Point> set_p;
	Point pts[n];
	for(int i=0;i<n;i++)
	{
		int a,b; scanf("%d %d",&a,&b);
		Point p(a,b);
		set_p.insert(p);
		pts[i] = p;
	}
	if(n <= 1)
	{
		printf("%d\n",4-n);
		return 0;
	}
	int ans = 3;
	Point p[3][2];
	bool sq[3];
	for(int a=0;a<n;a++)
	for(int b=a+1;b<n;b++)
	{
		sq[0] = sq[1] = sq[2] = true;
		bool parallel = 0;
		if(pts[a].x - pts[b].x == 0 || pts[a].y - pts[b].y == 0) parallel = 1;
		if(parallel)
			f_parallel(pts[a],pts[b],p,sq);
		else{}
			//f_other(pts[a],pts[b],p,sq);
		
		for(int i=0;i<3;i++)
		{
			if(!sq[i]) continue;
			bool has1 = false, has2 = false;
			has1 = set_p.find(p[i][0]) != set_p.end();
			has2 = set_p.find(p[i][1]) != set_p.end();
			if(has1 && has2) ans = 0;
			else if(has1 || has2) ans = min(ans,1);
			else ans = min(ans,2);
		}
		if(!ans) break;
	}
	printf("%d\n",ans);
	return 0;
}
