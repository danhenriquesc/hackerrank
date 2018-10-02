#include <iostream>
#include <cstdlib>
using namespace std;
typedef long long int llint;
llint final_val,n,max_marks;
llint* marks;
bool cal ( llint st , llint prev , llint val){
	if(st == n ){
		final_val=val;
		return true;
	}
	else{
			if(marks[st-1]>marks[st]){
				for(llint i=1;i<prev;i++){
					if(cal(st+1,i,val+i))
						return true;
				}
				return false;
			}
			else if(marks[st-1]<marks[st]){
				for(llint i=prev+1;i<=max_marks;i++){
					if(cal(st+1,i,val+i))
						return true;
				}
			}
			else{
				for(llint i=1;i<=prev;i++){
					if(cal(st+1,i,val+i))
						return true;
				}
				for(llint i=prev+1;i<=max_marks;i++){
					if(cal(st+1,i,val+i))
						return true;
				}
			}
	}
	return false;
}
int main(){
	cin>>n;
	marks = new llint[n];
	max_marks=-1;
	int decreasing =0 ;
	for(llint i=0;i<n;i++){
		cin>>marks[i];
		if(marks[i]>max_marks)
			max_marks=marks[i];
		if(i>0){
			if(marks[i-1]-marks[i]==1)
				decreasing+=1;
		}
	}
	if(decreasing==n-1){
		llint temp = decreasing+1;
		cout<<(temp/2)*(2+(temp-1))<<endl;
		exit(0);
	}
	for(llint i=1;i<=max_marks;i++){
		if(cal(1,i,i))
			break;
	}
	cout<<final_val<<endl;
	return 0;
}
