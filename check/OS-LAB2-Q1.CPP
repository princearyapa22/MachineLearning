#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

struct cmp
{
	bool operator() ( pii a, pii b)
	{
		return a.second < b.second;
	}
};

int main()
{
	int n; cin>>n;
	vector<int> at(n), bt(n),pr(n), ct(n), wt(n), tat(n);
	for(int i=0; i<n; i++)
		cin>>pr[i]>>at[i]>>bt[i];
	
	vector<int> btt=	bt;
	vector<bool> vis(n, false);
	priority_queue< pii, vector<pii>, cmp > pq;
	
	int mini=INT_MAX;
	for(int i=0; i<n; i++)
		mini=min(mini, at[i]);
	for(int i=0; i<n; i++)
		if(mini==at[i])
			{
			pq.push(make_pair(i, pr[i]));
			vis[i]=1;
			}
			
	int st=0;
	int comp=0;
while(comp!=n)
	{
		for(int i=0; i<n; i++)
			if(!vis[i])
				if(st >= at[i])
					{
						pq.push({i, pr[i]});
						vis[i]=1;
					}
		st++;
		if(pq.empty())
			continue;
		else{
			int a=pq.top().first;			
			bt[a]=bt[a]-1;
			
			if(bt[a]==0)
			{
				pq.pop();
				ct[a]=st;
				tat[a]=ct[a]-at[a];
				wt[a]=tat[a]-btt[a];
				comp++;
			}
		}
		
	}
	cout<<left<<setw(6)<<setfill(' ')<<"P.NO";
	cout<<left<<setw(8)<<setfill(' ')<<"PRIORIY";
    cout<<left<<setw(6)<<setfill(' ')<<"AT";
    cout<<left<<setw(6)<<setfill(' ')<<"BT";
    cout<<left<<setw(6)<<setfill(' ')<<"CT";
    cout<<left<<setw(6)<<setfill(' ')<<"TAT";
    cout<<left<<setw(6)<<setfill(' ')<<"WT";
    cout<<endl;
	for(int i=0; i<n; i++)
     {
         // cout<<left<<setw(6)<<setfill(' ')<<id[i];
         cout<<left<<setw(6)<<setfill(' ')<<i+1;
         cout<<left<<setw(8)<<setfill(' ')<<pr[i];
         cout<<left<<setw(6)<<setfill(' ')<<at[i];
         cout<<left<<setw(6)<<setfill(' ')<<btt[i];
         cout<<left<<setw(6)<<setfill(' ')<<ct[i];
         cout<<left<<setw(6)<<setfill(' ')<<tat[i];
         cout<<left<<setw(6)<<setfill(' ')<<wt[i];
         cout<<endl;
     }
     double avgtat=0, avgwt=0;
     int stat=0, swt=0;
     for(int i=0; i<n; i++){
     	stat+=tat[i];
     	swt+=wt[i];
     }
     avgtat= 1.0*stat/n;
     avgwt= 1.0*swt/n;
     
          cout<<"\n\n Average turn arougn time : "<<avgtat<<endl;
     cout<<"     Average wait time    : "<<avgwt<<endl;
	cout<<"       Throughput         : "<<1.0*n/(*max_element(ct.begin(), ct.end()));
}