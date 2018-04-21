#include<map>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],p[100005],b[100008],k,tot,head;
int ans;
void init(){
	b[1]=1;
	for(register int i=2;i<=3000;i++){
		if(b[i]==0)++tot,p[tot]=i;
		for(register int j=1;j<=tot;j++){
			if(i*p[j]>3000)break;b[i*p[j]]=1;
		}
	}
}
map<int,int>rt;
int main(){
	rt.clear();
	freopen("pf.out","w",stdout);
	init();
	int n=1009;
	for(register int i=1;i<=n;i++){
		cout<<i<<" "<<b[i];int tmp=0;
		for(register int j=1;j*j<=i;j++){
			if(i%j==0&&i!=j)tmp+=a[j],tmp+=a[i/j];
		}
		if(b[i]==0)a[i]=1-tmp;
		else a[i]=0-tmp;
		cout<<" "<<a[i]<<endl;
		rt[a[i]]++;
	}
	for(register int i=1;i<=n;i++)if(b[i]==0)++k;cout<<k<<endl;
	long long et=0;
	for(map<int,int>::iterator it=rt.begin();it!=rt.end();it++){
		cout<<it->first<<' '<<it->second<<" "<<"ls et£º"<<et<<endl;
		et+=it->first*it->second;
	}
	cout<<et<<endl<<endl;
	rt.clear();k=0;memset(a,0,sizeof(a));
	for(register int i=1;i<=n;i++){
		//cout<<i<<" "<<b[i];
		int tmp=0;
		for(register int j=1;j*j<=i;j++){
			if(i%j==0&&i!=j)tmp+=a[j],tmp+=a[i/j];
		}
		if(b[i]==0)a[i]=-tmp;
		else a[i]=1-tmp;
		//cout<<" "<<a[i]<<endl;
		rt[a[i]]++;
	}
	for(register int i=1;i<=n;i++)if(b[i]==0)++k;cout<<k<<endl;
	et=0;
	for(map<int,int>::iterator it=rt.begin();it!=rt.end();it++){
		cout<<it->first<<' '<<it->second<<" "<<"ls et£º"<<et<<endl;
		et+=abs(it->first)*it->second;
	}
	cout<<et<<endl;
	return 0;
}
