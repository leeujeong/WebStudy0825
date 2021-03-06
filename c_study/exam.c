#include <stdio.h>

//1. 학생 정보를 저장할 구조체 작성
typedef struct _Student{
    char name[31];
    int kor, eng, math;
    int sum;
    double avg;
} Student;

//2. 학생정보 구조체 배열의 길이를 매크로 상수를 이용하여 3으로 선언
#define LENGTH 3

//3. 매크로 상수를 이용해 도서정보 구조체 배열을 전역변수로 선언하여 모든 함수에서 사용할 수 있도록 처리
Student students[LENGTH];

//4. 새로운 학생정보를 입력받아서 학생정보 구조체 배열에 저장하는 함수구현
//  이름은 공백입력 가능하도록 처리, 국어 영어 수학 점수만 입력하면 총점과 평균은 자동으로 계산된뒤 저장되도록 처리
void inputinfomation(){
	printf("학생 %d명의 정보를 차례대로 입력하세요\n \n", LENGTH);
    for(int i = 0; i < LENGTH; i++){
    	fflush(stdin);
		printf("학생 %d 이름 >>>", i+1); 
		gets(students[i].name);
		printf("국어 >>>");
		scanf("%d", &students[i].kor);
		printf("영어 >>>");
		scanf("%d", &students[i].eng);
		printf("수학 >>>");
		scanf("%d", &students[i].math);
		students[i].sum = students[i].kor + students[i].eng + students[i].math;
		students[i].avg = students[i].sum / 3;
   	}
}


//5. 학생정보구조체 배열에 저장된 모든 학생정보를 파일에 저장하는함수를 구현하시어
//  파일명은 score.csv , "이름, 국어, 영어, 수학, 총점, 평균" 과 같은 형식으로 저장
void generateFile(){
    FILE * f = fopen("score.csv","w");
    if(f == NULL) {
        fprintf(stderr, "file open error\n");
        return;
    }
    
	fprintf(
		f,
		"성명,국어,영어,수학,총점,평균\n"
	);
    
    for(int i = 0; i < LENGTH; i++){
    	fprintf(
			f,
			"%s,%d,%d,%d,%d,%.2lf \n",
			students[i].name,
			students[i].kor,
			students[i].eng,
			students[i].math,
			students[i].sum,
			students[i].avg
		);
    }
    fclose(f);
    printf("score.csv 파일이 생성되었습니다.");
}
//6.지금까지 구현된 모든 함수를 호출할수 있는 main 함수를 구현
//  학생정보입력 후 파일저장이 되도록 호출 순서를 결정하시오
int main(){
    inputinfomation();
    generateFile();
}