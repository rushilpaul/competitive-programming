import java.util.*;

class SUBINC {
	public static void main(String args[]) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0) {
			int n = sc.nextInt();
			int ar[] = new int[n];
			for(int i = 0; i < n; i++)
				ar[i] = sc.nextInt();
			int ans[] = new int[n];
			ans[0] = 1;
			long cnt = 1;

			for(int i = 1; i < n; i++) {
				ans[i] = 1;
				if(ar[i] >= ar[i-1])
					ans[i] += ans[i-1];
				cnt += ans[i];
			}
			System.out.println(cnt);
		}
	}
}
