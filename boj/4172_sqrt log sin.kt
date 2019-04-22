import kotlin.math.ln
import kotlin.math.sin
import kotlin.math.sqrt

// 4172번 sqrt log sin
// 풀이:
//      단순 재귀식 구현 문제
//      수학 관련 라이브러리를 사용하면 간단하게 풀 수 있다.
//      수가 커지므로 우리에게 필요한 뒷 6자리만 계속 사용하면 된다.
fun main() {
    val x = IntArray(1000001)
    x[0] = 1
    for (i in 1 .. 1000000) {
        x[i] = x[(i- sqrt(i.toDouble())).toInt()] + x[ln(i.toDouble()).toInt()] + x[(i * sin(i.toDouble()) * sin(i.toDouble())).toInt()]
        x[i] %= 1000000
    }

    while(true){
        val index = readLine()!!.toInt()
        if (index == -1)
            break
        println(x[index])
    }
}