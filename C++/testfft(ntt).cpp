#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const int mod=7340033; // mod = 7 * (1<<20)
const int N=1<<12;

inline int regular(long long x) {
	return x%mod;
}
inline int regular(int x) {
	if (x>=mod) return x-mod;
	if (x<0) return x+mod;
	return x;
}
inline int pow(int x,int n) {
	int ans=1;
	while (n) {
		if (n&1) ans=regular((long long)ans*x);
		x=regular((long long)x*x);
		n>>=1;
	}
	return ans;
}
void NTT(int a[],int n,int oper) { // n must be 2^k
	const int g=pow(5,7),gg=pow(g,mod-2),nn=pow(n,mod-2),maxn=1<<20;
	for (int i=1,j=0;i<n;i++) {
		for (int s=n;j^=s>>=1,~j&s;);
		if (i<j) swap(a[i],a[j]);
	}
	for (int m=1,m2=2;m<n;m<<=1,m2<<=1) {
		int w=(oper==1)?g:gg;
		for (int i=m2;i<maxn;i<<=1) w=regular((long long)w*w);
		for (int i=0;i<n;i+=m2) {
			int unit=1;
			for (int j=0;j<m;j++) {
				int &x=a[i+j+m],&y=a[i+j];
				int t=regular((long long)unit*x);
				x=regular(y-t);
				y=regular(y+t);
				unit=regular((long long)unit*w);
			}
		}
	}
	if (oper==-1)
		for (int i=0;i<n;i++) a[i]=regular((long long)a[i]*nn);
}

int dp[30][1001];

void update(int &a,long long b) {
	a=(a+b)%mod;
}
void init() {
	int i,j,k;
	static int tmp[N];
	dp[0][0]=1;
	for (i=1;i<30;i++) {
		for (j=0;j<=1000;j++) tmp[j]=dp[i-1][j];
		for (j=1001;j<N;j++) tmp[j]=0;
		NTT(tmp,N,1);
		for (j=0;j<N;j++) tmp[j]=regular((long long)tmp[j]*tmp[j]);
		for (j=0;j<N;j++) tmp[j]=regular((long long)tmp[j]*tmp[j]);
		NTT(tmp,N,-1);
		for (j=1;j<=1000;j++) dp[i][j]=tmp[j-1];
		dp[i][0]=1;
	}
}
int main() {
	init();
	int t,n,k,p;
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&k);
		p=0;
		while (n!=1&&(n&1)) {
			n>>=1;
			p++;
		}
		printf("%d\n",dp[p][k]);
	}
	return 0;
}
