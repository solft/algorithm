import kotlin.math.hypot
// 7510번 고급 수학
// 풀이:
//      간단한 피타고라스 삼각형 체크 구현 문제
fun main() {
    val t = readLine()!!.toInt()
    for(i in 1 .. t) {
        val side = readLine()!!.split(" ").map { it.toInt() }.toIntArray()
        side.sort()
        println("Scenario #$i:")
        if(side[2].toDouble() == hypot(side[0].toDouble(), side[1].toDouble())) {
            println("yes")
        } else {
            println("no")
        }
        println()
    }
}