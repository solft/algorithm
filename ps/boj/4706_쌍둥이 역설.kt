import java.lang.Math.pow
import kotlin.math.sqrt

// 4706번 쌍둥이 역설
// 분류: 구현, 수학
// 문제:
//      계산식 구현해서 값찾기
// 풀이:
//      문제에 주어진 조건대로 구하면 된다.
fun main() {
    while(true){
        val num = readLine()!!.split(" ").map { it.toDouble() }
        if(num[0] == 0.0 && num[1] == 0.0)
            break

        println("%.3f".format(sqrt(1-pow(num[1], 2.0)/pow(num[0], 2.0))))
    }
}
