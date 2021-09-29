package A;

import java.util.Scanner;

//2. 점수와 학년을 입력받아 60점 이상이면 합격, 미만이면 불합격을 출력하시오. 4학년인 경우 70점 이상 이어야 합격이다.
public class EX2 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("점수를 입력하세요(0~100)");
		int score = sc.nextInt();
		System.out.println("학년을 입력하세요(1~4)");
		int grade = sc.nextInt();
		
		if(score >= 60) {
			if(grade !=4) {
			System.out.println("합격");}
			else if(score >= 70) {
				System.out.println("합격");}
			else {
				System.out.println("불합격");
			}
		}else {
			System.out.println("불합격");
		}
		sc.close();
	}

}
