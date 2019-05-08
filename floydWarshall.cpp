#include<bits/stdc++.h>
#include<fstream>
using namespace std;
map<string,vector<pair<string,double> > >graph;

map<string,vector<pair<string,double> > >::iterator iter;

vector<pair<string,double> >::iterator checker;

set<string> number_nodes;
set<string>::iterator itr;
double **dp;
double **dist;
int **parent;
int drive=1;

map<int,string> mp;
map<string,int> mp1;
//vector<pair<int,bool> >index;
vector<int> index;
double mini=INT_MAX;
int indexer;
int k=0;
//FUNCTIONS
unsigned int factorial(unsigned int n)
{
    if (n == 0)
    return 1;
    return n * factorial(n - 1);
}




void printArr(int arr[][12],int x,vector<int> a,int n)
{
	for (int i=0; i<n; i++)
    {
        arr[k][i]=a[i];
    }
    k++;

}




void heapPermutation(int arr[][12],int x,vector<int> a, int size, int n)
{

	if (size == 1)
	{
		printArr(arr,x,a, n);
		return;
	}

	for (int i=0; i<size; i++)
	{
		heapPermutation(arr,x,a,size-1,n);


		if (size%2==1)
			swap(a[0], a[size-1]);


		else
			swap(a[i], a[size-1]);
	}
}





int totaltime()
{
    int har=(int)2*mini;
    return har;
}




void printpath(int index,int driverno)
{

    cout<<"Driver-"<<driverno<<" ------>Resturant------>"<<mp.find(index)->second;

}



void printpather(int index)
{

    cout<<"------>"<<mp.find(index)->second;

}



void details(int i,string line)
{
    if(i==1)
    {
        cout<<"Flat number-171, Narmada apartment, "<<line<<" , Noida , U.P"<<endl<<endl;
    }
    if(i==2)
    {
        cout<<"Flat number-432, Achlon apartment, "<<line<<" , Noida , U.P"<<endl<<endl;
    }
    if(i==3)
    {
        cout<<"Flat number-124, Kalpana apartment, "<<line<<" , Noida , U.P"<<endl<<endl;
    }
    if(i==4)
    {
        cout<<"Flat number-1710, Gaursons apartment, "<<line<<" , Noida , U.P"<<endl<<endl;
    }
    if(i==5)
    {
        cout<<"Flat number-1619, Lodha apartment, "<<line<<" , Noida , U.P"<<endl<<endl;
    }

}




void matrix_of_permute(int matrix[][12],int x,int s,int y){
int i,j;
mini=INT_MAX;
for(i=0;i<x;i++){
  //calc(matrix[i][],i,y);
double distance=dist[0][matrix[i][s]];
for(j=s;j<y-1;j++){
    distance+=dist[matrix[i][j]][matrix[i][j+1]];
}
if(distance<mini)
  {
    mini=distance;
    indexer=i;
  }

}

int ttime=totaltime();

if(ttime<=40)
{
    cout<<"\nYour order will take "<<ttime<<" minutes"<<endl<<endl;
    int cnt=0;
for(i=s;i<y;i++)
{
    if(cnt==0){
        printpath(matrix[indexer][i],drive++);
        cnt++;
    }
    else{
        printpather(matrix[indexer][i]);
    }
}
}
else
{

   int half=y/2;
   matrix_of_permute(matrix,x,0,half);
   matrix_of_permute(matrix,x,half,y);



}
cout<<endl<<endl;
}





void finder(vector<pair<string,double> >::iterator st,vector<pair<string,double> >::iterator en,string ch){

for(checker=st;checker!=en;checker++){
    if(checker->first==ch)
        return;
}
return;
}



 void creatingmatrix(){


 dp=new double*[graph.size()];
 int i,j;
for(iter=graph.begin(),i=0;iter!=graph.end(),i<graph.size();iter++,i++){
    dp[i]=new double[graph.size()];
    j=0;
    for(itr=number_nodes.begin();itr!=number_nodes.end();itr++){

     //FINDS IF THERE IS A PATH FROM A NODE TO ANOTHER AND ASSIGNS VALUE ACCORDINGLY
       finder(iter->second.begin(),iter->second.end(),*itr);
        if(checker==iter->second.end()&& *itr!=iter->first){
            dp[i][j]=INT_MAX;
        }
        else{
            if(*itr==iter->first){
                dp[i][j]=0;
            }
            else
                dp[i][j]=checker->second;
        }
    j+=1;
    }
}


}


void floydWarshall (int V)
{

	int i, j, k;


   dist=new double*[V];
   parent=new int*[V];
   for (i = 0; i < V; i++){
		dist[i]=new double[V];
		for (j = 0; j < V; j++)
			dist[i][j] = dp[i][j];
	}

	for (i = 0; i < V; i++)
	{ parent[i]=new int[V];
	    for (j = 0; j < V; j++)
	    {
	        if(i==j || dp[i][j]==INT_MAX)
	        {
	            parent[i][j]=-1;
	        }
	        else
	        {
	            parent[i][j]=i;
	        }
	    }
	}



	for (k = 0; k < V; k++)
	{

		for (i = 0; i < V; i++)
		{

			for (j = 0; j < V; j++)
			{

				if (dist[i][k] + dist[k][j] < dist[i][j])
				{
				    dist[i][j] = dist[i][k] + dist[k][j];
				    parent[i][j] = parent[k][j];
				}

			}
		}
	}




}





int main(){
int c,w,i;
char u,v;
ifstream fin;

fin.open("distance.txt");
string line;

vector<string> str;
while(fin){

    fin>>line;

    str.push_back(line);
    if(str.size()==3){

        number_nodes.insert(str[0]);
    number_nodes.insert(str[1]);

    graph[str[0]].push_back(make_pair(str[1],atof(str[2].c_str())));
    str.clear();
    }
}
fin.close();

for(i=0,itr=number_nodes.begin();i<graph.size(),itr!=number_nodes.end();i++,itr++)
    {
         cout<<*itr<<" ";
         mp[i]=*itr;
         mp1[*itr]=i;
    }


cout<<endl<<endl;
for(itr=number_nodes.begin();itr!=number_nodes.end();itr++){
    if(graph.find(*itr)==graph.end()){
        graph[*itr].push_back(make_pair("1",1));
    }
}
   creatingmatrix();

   int V=graph.size();

   floydWarshall(V);



   fin.open("order.txt");

   i=0;
   int number;
   while(fin){
    fin>>line;
    //cout<<line<<endl;
    if(i==0){
        //stringstream ss(line);
        //ss<<i;
    i=atoi(line.c_str());
    number=i;
    cout<<endl;
    cout<<"Number of orders are:"<<i<<endl<<endl;
    }
    else{
            cout<<"Your order number 128"<<number-i+1<<" is from : ";
            details(i,line);

            index.push_back(mp1.find(line)->second);
            i-=1;

    if(i==0){

        int x=factorial(index.size());
         int matrix[x][12];
         heapPermutation(matrix,x,index,index.size(),index.size());
         matrix_of_permute(matrix,x,0,index.size());
         index.clear();
         k=0;
         mini=INT_MAX;
         cout<<endl;
         cout<<"----------------------------------------------------------"<<endl;
         cout<<"enter 1 to continue and 0 to exit"<<endl;
         int ex;
         cin>>ex;
         if(ex==0)
         {
             break;
         }

    }

    }

}
fin.close();


}
