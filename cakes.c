#include <stdio.h>
#include <stdlib.h>

void gemisma(int alevri[],double wres_zax[][2],int cake);
void display(int alevri[],double wres_zax[][2],int cake);
void mo_alevri(int alevri[],int cake);
void mo_zaxaris(double wres_zax[][2], int cake);
void mo_wrwn_alevri_panw_apo_300(int alevri[],double wres_zax[][2],int cake);
void max_alevri(int alevri[],double wres_zax[][2],int cake);
void max_zaxari(int alevri[],double wres_zax[][2],int cake);
void sorting_zaxari_asc(int alevri[],double wres_zax[][2],int cake);

int main() {
	int cake;
	printf("Posa cake efages?\n");
	scanf("%i",&cake);
	double wres_zax[cake][2];
	int alevri[cake];
	
	gemisma(alevri,wres_zax,cake);
	display(alevri,wres_zax,cake);
	mo_alevri(alevri,cake);
	mo_zaxaris(wres_zax,cake);
	mo_wrwn_alevri_panw_apo_300(alevri,wres_zax,cake);
	max_alevri(alevri,wres_zax,cake);
	max_zaxari(alevri,wres_zax,cake);
	sorting_zaxari_asc(alevri,wres_zax,cake);
	display(alevri,wres_zax,cake);
	
	return 0;
}

void gemisma(int alevri[],double wres_zax[][2],int cake){
	printf("\n");
	int i;
	double wres,zaxari;
	int alevri1;
	for (i=0; i<cake; i++){
		printf("Poses wres psithike to %iï cake?\n",i+1);
		scanf("%lf",&wres);
		wres_zax[i][0]=wres;
		printf("Posi zaxari evales sto %iï cake?\n",i+1);
		scanf("%lf",&zaxari);
		wres_zax[i][1]=zaxari;
		printf("Poso alevri xrisimopiises sto %iï cake?\n",i+1);
		scanf("%i",&alevri1);
		alevri[i]=alevri1;	
	}
	printf("\n");
}

//display -> 1. 3.5h, 500z, 300a
void display(int alevri[],double wres_zax[][2],int cake){
	printf("\n");
	int i;
	for (i=0; i<cake; i++){
		printf("%i. %.1fh, %.2fgr, %igr\n",i+1,wres_zax[i][0],wres_zax[i][1],alevri[i]);
	}
	printf("\n");
}

void mo_alevri(int alevri[],int cake){
	int i;
	int sum=0;
	double mo;
	for (i=0; i<cake; i++){
		sum=sum+alevri[i];
	}
	if (cake==0){
		mo=0;
	}
	else {
		mo=(double)sum/cake;
	}
	printf("O mo gia to alevri einai %.3f\n",mo);
}

void mo_zaxaris(double wres_zax[][2], int cake){
	int i;
	double sum=0;
	double mo;
	for (i=0; i<cake; i++){
		sum=sum+wres_zax[i][1];
	}
	mo=sum/cake;
	printf("O mo gia thn zaxari einai %.3f\n",mo);	
}

void mo_wrwn_alevri_panw_apo_300(int alevri[],double wres_zax[][2],int cake){
	int i;
	double sum=0;
	double mo;
	int count=0;
	for (i=0; i<cake; i++){
		if (alevri[i]>300){
			count++;
			sum=sum+wres_zax[i][0];
		}
	}
	if (count==0){
		mo=0;
	}
	else {
		mo=sum/count;
	}
	printf("O mo gia tis wres gia ta cake me alevri panw apo 300gr einai %.2f\n",mo);
}

void max_alevri(int alevri[],double wres_zax[][2],int cake){
	int i;
	int maxi=alevri[0];
	int pos=0;
	for (i=0; i<cake; i++){
		if (alevri[i]>maxi){
			maxi=alevri[i];
			pos=i;
		}
	}
	printf("To megisto alevri einai %i, to exei to %io cake. Psithike %.1f wres kai exei %.2f gr zaxaris\n",maxi,pos+1,wres_zax[pos][0],wres_zax[pos][1]);
}

void max_zaxari(int alevri[],double wres_zax[][2],int cake){
	int i;
	int maxi=wres_zax[0][1];
	int pos=0;
	for (i=0; i<cake; i++){
		if (wres_zax[i][1]>maxi){
			maxi=wres_zax[i][1];
			pos=i;
		}
	}
	printf("H megisti zaxari einai %.2f kai tin exei to %i cake\n",maxi,pos+1);
	printf("To alevri gia to %i cake einai %.1f kai psithike se %.1f wres\n",pos+1,alevri[pos],wres_zax[pos][0]);
}

void sorting_zaxari_asc(int alevri[],double wres_zax[][2],int cake){
	int i,j;
	double temp;
	int temp1;
	for (i=0; i<cake-1; i++){
		for (j=0; j<cake-i-1; j++){
			if (wres_zax[j][1]>wres_zax[j+1][1]){
				//swap zax
				temp=wres_zax[j][1];
				wres_zax[j][1]=wres_zax[j+1][1];
				wres_zax[j+1][1]=temp;
				//swap wres
				temp=wres_zax[j][0];
				wres_zax[j][0]=wres_zax[j+1][0];
				wres_zax[j+1][0]=temp;
				//swap alevri
				temp1=alevri[j];
				alevri[j]=alevri[j+1];
				alevri[j+1]=temp1;
			}
		}
	}
}
	
