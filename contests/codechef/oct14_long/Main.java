// Program question at: http://www.codechef.com/OCT14/problems/CHEFSQUA

import java.io.*;
import java.math.*;
import java.util.*;

class Point
{
	public int x,y;
	Point(int x, int y)
	{
		this.x = x; this.y = y;
	}
	Point(double x, double y)
	{
		this.x = (int)x; this.y = (int)y;
	}
	Point() {}
	public double slope(Point p)
	{
		if(p.x - x == 0) return Double.NaN;
		return ((double)p.y - y) / (p.x - x);
	}
	public void swap(Point p)
	{
		int tmp = p.x; p.x = x; x = tmp;
		tmp = p.y; p.y = y; y = tmp;
	}
	public Point(Point p)
	{
		x = p.x; y = p.y;
	}
	
	public String toString()
	{
		return x + " " + y;
	}
	public boolean equals(Object o)
	{
		if(!(o instanceof Point)) return false;
		Point p = (Point)o;
		return p.x == x && p.y == y;
	}
	public int hashCode()
	{
		return (Integer.toString(x) + Integer.toString(y)).hashCode();
	}
}

public class Main
{	
	public static void main(String args[]) throws Exception
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(reader.readLine());
		HashSet<Point> set = new HashSet<Point>();
		Point pts[] = new Point[n];
		int ar[] = new int[n];
		for(int a=0;a<n;a++)
		{
			String input[] = reader.readLine().split(" ");
			pts[a] = new Point(Integer.parseInt(input[0]), Integer.parseInt(input[1]));			
			set.add(pts[a]);
		}
		if(n <= 1)
		{	
			System.out.println(4-n);
			System.exit(0);
		}
		int ans = 3;
		Point min[] = new Point[4];
		for(int a=0;a<n;a++)
		for(int b=a+1;b<n;b++)
		{
			Point p[][] = null;
			double m = pts[a].slope(pts[b]);
			
			if(m == 0 || Double.isNaN(m))
				p = f_parallel(pts[a], pts[b]);
			else
				p = f_other(new Point(pts[a]), new Point(pts[b]));
			for(int i=0;i<3;i++)
			{
				if(p[i] == null) continue;
				boolean has1 = set.contains(p[i][0]), has2 = set.contains(p[i][1]);
				if(has1 && has2)
				{
					ans = 0;
					min[0] = pts[a];
					min[1] = pts[b];
					min[2] = p[i][0];
					min[3] = p[i][1];
				}
				else if(has1 || has2)
				{
					if(ans > 1)
					{
						min[0] = pts[a];
						min[1] = pts[b];
						min[2] = p[i][0];
						min[3] = p[i][1];
					}
					ans = Math.min(ans,1);
				}
				else
				{
					if(ans > 2)
					{
						min[0] = pts[a];
						min[1] = pts[b];
						min[2] = p[i][0];
						min[3] = p[i][1];
					}
					ans = Math.min(ans,2);
				}
			}
			if(ans == 0) break;
		}
		/*for(int a=0;a<4;a++)
			System.out.printf("%s\n",min[a]);
		*/
		System.out.println(ans);
	}
	
	static boolean checkint(double d)
	{
		return d-Math.floor(d) < 0.000000001 && !Double.isNaN(d);
	}
	
	static Point[][] f_other(Point p1, Point p2)
	{
		//System.out.printf("for %s and %s:\n",p1,p2);
		Point pts[][] = new Point[3][2];
		double d = Math.hypot(p1.x - p2.x, p1.y - p2.y);
		double m1 = p1.slope(p2);
		if((m1 > 0 && p1.x > p2.x) || (m1 < 0 && p1.x < p2.x)) p1.swap(p2);
		double m2 = Double.NaN;
		double x1,y1,x2,y2;
		if(m1 == 1)
		{
			x1 = p2.x;
			y1 = p1.y;
		}
		else
		{
			m2 = Math.tan(Math.toRadians(Math.toDegrees(Math.atan(m1)) + 45));
			if(m1 > 0)
				x1 = (double)p1.x + d/Math.sqrt(2*(1+m2*m2));
			else
				x1 = (double)p1.x - d/Math.sqrt(2*(1+m2*m2));
			y1 = m2*(x1-p1.x) + p1.y;
		}
		if(!checkint(x1) || !checkint(y1))
			pts[0] = null;
		else
		{
			pts[0][0] = new Point(x1,y1);
			m2 = -1/m1;
			if(m1 > 0)
				x2 = x1 - d/Math.sqrt(1+(long)m2*m2);
			else
				x2 = x1 + d/Math.sqrt(1+(long)m2*m2);
			y2 = m2*(x2 - x1) + y1;
			if(!checkint(x2))
				pts[0] = null;
			else
				pts[0][1] = new Point(x2,y2);
		}
		// diagonal square complete
		m2 = -1/m1;
		x1 = p1.x - d/Math.sqrt(1 + m2*m2);
		if(!checkint(x1))
		{
			pts[1] = pts[2] = null;
			return pts;
		}
		else
		{
			y1 = m2*(x1 - p1.x) + p1.y;
			pts[1][0] = new Point(x1,y1);
			
			x2 = p2.x - d/Math.sqrt(1 + m2*m2);
			y2 = m2*(x2 - p2.x) + p2.y;
			if(!checkint(x2) || !checkint(y2))
				pts[1] = null;
			else
				pts[1][1] = new Point(x2,y2);

			// next square
			x1 = p1.x + d/Math.sqrt(1 + m2*m2);
			y1 = m2*(x1 - p1.x) + p1.y;
			if(!checkint(x1) || !checkint(y1))
			{
				pts[2] = null;
				return pts;
			}
			else
				pts[2][0] = new Point(x1,y1);
			
			x2 = p2.x + d/Math.sqrt(1 + m2*m2);
			y2 = m2*(x2 - p2.x) + p2.y;
			
			if(!checkint(x2) || !checkint(y2))
				pts[2] = null;
			else
			{
				try {
				pts[2][1] = new Point(x2,y2); }
				catch(Exception er) { System.out.printf("%s %s\n",p1,p2); er.printStackTrace(); System.exit(1); }
			}
		}
		/*
		for(int a=0;a<3;a++)
		{
			if(pts[a] == null) System.out.println("null null");
			else System.out.printf("%s %s\n",pts[a][0],pts[a][1]);
		}
		*/
		return pts;
	}
	
	static Point[][] f_parallel(Point p1, Point p2)	// slope 0 or INF
	{
		Point pts[][] = new Point[3][2];
		double m = p1.slope(p2), d=0;
		if(Double.isNaN(m))
		{
			d = Math.abs(p1.y - p2.y);
			pts[0][0] = new Point(p1.x + d, p1.y);
			pts[0][1] = new Point(p2.x + d, p2.y);
			
			pts[1][0] = new Point(p1.x - d, p1.y);
			pts[1][0] = new Point(p2.x - d, p2.y);
			
			if(d%2 != 0) pts[2] = null;
			else
			{
				pts[2][0] = new Point(p1.x - d/2, Math.max(p1.y,p2.y)-d/2);
				pts[2][1] = new Point(p1.x + d/2, Math.max(p1.y,p2.y)-d/2);
			}
		}
		else
		{
			d = Math.abs(p1.x - p2.x);
			pts[0][0] = new Point(p1.x, p1.y + d);
			pts[0][1] = new Point(p2.x, p2.y + d);
			
			pts[1][0] = new Point(p1.x, p1.y - d);
			pts[1][1] = new Point(p2.x, p2.y - d);
			
			if(d % 2 != 0) pts[2] = null;
			else
			{
				pts[2][0] = new Point(Math.min(p1.x,p2.x) + d/2, p1.y + d/2);
				pts[2][1] = new Point(Math.min(p1.x,p2.x) + d/2, p1.y - d/2);
			}
		}
		return pts;
	}
}
