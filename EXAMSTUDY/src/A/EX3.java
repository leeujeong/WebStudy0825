package A;

import java.util.Scanner;

//3. 커피 메뉴를 입력받아 가격을 알려주는 프로그램을 구현하시오. switch 문을 이용하여 구현하시오.
//(에스프레소, 카푸치노, 카페라떼는 3500원, 아메리카노는 2000원이다.)
public class EX3 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String order = sc.next();
		int price =0;
		switch(order) {
		case  "에스프레소";
		case  "카푸치노";
		case  "카페라떼";
			price = 3000;
			break;
		case  "아메리카노";
		price = 2000;
			break;
		default : System.out.println("메뉴에 없습니다.");
		}
		if(price != 0) {
			System.out.println(order + "는" + price + "원입니다.");
		sc.close();
		}
	}

}
