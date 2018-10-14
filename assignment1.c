#include <stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
	int f,v1=0,v2=0,v3=0,v4=0,v5=0,v6=0,v7=0,v8=0,v9=0,v10=0,sum=0;
	int a1[2],a2[2],a3[2],a4[2],a5[2],a6[2],a7[2],a8[2],a9[2],a10[2];
	int array[1000];
	pipe(a1);
 	pipe(a2);
 	pipe(a3);
 	pipe(a4);
 	pipe(a5);
 	pipe(a6);
	pipe(a7);
	pipe(a8);
	pipe(a9);
	pipe(a10);
	for(int i=0;i<1000;i++){
		array[i]=i;
	}
	int c1=fork();
	if (c1==0){
		for(int i=0;i<100;i++){
			v1+=array[i];
		}
		write(a1[1],&v1,sizeof(v1));
		close(a1[1]);
		exit(0);
	}
	else{
		int c2=fork();
		if (c2==0){
			for(int i=100;i<200;i++){
				v2+=array[i];
			}
			write(a2[1],&v2,sizeof(v2));
			close(a2[1]);
			exit(0);
		}
		else{
			int c3=fork();
			if (c3==0){
				for(int i=200;i<300;i++){
					v3+=array[i];
				}
				write(a3[1],&v3,sizeof(v3));
				close(a3[1]);
				exit(0);
			}
			else{
				int c4=fork();
				if (c4==0){
					for(int i=300;i<400;i++){
						v4+=array[i];
					}
					write(a4[1],&v4,sizeof(v4));
					close(a4[1]);
					exit(0);
				}
				else{
					int c5=fork();
					if (c5==0){
						for(int i=400;i<500;i++){
							v5+=array[i];
						}	
						write(a5[1],&v5,sizeof(v5));
						close(a5[1]);
						exit(0);
					}
					else{
						int c6=fork();
						if (c6==0){
							for(int i=500;i<600;i++){
								v6+=array[i];
							}
							write(a6[1],&v6,sizeof(v6));
							close(a6[1]);
							exit(0);
						}
						else{
							int c7=fork();
							if (c7==0){
								for(int i=600;i<700;i++){
									v7+=array[i];
								}
								write(a7[1],&v7,sizeof(v7));
								close(a7[1]);
								exit(0);
							}
							else{
								int c8=fork();
								if (c8==0){
									for(int i=700;i<800;i++){
										v8+=array[i];
									}
									write(a8[1],&v8,sizeof(v8));
									close(a8[1]);
									exit(0);
								}
								else{
									int c9=fork();
									if (c9==0){
										for(int i=800;i<900;i++){
											v9+=array[i];
										}
										write(a9[1],&v9,sizeof(v9));
										close(a9[1]);
										exit(0);
									}
									else{
										for(int i=900;i<1000;i++){
											v10+=array[i];
										}
										write(a10[1],&v10,sizeof(v10));
										close(a10[1]);
										wait(NULL);
									}
									wait(NULL);
								}
								wait(NULL);
							}
							wait(NULL);
						}
						wait(NULL);
					}
					wait(NULL);
				}
				wait(NULL);
			}
			wait(NULL);
		}
		wait(NULL);
	}
	read(a1[0],&v1,sizeof(int));
	read(a2[0],&v2,sizeof(int));
	read(a3[0],&v3,sizeof(int));
	read(a4[0],&v4,sizeof(int));
	read(a5[0],&v5,sizeof(int));
	read(a6[0],&v6,sizeof(int));
	read(a7[0],&v7,sizeof(int));
	read(a8[0],&v8,sizeof(int));
	read(a9[0],&v9,sizeof(int));
	read(a10[0],&v10,sizeof(int));
	sum+=(v1+v2+v3+v4+v5+v6+v7+v8+v9+v10);
	printf("Sum = %d",sum);
	return 0;
}
