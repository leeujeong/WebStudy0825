package A;

import java.util.Scanner;

// 1. 이름(문자열), 나이(정수), 키(실수), 성별(문자)을 입력받아 출력하는 프로그램을 구현하시오.
public class EX_01 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String name = sc.next();
		System.out.println("이름을 입력하세요");
		int age = sc.nextInt();
		System.out.println("나이를 입력하세요");
		double height = sc.nextDouble();
		System.out.println("키를 입력하세요");
		char gender = sc.next().charAt(0);
		// char 입력은 없기 때문에 일단 문자열로 입력받은 뒤(next) 첫 번째 글자만(인덱스 0 위치의 글자: charAt(0)) 추출한다.
		// String 은 char[] 배열이다!
		System.out.println(name + "," + age + "," + height + "," + gender);
		
		sc.close();
		

	}

}
