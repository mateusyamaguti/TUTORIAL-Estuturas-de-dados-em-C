#include <stdio.h> 
 
int compcres(int const *a, int const *b) {
    return *a - *b;      // permite classificar ascendente
}

int compdecr(int const *a, int const *b) {
    return *b - *a;      // permite classificar ascendente
}

int main(){
	int i, indp, indi, qde, par[100000], imp[100000];
	scanf("%d", &qde);
	for(i=0, indp=-1, indi=-1; i<qde; i++){
		scanf("%d", &par[++indp]);
		if(par[indp]%2 == 1){
			imp[++indi]= par[indp];
			indp--;
		}
	}

	qsort(par, indp+1, sizeof(int), compcres);
	
	qsort(imp, indi+1, sizeof(int), compdecr);
	
	for(i=0; i<=indp; i++) 
		printf("%d\n", par[i]);
		
	for(i=indi; i>=0; i--) 
		printf("%d\n", imp[i]);

    return 0;
}
