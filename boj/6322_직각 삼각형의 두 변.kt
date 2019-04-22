import kotlin.math.hypot
import kotlin.math.sqrt

// 6322번 직각삼각형의 두변
// 문제:
//      3변의 길이가 순서대로 주어졌을 때
//      직각삼각형을 만들수 있는지 있으면 안 주어진 한 변의 길이는?
// 풀이:
//      단순 구현 문제
// 사용한 코틀린 문법:
//      hypot(x, y) = sqrt(x^2 + y^2) 직각삼각형 x, y 의 빗변 길이 구하는 함수
//      println("%.숫자f".format(더블형)) 소수점 `숫자` 자리만큼 표현하기
fun main() {
    var index = 1
    while(true){
        val t = readLine()!!.split(" ").map { it.toInt() }
        if(t[0] == 0 && t[1] == 0 && t[2] == 0)
            break
        // t[0] = a, t[1] = b / t[2] = c = 빗변
        when {
            t[0] == -1 -> {
                println("Triangle #$index")
                val temp = t[2]*t[2] - t[1]*t[1]
                if(temp <= 0)
                    println("Impossible.")
                else
                    println("a = %.3f".format(sqrt(temp.toDouble())))
                println()
            }
            t[1] == -1 -> {
                println("Triangle #$index")
                val temp = t[2]*t[2] - t[0]*t[0]
                if(temp <= 0)
                    println("Impossible.")
                else
                    println("b = %.3f".format(sqrt(temp.toDouble())))
                println()
            }
            t[2] == -1 -> {
                println("Triangle #$index")
                println("c = %.3f".format(hypot(t[0].toDouble(), t[1].toDouble())))
                println()
            }
        }
        index++
    }
}