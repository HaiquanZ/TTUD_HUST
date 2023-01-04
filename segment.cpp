#include <stdio.h>
#define N 100001
int a[N],n,b[N];
void swap(int  *a,int  *b){
	int t=*a;
	*a=*b;
	*b=t;
}
void quicksort(int low,int high){
	if (low>=high) return;
	else{
		int pivot,right,left;
		pivot=b[high];
		left=low;
		right=high-1;
		while (1){
			while (b[left]<pivot && left<=right) left++;
			while  (b[right]>pivot && left<=right) right--;
			if  (left>=right) break;
			swap(&b[left],&b[right]);
			swap(&a[left],&a[right]);
			left++;
			right--;
		}
		swap(&b[left],&b[high]);
		swap(&a[left],&a[high]);
		quicksort(low,left-1);
		quicksort(left+1,high);
	}
}
int  main(){
	int ans,end;
	ans=1;
	scanf("%d",&n);
	for  (int i=1;i<=n;i++)
		scanf("%d%d",&a[i],&b[i]);
	quicksort(1,n);
	end=b[1];
	for (int i=2;i<=n;i++){
		if  (a[i]>end) {
			ans++;
			end=b[i];
		}
	}
	printf("%d",ans);
	return 0;
}
