#include <stdio.h>
//1. 도서정보 저장 구조체
typedef struct book{
    int  bNo;
    char bName[31];
    char author[31];
}Book;

//2. 도서정보 구조체 배열 길이를 매크로 상수이용하여 10 으로 선언
#define LENGTH 10

//3. 매크로 상수 이용해 도서정보 구조체 배열을 전역 변수로 선언하고,
//   배열의 인덱스역시 전역변수로 선언하여 모든함수에서 사용하도록 처리
Book books[LENGTH];
int i;

//4. 메뉴 출력
void menu(){
	printf(":::도서등록 프로그램:::\n");
	printf("1. 도서정보 등록\n");
	printf("2. 도서정보 조회\n");
	printf("3. 전체도서 목록\n");
	printf("0. 프로그램 종료\n");
}

//5. 새로운 도서정보를 입력받아서 도서정보 구조체 배열에 저장하는 함수를 구현
//   새로운 도서정보는 항상 배열의 마지막 요소 다음위치에 저장하고, 배열이 가득찬 경우 저장할수 없다는 적절한 메세지 출력
void addBook(){
    if(LENGTH != i)
	{
        printf("신규 책 번호 입력 >>>");
        scanf("%d", &books[i].bNo);
        
        if(books[i].bNo <= 1000 || books[i].bNo >= 10000) {
        	printf("숫자가 잘못됐습니다. \n");
        	books[i].bNo = 0;
			return;
		}
		      
        printf("신규 책 제목 입력 >>>");
        
        scanf("%s", books[i].bName);
        
        if(sizeof(books[i].bName) > 30) {
        	printf("잘못 됐스비낟.");
        	return;
		}
        printf("신규 책 저자 입력 >>>");
        scanf("%s", books[i].author);
        
        if(sizeof(books[i].author) > 30) {
        	printf("잘못 됐스비낟.");
        	return;
		}
		
		i++;
    }
    else
	{
		printf("배열이 가득찼습니다.");
	}
    
    
}


void queryBook(){
    int num_book;
    printf("조회할 책 번호 입력 >>>");
    scanf("%d",&num_book);
    
    bool status = false;
    for(int i =0; i<LENGTH; i++){
        if(books[i].bNo == num_book){
            printf("조회결과 : %s %s \n", books[i].bName, books[i].author);
            status = true;
        }
    }
    
    if(!status) {
    	printf("없습니다. \n");
	}
}



//7. 모든 도서의 도서번호, 제목, 저자정보를 조회하는 함수구현
void printBook(){
    for(i=0; i<LENGTH;i++){
    	if(books[i].bNo != 0){
        	printf("도서번호 : %d, 제목 : %s, 저자정보 : %s \n", books[i].bNo, books[i].bName, books[i].author);
    	}
    }

}
//8. 지금까지 구현된 모든함수를 호출할수 있는 main 함수구현
int main(){
    int sel;
    while(1){
        menu();
        printf("메뉴선택(1,2,3,0) >>>");
        scanf("%d",&sel);
        switch (sel)
         {
            case 1 : addBook(); break;
            case 2 : queryBook(); break;
            case 3 : printBook(); break;
            case 0 : return 0;
            default: puts("0~3 사이의 메뉴 번호를 선택하세요"); break;
          }
    }