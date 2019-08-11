import java.time.OffsetDateTime;
import java.time.ZoneOffset;

// 16170번 오늘의 날짜는?
// 분류: 날짜
// 문제:
//      현재 UTC+0의 년월일 구하기
// 풀이:
//      java.time.*을 잘 활용하기
public class Main {
    public static void main(String[] args) {
        OffsetDateTime utc = OffsetDateTime.now(ZoneOffset.UTC);
        System.out.println(utc.getYear());
        if(utc.getMonthValue() < 10)
            System.out.println("0" + utc.getMonthValue());
        else
            System.out.println(utc.getMonthValue());
        System.out.println(utc.getDayOfMonth());
    }
}
