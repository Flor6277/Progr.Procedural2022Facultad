/*Ejemplo de ordenamiento con recursividad*/

void quicksort(int arr[ ], int inf, int sup){
	int t[long];
	int i,piv,m,n;
	
	if (inf < sup) {
		i=(inf+sup)/2;
		piv=arr[i];
		for( i= inf;i<=sup;i++)
			t[i]=arr[i];
			m=inf; n=sup;
			for(i=inf; i<= sup; i++)
				if (t[i] < piv){
					arr[m]=t[i];
					m=m+1;
				}
				else if (t[i] > piv){
						arr[n]=t[i];
						n=n-1;
					}
			for( i=m;i<=n;i++)
				arr[i]=piv;
				quicksort(arr,inf,m-1);
				quicksort(arr,n+1,sup);
	}
	return;
}

int main(){
	int arr[]
	
}
