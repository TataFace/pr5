#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


void array1(){
	int N;
	printf("enter array size: ");
	scanf("%d", &N);

	int* arr = (int*)malloc(N*sizeof(int));

	printf("\nbegining of array adress%p\n", (void*)arr);

	for (int i = 0; i<N; i++){
		arr[i] = i;
		printf("arr[%d] = %d, adress = %p\n", i, arr[i], (void*)&arr[i]);
	}

	free(arr);

}

void array2(){
	int N, M;
	printf("enter two-dimensional array size N M: ");
	scanf("%d %d", &N, &M);

	int** arr2 = (int**)malloc(N*sizeof(int*));

	for (int i = 0; i<N; i++){
		arr2[i] = (int*)malloc(M*sizeof(int));

	}

	printf("\nbegining of array adress%p\n", (void*)arr2[0][0]);

	for (int i = 0; i<N; i++){
		for (int j = 0; j<M; j++){
			arr2[i][j] = i+j;
			printf("%d(%p) ", arr2[i][j], (void*)&arr2[i][j]);

		}
		printf("\n");
	}
	for (int i = 0; i<N; i++) free(arr2[i]);
	free(arr2);

}


bool is_composite(int n){
	if (n<= 3) return false;
	for (int i = 2; i<=n/2;i++){
		if (n%i==0) return true;
	}
	return false;
}

void comp_and_max(int arr[], int size, int *count, int *max){
	*count = 0;
	*max = -1000;

	for(int i=0; i<size; i++){
		if(is_composite(arr[i])){
			(*count)++;
			if(arr[i]>*max){
				*max = arr[i];
			}
		}
	}

	if(*count == 0) *max=-1;
}






int main(){
	printf("one-dimensional array\n");
	array1();

	printf("two-dimensional array\n");
	array2();

	printf("\nfind composite count and max of them\n");


	int arr[] = {1, 2, 4, 6, 7, 8, 9, 11, 15};
	int size = sizeof(arr)/sizeof(arr[0]);

	int comp_count, max_comp;


	comp_and_max(arr, size, &comp_count, &max_comp);
	printf("composite count: %d\n", comp_count);
	printf("max composite number: %d\n", max_comp);


	return 0;
	
}
